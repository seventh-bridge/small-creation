#include "LinkQueue.h"

int main()
{
	LinkQueue M, W;
	InitQueue(M);
	InitQueue(W);
	DataType MaleName[9] = { {"M1"}, {"M2"}, {"M3"}, {"M4"}, {"M5"}, {"M6"}, {"M7"}, {"M8"}, {"M9"} };
	DataType FemaleName[7] = { {"W1"}, {"W2"}, {"W3"}, {"W4"}, {"W5"}, {"W6"}, {"W7"} };
	for (int i = 0; i < 9; i++)
		EnQueue(M, MaleName[i]);
	for (int i = 0; i < 7; i++)
		EnQueue(W, FemaleName[i]);
	cout << "��ʿ������";
	TraverseQueue(M);
	cout << endl << "Ůʿ������";
	TraverseQueue(W);
	cout << endl << "��ʼ���" << endl;
	Dancing(W, M);
	cout << "��Ժ���ʿ������";
	TraverseQueue(M);
	cout << endl << "��Ժ�Ůʿ������";
	TraverseQueue(W);
	cout << endl;
	return 0;
}