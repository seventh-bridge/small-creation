#include <iostream>
#include <cstring>

using namespace std;
//Huffman���Ĵ洢�ṹ
#define n 11						//Ҷ����Ŀ
#define m 2*n-1					//���н������
typedef struct					//�������
{	float weight;				//Ȩֵ��������Ȩֵ��������
	int lchild,rchild,parent;	//���Һ��Ӽ�˫��ָ��
}HTNode;
typedef HTNode HuffmanTree[m];	//HuffmanTree����������

typedef struct
{	char ch;					//�洢�ַ�
	char bits[n+1];				//��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[n];


void CreateHuffmanTree(HuffmanTree T);//����Huffman����T[m-1]Ϊ������
void InitHuffmanTree(HuffmanTree T);	//��ʼ��Huffman��
void InputWeight(HuffmanTree T);		//����Ȩֵ
void SelectMin(HuffmanTree T,int i,int *p1,int *p2);//��T��ѡ������Ȩ��С�ĸ����
void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H);//����Huffman��T��Huffman�����H

int main()
{

	HuffmanTree T;
	HuffmanCode H;
	CreateHuffmanTree(T);
	CharSetHuffmanEncoding(T,H);
	//��ʼ�������
	cout << endl << "�����������ڵ�id, weight, parent, lchild, rchildΪ��" << endl;
	for (int i = 0; i < m; i++)
		cout << i << " " << T[i].weight << " " << T[i].parent << " " << T[i].lchild << " " << T[i].rchild << endl;
	return 0;
}

void CreateHuffmanTree(HuffmanTree T)
{ 	//����Huffman����T[m-1]Ϊ������
	int i,p1,p2;
	InitHuffmanTree(T);		//��T��ʼ��
	InputWeight(T);			//����Ҷ��Ȩֵ��T[0..n-1]��weight��
	for(i=n;i<m;i++)		//������n-1�κϲ����½�����δ���T[i]��
	{	SelectMin(T,i-1,&p1,&p2);
		//��T[0..i-1]��ѡ������Ȩ��С�ĸ���㣬����ŷֱ�Ϊp1��p2
		T[p1].parent=T[p2].parent=i;
		T[i].lchild=p1;		//��СȨ�ĸ�������½�������
		T[i].rchild=p2;		//��СȨ�ĸ�������½����Һ���
		T[i].weight=T[p1].weight+T[p2].weight;
	}
}

void InitHuffmanTree(HuffmanTree T)
{	//��ʼ��Huffman��
	int i;
	for (i=0;i<m;i++)
	{
		T[i].weight=0;
		T[i].lchild=T[i].rchild=T[i].parent=NULL;
	}
}

void InputWeight(HuffmanTree T)
{	//����Ȩֵ
	int i;
	for (i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��Ȩֵ��";
		cin>>T[i].weight;
	}
}

void SelectMin(HuffmanTree T,int i,int *p1,int *p2)
{	//��T��ѡ������Ȩ��С�ĸ����
	int j;
	float min1,min2;
	min1=min2=-1;
	for(j=0;j<=i;j++)
		if(T[j].parent==NULL)
		{
			if(T[j].weight<min1||min1==-1)
			{
				if(min1!=-1)
				{
					min2=min1;
					*p2=*p1;
				}
				min1=T[j].weight;
				*p1=j;
			}
			else
				if(T[j].weight<min2||min2==-1)
				{
					min2=T[j].weight;
					*p2=j;
				}
		}
}

void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H)
{	//����Huffman��T��Huffman�����H
	int c,p,i;				//c��p�ֱ�ָʾT�к��Ӻ�˫�׵�λ��
	char cd[n+1];			//��ʱ��ű���
	char str[n+1];           //��������ַ���
	int start;				//ָʾ������cd�е���ʼλ��
	cd[n]='\0';				//���������
	cout<<"�������ַ�����";
	cin>>str;
	for(i=0;i<n;i++)		//������Ҷ��T[i]�ı���
	{
		H[i].ch=str[i];	//����Ҷ��T[i]��Ӧ���ַ�
		start=n;			//������ʼλ�õĳ�ֵ
		c=i;				//��Ҷ��T[i]��ʼ����
		while((p=T[c].parent)!=NULL)//ֱ�����ݵ�T[c]������Ϊֹ
		{	//��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
			cd[--start]=(T[p].lchild==c)?'0':'1';
			c=p;			//��������
		}
		strcpy(H[i].bits,&cd[start]);		//���Ʊ���λ��
	}
	for(i=0;i<n;i++)
		cout<<"��"<<i+1<<"���ַ�"<<H[i].ch<<"�ı���Ϊ"<<H[i].bits<<endl;
}

