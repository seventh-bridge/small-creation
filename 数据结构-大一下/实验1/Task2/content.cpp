#include "listinarray.h"

int main(void)
{

	LIST my_List1;//�����߱��LIST���͵ı���
	DataType Array[]={{"9787302257646", "������ƻ���", 25.00}, {"9787302164340", "������ƻ�������2�棩", 20.00},  \
	{"9787811234923", "������Գ�����ƽ̳�", 21.00}, {"9787810827430", "��ҵ��������Ƽ�������ԭ����Ӧ��", 29.00}, \
	{"9787302219972", "��Ƭ��������Ӧ��", 32.00}};

	//��ʼ�����Ա�
	InitList(my_List1);

	//�����Ա��ָ��λ�ò�������
	for (int i=0; i<5; i++)
		ListInsert(my_List1,1,Array[i]);

	//������Ա�Ԫ��
	DataType book3;
	GetElem(my_List1, 3, &book3);
	cout<<"������"<<book3.bookName<<"  ��ţ�"<<book3.bookNumber<<"  �۸�"<<book3.bookPrice<<endl;
	
	return 0;
}