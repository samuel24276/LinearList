const  int MAXSIZE = 100;
template<class T>

class SeqList
{
    T data[MAXSIZE];
    int length;
public:
    SeqList()
    {
        length = 0;
    }
    SeqList(const T a[], int n);
    int GetLength();
    bool Insert(int i, T a);
    bool Delete(int i);
    void print();
    bool SetValue(int i, T a);
    T GetValue(int i);
    int Locate(T a);
};
template <class T>
SeqList<T>::SeqList(const T a[], int n)
{
    if(n>MAXSIZE)   throw"数组长度超过顺序表最大长度";
    for(int i=0; i<n; ++i)
        data[i] = a[i];
    length = n;
}

template <class T>
void SeqList<T>::print()
{
    std::cout<<"顺序表的各个元素如下：\n";
    for(int i=0; i<length; ++i)
        std::cout<<data[i]<<' ';
    std::cout<<std::endl;
}
template <class T>
int SeqList<T>::GetLength()
{
    return length;
}

template <class T>
bool SeqList<T>::SetValue(int i, T a)
{
    if(i>length || i<1) return false;
    data[i-1] = a;
    return true;
}

template <class T>
T SeqList<T>::GetValue(int i)
{
    return data[i-1];
}

template <class T>
int SeqList<T>::Locate(T a)
{
    int i;
    for(i=0; i<length; ++i)
    {
        if(data[i] == a)
            return i+1;
    }
    if(i == length)     return -1;
}

template <class T>
bool SeqList<T>::Insert(int i, T a)
{
    if(length>=MAXSIZE)     throw"顺序表长度过长";
    if(i<1 || i>length)    return false;
    length +=1;
    for(int j=length-1; j>i-1; --j)
        data[j] = data[j-1];
    data[i-1] = a;
    return true;
}

template <class T>
bool SeqList<T>::Delete(int i)
{
    if(length<=0)     throw"顺序表长度过短";
    if(i<1 || i>length)    return false;
    for(int j=i-1; j<length-1; ++j)
        data[j] = data[j+1];
    length -= 1;
    return true;
}