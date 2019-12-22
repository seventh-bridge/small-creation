#include "BiTree.h"

//��ʼ���ն�����
void TreeInit(BTNode* &root)
{
	root=NULL;
}

//����ǰ��������н���������
void CreateBTree_Pre(BTNode  *&root, DataType Array[]) 
{ 
	static int count=0;	//��̬����count
    char item=Array[count];//��ȡArray[]�����еĵ�count��Ԫ��
	count++;
	if(item == '#') //�������#�ַ�����������
	{ root = NULL; return ;}
    else
	{
		root = new BTNode;
        root->data = item;
	    CreateBTree_Pre (root->lchild,Array);    //�������� 
	    CreateBTree_Pre (root->rchild,Array); //�������� 
 	 }
}

//�ͷŶ����������н��
void ClearBTree(BTNode* &root)
{
    if(root!=NULL)
    {
        ClearBTree( root->lchild );
        ClearBTree( root->rchild );
        delete root;
        root=NULL;
    }
}

void TraverseTree_Pre(BTNode* &root, DataType ResArray[])
{
	static int pre_int = 0;
	if (root == NULL)
	{
		ResArray[pre_int] = '#';
		pre_int++;
		return;
	}
	ResArray[pre_int] = root->data;
	pre_int++;
	TraverseTree_Pre(root->lchild, ResArray);
	TraverseTree_Pre(root->rchild, ResArray);
}

void TraverseTree_Mid(BTNode* &root, DataType ResArray[])
{
	static int mid_int = 0;
	if (root == NULL)
	{
		ResArray[mid_int] = '#';
		mid_int++;
		return;
	}
	TraverseTree_Mid(root->lchild, ResArray);
	ResArray[mid_int] = root->data;
	mid_int++;
	TraverseTree_Mid(root->rchild, ResArray);
}

void TraverseTree_Post(BTNode* &root, DataType ResArray[])
{
	static int post_int = 0;
	if (root == NULL)
	{
		ResArray[post_int] = '#';
		post_int++;
		return;
	}
	TraverseTree_Post(root->lchild, ResArray);
	TraverseTree_Post(root->rchild, ResArray);
	ResArray[post_int] = root->data;
	post_int++;
}