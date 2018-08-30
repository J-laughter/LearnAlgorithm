#include "SeqList.h"

//Ĭ�Ϲ��캯��
template<class T>
SeqList<T>::SeqList()
{
    Data = nullptr;
    Length = 0;
    Size = 0;
}

//���ι��캯��
template<class T>
SeqList<T>::SeqList(T *Data, int Length, int Size)
{
    this->Data = Data;
    this->Size = Size;
    this->Length = Length;
    this->Data = new T[Size+1];
    for(int i=0;i<Length;i++)
        this->Data[i+1] = Data[i];
}

//��������
template<class T>
SeqList<T>::~SeqList()
{
    if(Data!=nullptr)
        delete []Data;
    Data = nullptr;
    Size = 0;
    Length = 0;
}

//��ȡ˳����е�����
template<class T>
T* SeqList<T>::get_data()
{
    return Data;
}

//��ȡָ��λ������
template<class T>
T SeqList<T>::get_element(int loca)
{
    return Data[loca];
}

//��ȡ˳�����
template<class T>
int SeqList<T>::get_length()
{
    return Length;
}

//ɾ��ָ��λ��Ԫ��
template<class T>
void SeqList<T>::ele_delete(int loca)
{
    for(int i=loca;i<Length;i++)
        Data[i] = Data[i+1];
    Length--;
}

//��ָ��λ�ò���Ԫ��
template<class T>
void SeqList<T>::ele_insert(int loca,T data)
{
    if(loca>Length+1)
        throw "out of size";
    if(Length+1>=Size)
    {
        T* p = Data;
        Data = new T[Size+10];
        for(int i=1;i<=Length;i++)
            Data[i] = p[i];
        delete []p;
        p = nullptr;
        Size+=10;
    }
    for(int i=Length+1;i>loca;i--)
        Data[i] = Data[i-1];
    Data[loca] = data;
    Length++;
}

//��˳�������
template<class T>
void SeqList<T>::sort_list()
{
    for(int i=1;i<=Length;i++)
    {
        for(int j=i+1;j<=Length;j++)
        {
            if(Data[i]>Data[j])
            {
                int temp = Data[i];
                Data[i] = Data[j];
                Data[j] = temp;
            }
        }
    }
}






