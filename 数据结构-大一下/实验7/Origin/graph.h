#include <iostream>
using namespace std;

#define MAXVEX 50//��󶥵����

typedef int weight;//�ڽӾ���Ԫ������
typedef char DataType;//������������

//�ڽӾ�������
typedef struct{
  weight  arcs[MAXVEX][MAXVEX]; //�ڽӾ���
  DataType  data[MAXVEX];//һά���鶥���
  int vexs;//�������
}MGraph,*AdjMetrix;

//�����ڽӾ���, g��ָ��ͼ��ָ�������m[][MAXVEX]���ڽӾ���d[]�Ƕ����,n�������
void CreateGraph(AdjMetrix g,int m[][MAXVEX], DataType d[],int n);

//��ʾ�ڽӾ���
void DispGraph(AdjMetrix g);

//ȡ��һ���ڽӵ�
int GetFirst(AdjMetrix g,int k);

//ȡ��һ���ڽӵ�
int GetNext(AdjMetrix g,int k,int t);

//������k��ֵx
void PutVex(AdjMetrix g,int k,DataType x);

//ȡ����k��ֵ
DataType  GetVex(AdjMetrix g,int k);

//��ͨͼ������ȱ���
void DFS(AdjMetrix g,int k,int visited[]);