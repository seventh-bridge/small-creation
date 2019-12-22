#include "LinkQueue.h"

//��ʼ����ͷ����������
int InitQueue( LinkQueue &Q )
{   //����ֻ��һ����ͷ������ʽ����
    //ͷ��βָ���ָ��ͷ���
	Q.front=Q.rear=new QNode;
	if(Q.front==NULL) {cout<<"����";return 0;}
	Q.front->next=NULL;
	return 1;
} 

//�������п�
int QueueEmpty(LinkQueue &Q)
{
	if(Q.front->next==NULL)
		return 1;
	else
		return 0;
}

//���
int EnQueue( LinkQueue &Q, DataType item )
{	//�������β�巨

	QNode *t=new QNode; //�������½��
	if(t==NULL) {cout<<"����";return 0;}
	t->data=item; t->next=NULL;	

	Q.rear->next=t; //����β��������½��

	Q.rear=t; //�۸���βָ��
	return 1;
} 

//����
int DeQueue( LinkQueue &Q,DataType &item )
{	//ɾ��������ı�ͷԪ��

	//���п�
	if(Q.front==Q.rear) {cout<<"�ӿ�";return 0;}

	QNode *t=Q.front->next;
	item=t->data;
	Q.front->next=t->next; //��ɾ����ͷ��� 

	if(Q.rear==t)  //����ɾ��β��������βָ��
		Q.rear=Q.front;
	delete t; 
	return 1;
}

//ȡ��ͷԪ��
int GetFront( LinkQueue &Q, DataType &item )
{	
	if(Q.front==Q.rear) {cout<<"�ӿ�";return 0;}
	item=Q.front->next->data;
	return 1;
}

//��������
int TraverseQueue(LinkQueue &Q)
{
	if(Q.front==Q.rear) {cout<<"�ӿ�";return 0;}
	QNode *p=Q.front->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return 1;
}

//�ͷ�������
void Destroy(LinkQueue &Q)
{
	while(Q.front!=NULL)
	{
		Q.rear=Q.front;
		Q.front=Q.front->next;
		delete Q.rear;
	}
}

void Reverse(LinkQueue &Q)
{
	DataType stack[10] = "";
	DataType *stack_bottom = stack, *stack_top = stack;
	while (!QueueEmpty(Q))
	{
		DataType tmp;
		DeQueue(Q, tmp);
		*stack_top = tmp;
		stack_top++;
	}
	stack_top--;
	while (stack_bottom != stack_top)
	{
		DataType tmp = *stack_top;
		EnQueue(Q, tmp);
		*stack_top = '\0';
		stack_top--;
	}
	EnQueue(Q, *stack_top);
	*stack_top = '\0';
}