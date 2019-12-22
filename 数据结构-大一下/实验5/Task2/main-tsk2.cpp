#include "BiTree.h"

int nodecount = 0;

int Depth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int dep1 = Depth(root->lchild)+1;
	int dep2 = Depth(root->rchild)+1;
	return dep1 > dep2 ? dep1 : dep2;
}

void LeafNodeCount(BTNode* root)
{
	if (root != NULL)
	{
		LeafNodeCount(root->lchild);
		LeafNodeCount(root->rchild);
		if (root->lchild == NULL && root->rchild == NULL)
			nodecount++;
	}
}

int main()
{
	BTNode* btree;
	TreeInit(btree);
	cout << "��������ʼ���ɹ�" << endl;
	DataType treeData[15] = { 'A','B','#','C','D','#','#','E','#','#','F','#','G','#','#' };
	CreateBTree_Pre(btree, treeData);
	cout << "Ҷ�ӽ�����Ϊ��";
	LeafNodeCount(btree);
	cout << nodecount << endl;
	cout << "���Ϊ��";
	cout << Depth(btree) << endl;
	return 0;
}