#include "LinkQueue.h"

int main()
{
	LinkQueue Q;
	InitQueue(Q);
	cout << "���г�ʼ���ɹ�" << endl;
	char inQueue = 'a';
	for (int i = 0; i < 5; i++)
		EnQueue(Q, (char)((int)inQueue + i));
	cout << "�������У�";
	TraverseQueue(Q);
	Reverse(Q);
	cout << endl << "�ٴα�����";
	TraverseQueue(Q);
	Destroy(Q);
	cout << endl << "�������ٳɹ���";
	return 0;
}