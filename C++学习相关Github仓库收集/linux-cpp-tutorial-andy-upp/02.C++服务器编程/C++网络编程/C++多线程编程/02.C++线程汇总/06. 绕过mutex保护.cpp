/*
mutex，能够解决线程安全的问题，但它不是万能的。
下面的例子虽然使用了mutex，但是恶意注入了一个外部函数，
导致把被mutex保护的双向链表，让一个外部的指针指向了，
结果就可以通过这个外部的指针操作被保护的双向链表，也就绕过了metex的保护。
*/

#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <thread>
#include <unistd.h>


using namespace std;

//是线程安全的
class data_protect{
public:
  list<int> alist{1,2};
  mutex m;
public:  
  void add_list(int val){
    //操作双向链表时，加锁了
    lock_guard<mutex> g(m);
    alist.push_back(val);
  }

  bool contains(int val){
    //操作双向链表时，加锁了
    lock_guard<mutex> g(m);
    return find(alist.begin(), alist.end(), val) != alist.end();
  }

  //参数接受一个外来的函数，并把双向链表传递给了外来的函数
  template<typename Function>
  void do_data(Function func){
    lock_guard<mutex> g(m);
    func(alist);
  }
};

list<int>* unprotect_list;
//外来的函数接收到了双向链表的引用，并把这个双向链表暴露给外面的非保护的双向链表的指针
void bad_func(list<int>& alist){
  unprotect_list = &alist;
}

void gl(data_protect& dp){
  dp.do_data(bad_func);
  //这个插入操作没有加锁，所以不是线程安全的
  unprotect_list->push_back(99);
}

int main(){
  data_protect dp;
  gl(dp);

  //alist被改变了
  for(auto& s : dp.alist){
    cout << s << endl;
  }
}

/*
为了避免上面的情况，最好遵守下面的准则：
不要将受保护的数据的指针或者引用传递到锁的范围之外，
无论是通过函数返回它们，还是作为参数传递给用户提供的函数。
*/