#include "static_list.h"

int main()
{
    char a[6] = {'1', '2', '3', '4', '5', '6'};
    char ch;
    StaticLinkList<char> s1(a,6);
    std::cout<<"当前链表各元素依次为：\n";
    s1.print();
    std::cout<<"向第1个位置插入+后：\n";
    s1.Insert(1, '+');
    s1.print();
    std::cout<<"元素4所在下标为："<<s1.Locate('4')<<std::endl;
    s1.GetValue(3, ch);
    std::cout<<"下标为3的元素是："<<ch<<std::endl;
    std::cout<<"向第8个位置插入z后：\n";
    s1.Insert(8, 'z');
    s1.print();
    s1.Delete(7, ch);
    std::cout<<"被删除的第7个元素是："<<ch<<std::endl;
    std::cout<<"当前链表各元素依次为：\n";
    s1.print();
    s1.Delete(1, ch);
    std::cout<<"被删除的第1个元素是："<<ch<<std::endl;
    std::cout<<"当前链表各元素依次为：\n";
    s1.print();
    s1.Insert(12, 'd');
    s1.Delete(12, ch);
    s1.print();
    return 0;
}


/// 2018.1.31~2.1
