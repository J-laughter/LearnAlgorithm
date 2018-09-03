#include "LinkList.h"

//Ĭ�Ϲ��캯��
template<class T>
LinkList<T>::LinkList()
{
    Head = new Node<T>;
    Head->Next = nullptr;
}

//���ι��캯��
template<class T>
LinkList<T>::LinkList(T* data, int len)
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Node<T>* sign = Head;
    for(int i=0;i<len;i++)
    {
        Node<T>* p = new Node<T>;
        p->Data = data[i];
        p->Next = nullptr;
        sign->Next = p;
        sign = p;
    }
}

//��������
template<class T>
LinkList<T>::~LinkList()
{
    if(Head!=nullptr)
    {
        while(Head->Next!=nullptr)
            ele_delete(1);
        delete Head;
        Head = nullptr;
    }
}

//��ȡͷ�ڵ�
template<class T>
Node<T>* LinkList<T>::get_head()
{
    return Head;
}

//��ָ��λ�ò���Ԫ��
template<class T>
void LinkList<T>::ele_insert(T data, int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
        sign = sign->Next;
    Node<T>* p = new Node<T>;
    p->Data = data;
    p->Next = sign->Next;
    sign->Next = p;
}

//ɾ��ָ��λ��Ԫ��
template<class T>
void LinkList<T>::ele_delete(int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
        sign = sign->Next;
    Node<T>* p = sign->Next;
    sign->Next = p->Next;
    delete p;
    p = nullptr;
}

//��ѯָ��Ԫ���Ƿ��������У������ڣ����ص�һ����λ�ã��������ڣ�����-1
template<class T>
int LinkList<T>::ele_locate(T data)
{
    Node<T>* sign = Head->Next;
    int posi = 1;
    while(sign!=nullptr)
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
void LinkList<T>::ele_modify(int posi, T data)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
        sign = sign->Next;
    sign->Data = data;
}

//��ȡ����β��Ԫ��
template<class T>
Node<T>* LinkList<T>::get_back()
{
    Node<T>* sign = Head;
    while(sign->Next!=nullptr)
        sign = sign->Next;
    return sign;
}

//�ƶ�������ָ��λ��
template<class T>
Node<T>* LinkList<T>::move_to(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
        sign = sign->Next;
    return sign;
}
