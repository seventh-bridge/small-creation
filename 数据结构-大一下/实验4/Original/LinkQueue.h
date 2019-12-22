#include <iostream>
using namespace std;

typedef char DataType;

struct QNode
{ //���ṹ
	DataType	data; 
	QNode	*next; 
}; 

typedef struct 
{ //���нṹ
	QNode	*front;
	QNode	*rear; 
}LinkQueue; 

//��ʼ����ͷ����������
int InitQueue( LinkQueue &Q );

//�������п�
int QueueEmpty(LinkQueue &Q);

//���
int EnQueue( LinkQueue &Q, DataType item );

//����
int DeQueue( LinkQueue &Q,DataType &item );

//ȡ��ͷԪ��
int GetFront( LinkQueue &Q,DataType &item );

//��������
int TraverseQueue(LinkQueue &Q);

//�ͷ�������
void Destroy(LinkQueue &Q);