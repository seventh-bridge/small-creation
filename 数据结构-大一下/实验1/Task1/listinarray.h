#include <iostream>
using namespace std;

#define LISTSIZE 100

typedef int DataType;//����DataType����

typedef struct SqList{	 
	DataType items[LISTSIZE]; //������Ա�����
    int length;
}LIST;// LISTΪ�û���������Ա�����


//��ʼ�������Ա�
void InitList(LIST &L);

//�ж����Ա��Ƿ�Ϊ�� 
int ListEmpty(LIST &L);

//������Ա���
int ListLength(LIST &L);

//�����Ա�ָ��λ�ò���һ����Ԫ��
int ListInsert(LIST &L, int pos, DataType item);

//�����Ա���ɾ����һ����ָ��ֵƥ���Ԫ��
int ListDelete(LIST &L, int pos, DataType *item);

//��ȡ˳�����ָ��λ���ϵ�����Ԫ�� 
int GetElem(LIST &L,int pos,DataType *item);

//�����Ա��в���Ԫ�أ����ص�һ����ָ��ֵƥ��Ԫ��λ��
int Find(LIST &L,DataType item);

//����������Ա�
int TraverseList(LIST &L);