#include "DouLinkList.h"

//Ĭ�Ϲ��캯��
template<class T>
DouLinkList<T>::DouLinkList()
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Head->Prior = nullptr;
}

//���ι��캯��
template<class T>
DouLinkList<T>::DouLinkList(T* data,int Len)
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Head->Prior = nullptr;
    Node<T>* sign = Head;
    for(int i=0;i<Len;i++)
    {
        Node<T>* p = new Node<T>;
        p->Data = data[i];
        p->Prior = sign;
        p->Next = sign->Next;
        sign->Next = p;
        sign = p;
    }
}

//��������
template<class T>
DouLinkList<T>::~DouLinkList()
{
    if(Head)
    {
        while(Head->Next)
            ele_delete(1);
        delete Head;
        Head = nullptr;
    }
}

//��ȡͷ�ڵ�
template<class T>
Node<T>* DouLinkList<T>::get_head()
{
    return Head;
}

//��ָ��λ�ò���Ԫ��
template<class T>
void DouLinkList<T>::ele_insert(T data, int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    Node<T>* p = new Node<T>;
    p->Data = data;
    p->Next = sign->Next;
    p->Prior = sign;
    sign->Next->Prior = p;
    sign->Next = p;
}

//ɾ��ָ��λ��Ԫ��
template<class T>
void DouLinkList<T>::ele_delete(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    sign->Prior->Next = sign->Next;
    sign->Next->Prior = sign->Prior;
    delete sign;
    sign = nullptr;
}

//��ѯָ��Ԫ���Ƿ��������У������ڣ����ص�һ����λ�ã��������ڣ�����-1
template<class T>
int DouLinkList<T>::ele_locate(T data)
{
    Node<T>* sign = Head->Next;
    int posi = 1;
    while(sign)
    {
        if(sign->Data==data)
            return posi;
        sign = sign->Next;
        posi++;
    }
    return -1;
}

//��ָ��λ��Ԫ���޸�Ϊָ��ֵ
template<class T>
void DouLinkList<T>::ele_modify(int posi, T data)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    sign->Data = data;
}

//��ȡ����β��Ԫ��
template<class T>
Node<T>* DouLinkList<T>::get_back()
{
    Node<T>* sign = Head;
    while(sign->Next)
        sign = sign->Next;
    return sign;
}

//�ƶ�������ָ��λ��
template<class T>
Node<T>* DouLinkList<T>::move_to(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    return sign;
}
