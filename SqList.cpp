#include<iostream>
#include "SeqList.h"

int main()
{
    int a[30] = {1,2,3,4,5,6,7,8,9,0,10};
    SeqList<int> L(a, 20);
    L.print();
    L.SetValue(10,1);
    L.print();
    L.Insert(12, 12);
    L.print();
    L.Delete(1);
    L.print();
    L.SetValue(20,20);
    L.print();
    int temp = L.Locate(20);
    if(temp == -1)
        std::cout<<"寻找的值不存在\n";
    else    std::cout<<"寻找的值在第"<<temp<<"位上\n";
    std::cout<<"第13个元素为"<<L.GetValue(13)<<std::endl;
    L.Insert(12, 12);
    L.Insert(12, 12);
    L.Insert(12, 12);
    L.print();
    std::cout<<"顺序表长度为："<<L.GetLength()<<std::endl;
    return 0;
}



///2018.1.29    
