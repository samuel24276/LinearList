///静态链表实际上由两个链表构成，一个用于存储链表的各个元素，起始下标为front,
///另一个存储所有未分配的数组元素，称之为空闲链表，起始下标为tail
#include<iostream>

const int MAXSIZE = 10;
template <class T>
struct StaticNode
{
    T data;             ///数据域
    int next;           ///游标域
};

template <class T>
class StaticLinkList
{
    int front;
    int tail;
    StaticNode <T> SArray[MAXSIZE];
public:
    StaticLinkList();
    StaticLinkList(T a[], int n);
    ~StaticLinkList();
    int Locate(T a)const;
    bool Insert(int i, T a);
    bool Delete(int i, T& a);
    void print();
    int NewNode();                  ///申请节点
    void DeleteNode(int i);         ///释放节点
    bool GetValue(int i, T& a);

};

template <class T>
StaticLinkList<T>::StaticLinkList()
{
    for(int i=0; i<MAXSIZE-1; ++i)
        SArray[i].next = i+1;                   ///每个元素的游标域指向下一个数组元素
    SArray[MAXSIZE-1].next = -1;
    front = -1;                                 ///空链表的头指针定义为-1
    tail = 0;                                   ///未分配空间的第一个数组元素的下标
}

template <class T>
StaticLinkList<T>::StaticLinkList(T a[], int n)
{
    if(n>MAXSIZE)       throw"溢出";
    for(int i=0; i<MAXSIZE-1; ++i)
        SArray[i].next = i+1;
    SArray[MAXSIZE-1].next = -1;
    for(int i=0; i<n; ++i)
        SArray[i].data = a[i];
    front = 0;                      ///指向链表的起始元素
    tail = SArray[n-1].next;        ///tail指向空闲链表的第一个数组元素,注意是n-1，若是MAXSIZE-1那可错大发了
    SArray[n-1].next = -1;          ///链表中最后一个元素的next域定义为-1
}

template <class T>
StaticLinkList<T>::~StaticLinkList()
{
}

///申请结点时，若还有未分配的数组元素，则将空闲链表第一个结点分配，同时tail指向空闲链表的第一个结点，即下一个未分配元素
template <class T>
int StaticLinkList<T>::NewNode()            ///返回可用结点的下标
{
    if(tail == -1)  throw"空间不足";
    int pos = tail;
    tail = SArray[tail].next;
    return pos;
}

template <class T>
void StaticLinkList<T>::DeleteNode(int i)           ///删除下标为i的结点
{
    if(i<0 || i>MAXSIZE-1)  throw"释放空间错误";
    if(front == i)  front = SArray[i].next;         ///若释放的是第一个结点，则front要后移
    SArray[i].next = tail;          ///要释放的节点被插入空闲链表的第一个
    tail = i;                       ///tail指向第一个空闲结点
}

template <class T>
bool StaticLinkList<T>::Insert(int i, T a)           ///
{
    if(i<1 || i>MAXSIZE)    return false;
    if(i == 1)
    {
        int pos = NewNode();
        SArray[pos].data = a;
        SArray[pos].next = front;
        front = pos;
        return true;
    }
    int j = front;
    for(int k=1; k<i-1; ++k)        ///到达j=i-2, 即
    {
        j = SArray[j].next;
    }
    int pos = NewNode();
    SArray[pos].data = a;
    SArray[pos].next = SArray[j].next;
    SArray[j].next = pos;
    return true;
}

template <class T>
bool StaticLinkList<T>::Delete(int i, T& a)
{
    if(i<1 || i>MAXSIZE)    return false;
    if(i == 1)
    {
        GetValue(front, a);
        front = SArray[front].next;
        return true;
    }
    ///由被删除元素的前驱元素next可知被删除元素的下标，还需知道前驱元素的下标，即前驱的前驱的next域
    int j = front;
    for(int k=0; k<i-2; ++k)
    {
        j = SArray[j].next;
    }
    int temp = SArray[j].next;
    a = SArray[temp].data;
    SArray[j].next = SArray[temp].next;
    DeleteNode(temp);
    return true;
}

template <class T>
void StaticLinkList<T>::print()
{
    int i = front;
    while(i != -1)
    {
        std::cout<<SArray[i].data<<" ";
        i = SArray[i].next;
    }
    std::cout<<std::endl;
}

template <class T>
bool StaticLinkList<T>::GetValue(int i, T& a)           ///获取下标为i的值
{
    if(i<0 || i>MAXSIZE-1)      return false;
    a = SArray[i].data;
    return true;
}

template <class T>
int StaticLinkList<T>::Locate(T a)const                 ///获取值为a的下标
{
    int i = front;
    while(i != -1)
    {
        if(SArray[i].data == a)
            return i;
        i = SArray[i].next;
    }
    if(i == -1)     return -1;
}



