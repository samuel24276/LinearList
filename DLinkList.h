#include<iostream>

template <class T>
struct Node
{
    T data;
    struct Node<T> *pri;
    struct Node<T> *next;
};

template <class T>
class DLink_List
{
    Node <T> *front = NULL;
    Node <T> *rear = NULL;
public:
    DLink_List()
    {
        front = rear = new Node <T>;
        rear->pri = rear;
        rear->next = rear;
    }
    DLink_List(T a[], int n);
    ~DLink_List();
    int GetLength();
    bool Insert(int i, T a);
    bool Delete(int i, T& a);
    bool GetValue(int i, T& a);
    void print1();
    void print2();
};

template <class T>
DLink_List<T>::DLink_List(T a[], int n)
{
    front = rear = new Node <T>;
    front->data = n;
    Node <T> *p = rear;
    Node <T> *q;
    for(int i=1; i<=n; ++i)
    {
        q = p;
        p->next = new Node <T>;

        p = p->next;
        p->pri = q;
        p->data = a[i-1];
    }
    rear = p;
    rear->next = front;
    front->pri = rear;
}

template <class T>
DLink_List<T>::~DLink_List()
{
    Node <T> *p = front->next;
    Node <T> *q;
    while(p != front)
    {
        q = p;
        p = p->next;
        delete q;
    }
    delete front;
    front = rear =NULL;
}

template <class T>
int DLink_List<T>::GetLength()
{
    return front->data;
}

template <class T>
bool DLink_List<T>::Insert(int i, T a)
{
    if(i<1 || i>front->data)        return false;
    Node <T> *p = front->next;
    for(int j=1; j<i; ++j)
    {
        p = p->next;
    }
    Node <T> *q = new Node <T>;
    q->data = a;
    p->pri->next = q;
    q->pri = p->pri;
    q->next = p;
    p->pri = q;
    ++front->data;
    return true;
}

template <class T>
bool DLink_List<T>::Delete(int i, T& a)
{
    if(i<1 || i>front->data)        return false;
    Node <T> *p = front->next;
    for(int j=1; j<i; ++j)
    {
        p = p->next;
    }
    p->pri->next = p->next;
    p->next->pri = p->pri;
    a = p->data;
    delete p;
    --front->data;
    return true;
}

template <class T>
bool DLink_List<T>::GetValue(int i, T& a)
{
    if(i<1 || i>front->data)        return false;
    Node <T> *p = front->next;
    for(int j=1; j<i; ++j)
    {
        p = p->next;
    }
    a = p->data;
    return true;
}

template <class T>
void DLink_List<T>::print1()
{
    Node <T> *p = front->next;
    while(p != front)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
}

template <class T>
void DLink_List<T>::print2()
{
    Node <T> *p = rear;
    while(p != front)
    {
        std::cout<<p->data<<" ";
        p = p->pri;
    }
    std::cout<<std::endl;
}


