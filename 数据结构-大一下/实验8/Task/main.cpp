#include "Sort_Alg.h"

int main()
{
	int inputNumber[100] = { 0 }, n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputNumber[i];
	cout << "����������̣�(���һ��Ϊ���ս����" << endl;
	QuickSort(inputNumber, 0, n-1, n);
	cout << endl << "��������̣������һ��Ϊ���ս����" << endl;
	HeapSort_Proc(inputNumber, 0, n - 1, n);
	for (int i = 0; i < n; i++)
		cout << inputNumber[i] << " ";
	cout << endl;
	return 0;
}
