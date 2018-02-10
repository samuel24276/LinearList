#include<iostream>

template <class T>
struct Node
{
    T data;
    struct Node <T> *next;
};

template <class T>
class LinkList
{
    Node <T> *front;
public:
    LinkList()
    {
        front = new Node <T>;
        front->next = NULL;
    }
    LinkList(T a[], int n);
    ~LinkList();
    void print();
    bool Insert(int i, T a);
    bool Delete(int i, T& a);
    bool SetValue(int i, T a);
    bool GetValue(int i, T& a)const;
    int Locate(T a)const;
    int GetLength()const;
};

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
    front = new Node <T>;
    front->next = NULL;
    for(int i=n; i>0; --i)          ///头插法
    {
        Node <T> *s = new Node <T>;
        s->data = a[i-1];
        s->next = front->next;
        front->next = s;
    }
    front->data = n;
}

template <class T>
LinkList<T>::~LinkList()
{
    Node <T> *s = front->next;
    while(front->next)
    {
        front->next = s->next;
        delete s;
        s = front->next;
    }
    front = NULL;
}

template <class T>
void LinkList<T>::print()
{
    Node <T> *s = front->next;
    while(s)
    {
        std::cout<<s->data<<" ";
        s = s->next;
    }
    std::cout<<std::endl;
}

template <class T>
bool LinkList<T>::Insert(int i, T a)          ///插入第i个位置之前
{
    if(i>front->data || i<0)     return false;
    Node <T> *s = front;
    for(int j=1; j<i; ++j)
    {
        s = s->next;
    }
    Node <T> *p = new Node<T>;
    p->data = a;
    p->next = s->next;
    s->next = p;
    ++front->data;
    return true;
}

template <class T>
bool LinkList<T>::Delete(int i, T& a)
{
    if(i>front->data || i<0)     return false;
    Node <T> *s = front;
    for(int j=1; j<i; ++j)
    {
        s = s->next;
    }
    Node <T> *p = s->next;
    a = p->data;
    s->next = p->next;
    delete p;
    --front->data;
    return true;
}

template <class T>
bool LinkList<T>::SetValue(int i, T a)
{
    if(i>front->data || i<0)     return false;
    Node <T> *s = front->next;
    for(int j=1; j<i; ++j)
    {
        s = s->next;
    }
    s->data = a;
    return true;
}

template <class T>
bool LinkList<T>::GetValue(int i, T& a) const
{
    if(i>front->data || i<0)     return false;
    Node <T> *s = front->next;
    for(int j=1; j<i; ++j)
    {
        s = s->next;
    }
    a = s->data;
    return true;
}

template <class T>
int LinkList<T>::Locate(T a) const
{
    Node <T> *s = front->next;
    for(int i=1; s->next!=NULL; ++i)
    {
        if(s->data == a)
            return i;
        s=s->next;
    }
    if(!s->next)    return -1;
}

template <class T>
int LinkList<T>::GetLength() const
{
    return front->data;
}



