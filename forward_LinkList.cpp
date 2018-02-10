#include "forward_LinkList.h"

int main()
{
    double a[5] = {1.3, 2.5, 3, 4, 5};
    LinkList<char> s1();
    LinkList<double> s2(a, 5);
    std::cout<<"原链表元素依次为：";
    s2.print();
    double b;
    s2.GetValue(5, b);
    std::cout<<"第五个元素是:"<<b<<std::endl;
    s2.Delete(2, b);
    std::cout<<"被删除的第二个元素为："<<b<<std::endl;
    std::cout<<"此时链表长度为："<<s2.GetLength()<<std::endl;
    s2.Insert(2, 77);
    std::cout<<"插入后元素依次为：";
    s2.print();
    std::cout<<"元素4所在下标为："<<s2.Locate(4)<<std::endl;
    std::cout<<"第二个元素被赋值为9后链表为：\n";
    s2.SetValue(2, 9);
    s2.print();
    return 0;
}



///2018.1.30    丁宇飞

