#include "SqQueue.h"

int main() 
{
	SqQueue Q;
	InitQueue(Q);
	cout << "��ʼ�����гɹ���" << endl;
	char inQueue = 'a';
	for (int i = 0; i < 4; i++)
		EnQueue(Q, (char)((int)inQueue + i));
	cout << "Q.front=" << Q.front << " Q.rear=" << Q.rear << endl;
	cout << "����e��";
	EnQueue(Q, 'e');
	cout << endl << "���ӵ�Ԫ��Ϊ��";
	for (int i = 0; i < 3; i++)
	{
		DataType tmp;
		DeQueue(Q, tmp);
		cout << tmp << " ";
	}
	cout << "Q.front=" << Q.front << " Q.rear=" << Q.rear << endl;
	cout << endl << "�������У�";
	TraverseQueue(Q);
	inQueue = 'e';
	for (int i = 0; i < 3; i++)
		EnQueue(Q, (char)((int)inQueue + i));
	cout << endl << "Q.front=" << Q.front << " Q.rear=" << Q.rear << endl;
	while (!QueueEmpty(Q))
	{
		DataType tmp;
		DeQueue(Q, tmp);
	}
	cout << "�������ٳɹ�";
	return 0;
}