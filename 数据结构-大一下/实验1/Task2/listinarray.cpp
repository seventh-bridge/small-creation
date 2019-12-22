#include "listinarray.h"

//��ʼ�������Ա�
void InitList(LIST &L)
{
	L.length=0;
}

//�ж����Ա��Ƿ�Ϊ�� 
int ListEmpty(LIST &L)
{
	if(L.length<=0)	
		return 1;
	else	
		return 0;
} 

//������Ա���
int ListLength(LIST &L)
{
	return L.length;
}

//�����Ա�ָ��λ�ò���һ����Ԫ��
int ListInsert(LIST &L, int pos, DataType item)
{//posΪ����ģ��߼���λ��,itemΪ�����������Ԫ��
	int i;
	if(L.length>=LISTSIZE){                  //�б���
		cout<<"˳��������޷����룡"<<endl;
        return 0;}
	if(pos<=0 || pos>L.length+1){           //��λ��
		cout<<"����λ����Ч��"<<endl;
		return 0;}
	for(i=L.length-1;  i>=pos-1;  i--)     //����ƶ�Ԫ��
		L.items[i+1]=L.items[i];
	L.items[pos-1]=item;		            //����	
    L.length++;			            //����һ
	return 1; 
} 

//�����Ա���ɾ����һ����ָ��ֵƥ���Ԫ��
int ListDelete(LIST &L, int pos, DataType *item)
{//posΪɾ���ģ��߼���λ��,��item���ر�ɾԪ��
	int i;
	if(ListEmpty(L)){                     //�б��
		cout<<"˳���Ϊ�ձ��޷�ɾ����"<<endl;
        return 0; }
	if(pos<1 || pos>L.length){       //��λ��
		cout<<"ɾ��λ����Ч��"<<endl;
		return 0; }
	*item=L.items[pos-1];          //ɾ��Ԫ��ǰ����Ԫ�ص�ֵͨ��ָ�봫�ݸ��ⲿ������
	for(i=pos;i<L.length;i++)      //��ǰ�ƶ�Ԫ��	
          L.items[i-1]=L.items[i];
	L.length--;		           //����һ
	return 1; 
}

//��ȡ˳�����ָ��λ���ϵ�����Ԫ�� 
int GetElem(LIST &L,int pos,DataType *item)
{//posΪָ��λ��,item���ڷ����ҵ�������Ԫ��if(ListEmpty(L))	return 0;
	if(pos<=0 || pos>L.length){
		cout<<"λ����Ч"<<endl;
		return 0;
	}
	*item=L.items[pos-1];        //��Ԫ�ص�ֵͨ��ָ�봫�ݸ��ⲿ
	return 1;
} 
/*
//�����Ա��в���Ԫ�أ����ص�һ����ָ��ֵƥ��Ԫ��λ��
int Find(LIST &L,DataType item)
{//itemΪ�����ҵ�����Ԫ��
	int i=0;   // i��ʾ��ǰ���ҵ�λ�ã���ͷ��ʼ
	if(ListEmpty(L)){
		cout<<"˳���Ϊ�ձ��޷����ң�"<<endl;
		return 0;
	}
	//��ͷ��β�Ƚ����Ա��е�Ԫ�أ���δ�������Ա��ĩβ����δ�ҵ�ʱ��i�����
	bool operator != (const DataType a, const DataType b){
		strcmp(a.bookName, b.bookName) ? (strcmp(a.bookNumber, b.bookNumber) ? (fabs()
	}
	while(i<L.length && L.items[i]!=item) 
		i++;
	if(i<L.length)	    //���δ�������Ա��ĩβ��˵���ҵ�
		return i+1;     //�����߼�λ��
	else	            
		return 0;       //�������Ա��ĩβ����˵���Ҳ���
} 

//����������Ա�
int TraverseList(LIST &L)
{
    int i;
	for(i=0;i<L.length;i++)    //��ͷ��β������Ա��ÿһ��Ԫ��
        cout<<"������"<<L.items[i].bookName<<"  ��ţ�"<<L.items[i].bookNumber<<"  �۸�"<<L.items[i].bookPrice<<endl;
    return 1;
} 
*/