#include "listinarray.h"

int main(void)
{

	LIST my_List1,my_List2;//�����߱��LIST���͵ı���
	DataType Array[]={27,39,2,77,89,66};

	//��ʼ�����Ա�
	InitList(my_List1);
	InitList(my_List2);

	//�����Ա��ָ��λ�ò�������
	ListInsert(my_List1,1,89);
	ListInsert(my_List1,1,77);
	ListInsert(my_List1,3,66);
	ListInsert(my_List1,1,2);
	ListInsert(my_List1,1,39);
	ListInsert(my_List1,1,27);

	for(int i=1; i<=6; i++)
		ListInsert(my_List2,i,Array[i-1]);
	
	// ������ɾ��Ԫ��
	int removeNum = 77;
	ListDelete(my_List2, 1, &removeNum);

	//������Ա�Ԫ��
	cout<<"my_list1��";
	TraverseList(my_List1);
	cout<<"my_list2��";
	TraverseList(my_List2);
	// Output the lenth
	cout<<"Lenth of my_List2��"<<ListLength(my_List2);
	
	return 0;
}