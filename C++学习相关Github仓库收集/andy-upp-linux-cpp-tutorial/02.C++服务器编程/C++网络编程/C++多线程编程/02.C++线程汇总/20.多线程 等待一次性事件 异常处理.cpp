//https://www.cnblogs.com/xiaoshiwang/p/10023543.html

#include <iostream>
#include <string>
#include <future>

class A{
  int data;
public:
  A(int d = 10) : data(d){}
  int _data() const {return data;}
};
double div1(double a, double b){
  if(b == 0){
    //throw std::string("error");//进入string的catch
    //throw "error";//进入const char*的catch
    //throw 1;//进入int的catch
    throw A(101);//进入A a的catch
    
  }
  return a / b;
}

double div2(std::promise<double>& pro, double a, double b){
    int x;
    std::cin.exceptions (std::ios::failbit);   //如果不加这句，std::cin >> x这里，即使给的不是数字，也不会发生异常。
    try{
      std::cin >> x;//输入一个字母，就会引发异常
    }catch(std::exception&){
      pro.set_exception(std::current_exception());
    }

}
int main(){
  try{

    //std::asnyc 执行这段时，把后面的std::package_task和std::promise注释掉
    std::future<double> f = std::async(div1, 10, 0);
    std::cout << f.get() << std::endl;//get如果发生了异常，则进入catch

    //std::package_task 执行这段时，把std::asnyc和td::promise注释掉
    std::packaged_task<double(double, double)> t(div1);
    std::future<double> f2 = t.get_future();
    std::thread thread1(std::ref(t), 100, 0);
    thread1.detach();
    f2.get();//get如果发生了异常，则进入catch

    //std::promise 执行这段时，把上面的std::asnyc和td::package_task注释掉
    std::promise<double> pro;
    std::future<double> f3 = pro.get_future();
    std::thread thread2(div2, std::ref(pro), 100, 0);
    thread2.join();
    f3.get();////get如果发生了异常，则进入catch(...)部分
    
  }
  catch(A a){
    std::cout << "err:A a" << std::endl;
    std::cout << a._data() << std::endl;
  }
  catch(int a){
    std::cout << "err:int" << std::endl;
    std::cout << a << std::endl;
  }
  catch(const char* s){
    std::cout << "err:char*" << std::endl;
    std::cout << s << std::endl;
  }
  catch(std::string s){
    std::cout << "err:string" << std::endl;
    std::cout << s << std::endl;
  }
  catch(...){
    using namespace std;
    cout << "...." << endl;
    
  }
}