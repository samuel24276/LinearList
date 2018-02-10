#include<iostream>

template <class T>
struct Node
{
    T data;
    struct  Node <T> *next;
};

template <class T>
class CLinkList
{
    Node <T> *rear;
public:
    CLinkList() {rear = new Node <T>;   rear->next = rear;}
    CLinkList(T a[], int n);
    ~CLinkList();
    void print();
    int GetLength() const;
    bool Insert(int i, T a);
    bool Delete(int i, T& a);
    bool GetValue(int i, T& a);
    bool SetValue(int i, T a);
    int Locate(T a);
    void Connect(CLinkList& b);
};

template <class T>
CLinkList<T>::CLinkList(T a[], int n)
{
    rear = new Node <T>;
    Node <T> *p ;
    p = rear;
    p->data = n;
    for(int i=1; i<=n; ++i)
    {
        rear->next = new Node <T>;
        rear = rear->next;
        rear->data = a[i-1];
    }
    rear->next = p;
}

template <class T>
CLinkList<T>::~CLinkList()
{
    Node <T> *p = rear->next;
    Node <T> *q;
    while(p != rear)
    {
        q = p;
        p = p->next;
        delete q;
    }
    delete p;
    rear = NULL;
}

template <class T>
int CLinkList<T>::GetLength()   const
{
    return rear->next->data;
}

template <class T>
void CLinkList<T>::print()
{
    Node <T> *p = rear->next->next;
    while(p != rear)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<p->data<<std::endl;
}

template <class T>
bool CLinkList<T>::Insert(int i, T a)
{
    if(i<1 || i>rear->next->data)       return false;
    Node <T> *p = rear->next;
    for(int j=1; j<i; ++j)
        p = p->next;
    Node <T> *q = new Node <T>;
    q->data = a;
    q->next = p->next;
    p->next = q;
    ++rear->next->data;
    return true;
}

template <class T>
bool CLinkList<T>::Delete(int i, T& a)
{
    if(i<1 || i>rear->next->data)       return false;
    Node <T> *p = rear->next;
    for(int j=1; j<i; ++j)
        p = p->next;
    Node <T> *q = p->next;
    a = q->data;
    p->next = q->next;
    delete q;
    --rear->next->data;
    return true;
}

template <class T>
bool CLinkList<T>::GetValue(int i, T& a)
{
    if(i<1 || i>rear->next->data)       return false;
    Node <T> *p = rear->next;
    for(int j=1; j<=i; ++j)
        p = p->next;
    a = p->data;
    return true;
}

template <class T>
bool CLinkList<T>::SetValue(int i, T a)
{
    if(i<1 || i>rear->next->data)       return false;
    Node <T> *p = rear->next;
    for(int j=1; j<=i; ++j)
        p = p->next;
    p->data = a;
    return true;
}

template <class T>
int CLinkList<T>::Locate(T a)
{
    Node <T> *p = rear->next;
    int i = rear->next->data;
    int j;
    for(j=1; j<=i; ++j)
    {
        p = p->next;
        if(p->data == a)
            return j;
    }
    if(j==i)    return -1;
}
template <class T>
void CLinkList<T>::Connect(CLinkList& b)
{
    rear->next->data += b.rear->next->data;         ///长度相加
    Node <T> *q = b.rear->next;                     ///保存b链表的头节点
    b.rear->next = rear->next;                      ///b链表的表尾指针指向当前链表表头
    rear->next = q->next;                           ///当前链表表尾连接b链表的起始元素
    rear = b.rear;                                  ///表尾指向b的表尾
    delete q;                                       ///删除b原来的表头
}


