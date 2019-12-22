#include "chainlist.h"

//��ʼ��������
int InitList(Node *&H)
{  //HΪָ�������ͷָ��
	H=new Node;
	if(!H)
    {
        cout<<"��ʼ������"<<endl;
		return 0;
	} 
	H->next=NULL;
	return 1; 
}

//�б��
int ListEmpty(Node * H)
{  //HΪָ�������ͷָ��
	if(H->next)
		return 0;
	else //ͷ���ָ����Ϊ��
		return 1; 
}

//�������е�ǰԪ�صĸ���
int ListLength(Node * H)
{  //HΪָ�������ͷָ��
	Node *p=H->next;
	int total=0; 
	while(p){ 
		total++;      //������+1 
		p=p->next; //ָ�����
	}
	return total; 
}

//����������
void TraverseList(Node * H)
{  //HΪָ�������ͷָ��
	Node *p=H->next;
	while(p)
    { 
          cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}

//���ص�һ����ָ��ֵƥ���Ԫ��λ��
int Find_item(Node * H, DataType item)
{  //HΪָ�������ͷָ��
	Node *p=H->next;
	int pos=0; //���λ��
	while(p)
    { //�ӵ������һ����㿪ʼ˳��������н��
          pos++;
		if(p->data==item) break;
		p=p->next;
	}
	if(p) return pos; //����λ�ñ��
	else  return 0;
}

//��ȡ��������ָ��λ���ϵ�����Ԫ��
int Find_pos(Node * H, int pos, DataType *item)
{  //HΪָ�������ͷָ��
	Node *p=H->next;
	int i=1; //���λ��
	while(p && i!=pos){ 
		p=p->next; i++; 
	}
	if(p==NULL){ //���Ҳ��ɹ����˳�����
		cout<<"λ����Ч"<<endl;
		return 0;
	}
	*item=p->data;
	return 1; 
}

//�����Ա�ָ��λ�ò���һ����Ԫ��
int ListInsert (Node *H , int pos, DataType item)
{	
	Node *p=H;  int i=0;
	while( p ){ //����pos��ǰ��
		if(i+1==pos) break;
		p=p->next; i++;
	}
	if(p==NULL){ //���Ҳ��ɹ����˳�����
		cout<<"����λ����Ч"<<endl;
		return 0;
	}
	Node *t=new Node;	t->data=item; //��
	t->next=p->next; //��
	p->next=t; //��
	return 1;
}

//�����Ա���ɾ����һ����ָ��ֵƥ���Ԫ��
int ListDelete (Node *H, DataType item)
{	
	Node *p=H, *t;  int i=0;
	while( p->next ){ //����pos��ǰ��
		if(p->next->data==item) break;
		p=p->next; 
	}
	if(p->next==NULL){ //���Ҳ��ɹ����˳�����
		cout<<"ɾ��Ԫ�ز�����"<<endl;
		return 0;
	}
	t=p->next;	    //��tΪ��ɾ�����
	p->next=t->next; //��ɾ��t�����ӹ�ϵ
	delete t;		   //���ͷű�ɾ���
	return 1;
}

//����������
void DestroyList(Node * &H)
{  //HΪָ�������ͷָ��
	Node *p=H;
	while(H){ 
		p=H;
		H=H->next; 
		delete p;
	}
}

