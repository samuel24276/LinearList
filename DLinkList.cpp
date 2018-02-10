#include "DLinkList.h"

int main()
{
    int a[6] = {1,2,3,4,5,6};
    DLink_List<int> L(a, 6);
    int temp;
    L.print1();
    L.print2();
    std::cout<<"当前链表长度为："<<L.GetLength()<<std::endl;
    L.GetValue(3, temp);
    std::cout<<"当前链表第三个元素为："<<temp<<std::endl;
    std::cout<<"在删除第四个元素后链表各元素依次为：";
    L.Delete(4, temp);
    L.print1();
    std::cout<<"当前链表长度为："<<L.GetLength()<<std::endl;
    L.Insert(5,23);
    std::cout<<"在第5个位置插入23后链表各元素依次为：";
    L.print1();
    return 0;
}




///2018.1.30    丁宇飞

