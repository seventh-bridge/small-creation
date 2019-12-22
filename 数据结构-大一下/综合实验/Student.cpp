#include "Student.h"

void MainMenu()
{
	printf("########## ���Ա�������ϵͳ v1.0 ##########\n");
	printf("                          18271241 ��Τͮ\n");
	printf("           1. ��ӿ�����Ϣ\n");
	printf("           2. ��ѯ������Ϣ\n");
	printf("           3. ���ȫ��������Ϣ\n");
	printf("           4. �˳�����\n");
	printf("#########################################\n\n\n");
	printf("�������������");
}

void OutputStudent(Examinee a)
{
	printf("\nѧ�����飺\n");
	printf("������%s\n", a.Name);
	printf("���ţ�%s\n", a.ExamNum);
	printf("�Ա�");
	if (a.Gender == false)
		printf("��\n");
	else
		printf("Ů\n");
	printf("���䣺%d\n", (int)a.Age);
	printf("���Կ�Ŀ��%s\n", a.examtype);
}

int InitList(DataNode*& H)
{
	H = new DataNode;
	if (!H)
	{
		cout << "��ʼ������" << endl;
		return 0;
	}
	H->next = NULL;
	return 1;
}

void AddStudent(DataNode* H, bool* HeadStatus)
{
	system("cls");
	DataNode* p = H;
	while (p->next != NULL)
		p = p->next;
	DataNode* t = new DataNode;
	system("cls");
	printf("������ѧ�ţ�");
	scanf("%s", t->data.ExamNum);
	printf("������������Ӣ�ģ���");
	scanf("%s", t->data.Name);
	printf("�������Ա�0Ϊ�У�1ΪŮ����");
	int tmp = 0;
	scanf("%d", &tmp);
	if (tmp == 1)
		t->data.Gender = true;
	else
		t->data.Gender = false;
	printf("���������䣺");
	scanf("%hu", &t->data.Age);
	printf("�����뿼�Կ�Ŀ��");
	scanf("%s", t->data.examtype);
	t->next = NULL;
	if (*HeadStatus == false)
	{
		*H = *t;
		*HeadStatus = true;
	}
	else
		p->next = t;
	printf("���ѧ����Ϣ�ɹ���\n\n");
	system("pause");
}

int FindStudent(DataNode* H, int option, char data[], DataNode **item)
{
	DataNode* p = H;
	if (option == 1)
	{
		while (p != NULL)
		{
			if (strcmp(p->data.Name, data) == 0)
			{
				*item = p;
				return 1;
			}
			p = p->next;
		}
		printf("\nδ�ҵ���ѧ����");
		system("pause");
		return 0;
	}
	else if (option == 2)
	{
		while (p != NULL)
		{
			if (strcmp(p->data.ExamNum, data) == 0)
			{
				*item = p;
				return 1;
			}
			p = p->next;
		}
		printf("\nδ�ҵ���ѧ����");
		system("pause");
		return 0;
	}
	return 0;
}

void ChangeValue(Examinee* item)
{
	while (true)
	{
		printf("��ѡ����Ҫ�޸ĵ����ݣ�\n");
		printf("��1������    ��2��ѧ��    ��3������    ��4���Ա�\n");
		printf("��5�����Կ�Ŀ\n�������������");
		int opt = 0;
		if (scanf("%d", &opt) != 1 || opt < 1 || opt > 5)
		{
			printf("����������\n");
			system("pause");
			continue;
		}
		printf("�������޸ĺ�����ݣ�");
		if (opt == 1)
		{
			char tmp[20];
			scanf("%s", tmp);
			strcpy(item->Name, tmp);
		}
		else if (opt == 2)
		{
			char tmp[20];
			scanf("%s", tmp);
			strcpy(item->ExamNum, tmp);
		}
		else if (opt == 3)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			item->Age = (unsigned short)tmp;
		}
		else if (opt == 4)
		{
			int tmp = 0;
			printf("\n��0Ϊ������1ΪŮ����\n");
			scanf("%d", &tmp);
			if (tmp == 0)
				item->Gender = false;
			else
				item->Gender = true;
		}
		else if (opt == 5)
		{
			char tmp[10];
			scanf("%s", tmp);
			strcpy(item->examtype, tmp);
		}
		printf("�����޸���ɣ�\n");
		system("pause");
		break;
	}
}

int JudgeEqual(const Examinee a, const Examinee b)
{
	if (a.Age == b.Age && a.Gender == b.Gender && strcmp(a.ExamNum, a.ExamNum) == 0 && strcmp(a.examtype, b.examtype) == 0 && strcmp(a.Name, b.Name) == 0)
		return 1;
	else
		return 0;
}

/*
 * ע�⣺����������⡣
 * �ò��ֺ���δ�ܴ���pΪͷ�ڵ�ʱ��ɾ�������
 * ɾ��ͷ��㴦�����ݻᵼ��Ұָ�롣
 * ������ҵ��ʱ�����⣨��������д����Щ��û�иģ���ʹ����ʹ��ǰ�ĵ���
 */

void DeleteStudent(DataNode* H, DataNode* item)
{
	DataNode* p = H;
	while (p != NULL)
	{
		if (JudgeEqual(p->next->data, item->data))
		{
			if (p->next == NULL)
				item->next = NULL;
			else
				p->next = item->next;
			delete item;
			printf("ɾ���ɹ���\n");
			system("pause");
			return;
		}
		p = p->next;
	}
}

void ListFirstMenu()
{
	system("cls");
	printf("��ѡ������ʽ��\n");
	printf("��1������ѧ�Ž�������    ��2������������������\n");
	printf("�������������");
}

void SortStudent(DataNode* H, int option, bool HeadStatus)
{
	if (option == 1)
	{
		struct comp {
			bool operator()(const Examinee &x, const Examinee &y)
			{
				int tmp = strcmp(x.ExamNum, y.ExamNum);
				if (tmp <= 0)
					return false;
				else
					return true;
			}
		};
		priority_queue<Examinee, vector<Examinee>, comp> pq;
		DataNode* p = H;
		while (p != NULL)
		{
			if (HeadStatus == false)
				break;
			pq.push(p->data);
			p = p->next;
		}
		int i = 1;
		while (!pq.empty())
		{
			Examinee tmp = pq.top();
			pq.pop();
			printf("#########%d#########\n", i);
			OutputStudent(tmp);
			printf("####################\n");
			i++;
		}
		system("pause");
	}
	else if (option == 2)
	{
		struct comp {
			bool operator()(Examinee x, Examinee y)
			{
				int tmp = strcmp(x.Name, y.Name);
				if (tmp <= 0)
					return false;
				else
					return true;
			}
		};
		priority_queue<Examinee, vector<Examinee>, comp> pq;
		DataNode* p = H;
		while (p != NULL)
		{
			if (HeadStatus == false)
				break;
			pq.push(p->data);
			p = p->next;
		}
		int i = 1;
		while (!pq.empty())
		{
			Examinee tmp = pq.top();
			pq.pop();
			printf("#########%d#########\n", i);
			OutputStudent(tmp);
			printf("####################\n");
			i++;
		}
		system("pause");
	}
}
