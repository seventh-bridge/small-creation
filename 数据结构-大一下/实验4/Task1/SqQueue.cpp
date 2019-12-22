#include "SqQueue.h"

//��ʼ����ѭ������
int InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
	return 1;
}

//��ѭ�����г���
int QueueLength(SqQueue &Q)
{
	return (Q.rear-Q.front+QUEUESIZE)%QUEUESIZE;
}

//��ѭ�����п�
int QueueEmpty(SqQueue &Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

//ѭ���������
int EnQueue(SqQueue &Q, DataType item )
{
	if((Q.rear+1)%QUEUESIZE==Q.front)
	{
		cout<<"����"; 
		return 0;
	} //���ж���

	Q.items[Q.rear]=item; //����Ԫ�ط�βָ��λ��

	Q.rear=(Q.rear+1)% QUEUESIZE; //��βָ�����
	return 1;
} 

//ѭ�����г���
int DeQueue(SqQueue &Q, DataType &item )
{
	if(Q.rear==Q.front)
	{
		cout<<"�ӿ�"; 
		return 0;
	} //���жӿ�

	item=Q.items[Q.front]; //��ɾ����ͷԪ��

	Q.front=(Q.front+1)% QUEUESIZE;//��ͷָ�����
	return 1;
} 

//ȡ��ͷ
int GetFront(SqQueue &Q, DataType &item )
{
	if(Q.rear==Q.front)
	{
		cout<<"�ӿ�"; 
		return 0;
	} //���жӿ�

	item=Q.items[Q.front]; //��ȡ��ͷԪ��
	return 1;
} 

//��������
void TraverseQueue(SqQueue &Q)
{
	int i=Q.front;
	while(i!=Q.rear)
	{
		cout<<Q.items[i]<<" ";
		i=(i+1)%QUEUESIZE;
	}
	cout<<endl;
}