#include "BiTree.h"

int main()
{
	BTNode *btree;
	TreeInit(btree);
	cout << "��������ʼ���ɹ�" << endl;
	DataType treeData[15] = { 'A','B','#','C','D','#','#','E','#','#','F','#','G','#','#' };
	CreateBTree_Pre(btree, treeData);
	DataType TraverseData[16];
	cout << "ǰ�������" << endl;
	TraverseTree_Pre(btree, TraverseData);
	TraverseData[15] = '\0';
	cout << TraverseData << endl;
	cout << "���������" << endl;
	TraverseTree_Mid(btree, TraverseData);
	cout << TraverseData << endl;
	cout << "���������" << endl;
	TraverseTree_Post(btree, TraverseData);
	cout << TraverseData << endl;
	return 0;
}