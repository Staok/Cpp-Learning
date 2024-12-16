#include <forward_list>
#include <iostream>


//std::forward_list为c++新增的线性表，与list区别在于它是单向链表。
//我们在学习数据结构的时候都知道，链表在对数据进行插入和删除是比顺序存储的线性表有优势，
//因此在插入和删除操作频繁的应用场景中，使用list和forward_list
//比使用array、vector和deque效率要高很多。


int main()
{
    std::forward_list<int> numbers = {1,2,3,4,5,4,4};
    std::cout << "numbers:" << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }
    numbers.remove(4);
    std::cout << "numbers after remove:" << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }
    return 0;
}
