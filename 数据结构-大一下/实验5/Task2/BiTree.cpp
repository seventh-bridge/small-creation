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