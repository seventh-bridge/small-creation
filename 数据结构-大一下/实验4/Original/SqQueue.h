#include <iostream>
using namespace std;

#define QUEUESIZE 5

typedef char DataType;

typedef struct 
{
	DataType items[QUEUESIZE]; 
	int	front;
	int rear;
}SqQueue;

//��ʼ����ѭ������
int InitQueue(SqQueue &Q);

//��ѭ�����г���
int QueueLength(SqQueue &Q);

//��ѭ�����п�
int QueueEmpty(SqQueue &Q);

//ѭ���������
int EnQueue(SqQueue &Q, DataType item );

//ѭ�����г���
int DeQueue(SqQueue &Q, DataType &item );

//ȡ��ͷ
int GetFront(SqQueue &Q, DataType &item );

//��������
void TraverseQueue(SqQueue &Q);