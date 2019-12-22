#include <iostream>
using namespace std;

typedef char DataType;

typedef struct Node{		
	DataType	data;    //������	
	struct Node *lchild;
	struct Node *rchild; //������������ָ��	
}BTNode;//�������������

//��ʼ���ն�����
void TreeInit(BTNode* &root);

//����ǰ��������н���������
void CreateBTree_Pre(BTNode  *&root, DataType Array[]);

//�ͷŶ����������н��
void ClearBTree(BTNode* &root);

void TraverseTree_Pre(BTNode* &root, DataType ResArray[]);

void TraverseTree_Mid(BTNode* &root, DataType ResArray[]);

void TraverseTree_Post(BTNode* &root, DataType ResArray[]);