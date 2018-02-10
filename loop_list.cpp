#include "loop_list.h"

int main()
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int b[5] = {0, 9 , 8, 7, 666};
    CLinkList<int> circle(a, 7);
    std::cout<<"原循环链表为：";
    circle.print();
    int temp;
    circle.Delete(4, temp);
    std::cout<<"删除的第四个元素是："<<temp<<std::endl;
    std::cout<<"循环链表长度为："<<circle.GetLength()<<std::endl;
    if(circle.SetValue(6, 9))
        std::cout<<"第6个元素被赋值为9后：";
    circle.print();
    if(circle.Insert(6, 77))
        std::cout<<"插入第6个元素77后：";
    circle.print();
    std::cout<<"元素2的下标为："<<circle.Locate(2)<<std::endl;
    circle.GetValue(4, temp);
    std::cout<<"第4个元素为："<<temp<<std::endl;
    std::cout<<"现在的链表元素依次为：";
    circle.print();
    CLinkList<int> cir_copy(b, 5);
    circle.Connect(cir_copy);
    circle.print();
    std::cout<<"合并后链表长度为："<<circle.GetLength()<<std::endl;
    return 0;
}



///2018.1.30    丁宇飞
