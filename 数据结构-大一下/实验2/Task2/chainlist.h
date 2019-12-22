#include <iostream>
using namespace std;

typedef   char  DataType; 

struct Node  //Node为结点类型名
{
	DataType 	data;   //data代表数据元素
	struct Node	*next; //next为指向下一结点的指针
}; 


//初始化单链表
int InitList(Node * &H);

//判表空
int ListEmpty(Node * H);

//求单链表中当前元素的个数
int ListLength(Node * H);

//遍历单链表
void TraverseList(Node * H);

//返回第一个与指定值匹配的元素位置
int Find_item(Node * H, DataType item);

//获取单链表中指定位置上的数据元素
int Find_pos(Node * H, int pos, DataType *item);

//向线性表指定位置插入一个新元素
int ListInsert (Node *H , int pos, DataType item);

//从线性表中删除第一个与指定值匹配的元素
int ListDelete (Node *H, DataType item);

//撤销单链表
void DestroyList(Node * &H);

// 按顺序加入链表
int ListInsert_order(Node *H, DataType item);

