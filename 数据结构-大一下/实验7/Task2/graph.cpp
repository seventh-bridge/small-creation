#include "graph.h"
#include <algorithm>

//�����ڽӾ���, g��ָ��ͼ��ָ�������m[][MAXVEX]���ڽӾ���d[]�Ƕ����,n�������
void CreateGraph(AdjMetrix g,int m[][MAXVEX], DataType d[],int n){
  int i,j;
  g->vexs=n;//Ϊͼg�Ķ��������ֵ
  for(i=0;i<n;i++){//Ϊͼg�Ķ����ֵ
    g->data[i]=d[i];
    for(j=0;j<n;j++)//Ϊͼg���ڽӾ���ֵ
     g->arcs[i][j]=m[i][j];
  }
}

//��ʾ�ڽӾ���
void DispGraph(AdjMetrix g){
   int i,j;
   cout<<"ͼ�Ķ��㣺  ";
   for(i=0;i<g->vexs;i++)//���ͼg�Ķ���
      cout<<" "<<g->data[i];
   cout<<"\n\nͼ���ڽӾ���:"<<endl;
  //���forѭ�����ƶ�ÿһ��������б���
   for(i=0;i<g->vexs;i++){
      cout<<" "<<g->data[i];//�������i������
      for(j=0;j<g->vexs;j++)//���������i������֮���������i��Ӧ���ڽӾ���ĵ�i�е�����
        cout<<" "<<g->arcs[i][j];
      cout<<endl;
   } 
   cout<<endl;
}

//ȡ����k��һ���ڽӵ�
int GetFirst(AdjMetrix g,int k)
{
   int i;
   if(k<0||k>g->vexs)//�������±귶Χ��0��g->vexs-1֮�䣬�±꼴�Ƕ�������
	{
	   cout<<"����k������Χ"<<endl;
	   return -1;
   }
   for(i=0;i<g->vexs;i++)
      if(g->arcs[k][i]==1)//ɨ�趥��k�����е�Ԫ��ֵ����һ��Ԫ��ֵΪ1�Ķ�Ӧ�Ķ��㼴�Ƕ���k��һ���ڽӵ�
		return   i;//���ض���k��һ���ڽӵ�����
    return -1;
 
}

//ȡ����k���ڽӵ�t����һ���ڽӵ�
int GetNext(AdjMetrix g,int k,int t){
	 int i;
     if(k<0||k>g->vexs||t<0||t>g->vexs)
		{
	      cout<<"����k��t������Χ"<<endl;
	      return -1;
	 	}
     for(i=t+1;i<g->vexs;i++)
       if(g->arcs[k][i]==1)	
		   return   i;
    return -1;
}

//������k��ֵx
void PutVex(AdjMetrix g,int k,DataType x){
  if(k<0||k>g->vexs)  
     {
	      cout<<"����k������Χ"<<endl;
	      return ;
	 	}
   g->data[k]=x;
}

//ȡ����k��ֵ
DataType  GetVex(AdjMetrix g,int k){
  if(k<0||k>g->vexs)  
     {
	      cout<<"����k������Χ"<<endl;
	      return -1;
	 	}
  return  g->data[k];
}


//��ͨͼ������ȱ���
void DFS(AdjMetrix g,int k,int visited[]){
  int u;
  cout<<" "<<g->data[k];
  visited[k]=1;
  u=GetFirst(g,k);
  while(u!=-1)
  {
    if(visited[u]==0)
      DFS(g,u,visited);
    u=GetNext(g,k,u);
  }
}
