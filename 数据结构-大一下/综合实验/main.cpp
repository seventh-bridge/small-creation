#include "Student.h"

int main()
{
	DataNode *student = NULL;
	InitList(student);
	bool HeadHaveData = false;
	while (true)
	{
		system("cls");
		MainMenu();
		int optcode = 0;
		if (!scanf("%d", &optcode) || optcode < 1 || optcode > 5)
		{
			printf("\n���������Ϸ���\n");
			system("pause");
			continue;
		}
		else if (optcode == 4)
			exit(0);
		else if (optcode == 1)
		{
			AddStudent(student, &HeadHaveData);
			continue;
		}
		else if (optcode == 2)
		{
			while (true)
			{
				system("cls");
				printf("��1��ͨ����������    ��2��ͨ��ѧ�Ų���\n�������������");
				int opt_start = 0;
				if (scanf("%d", &opt_start) != 1 || opt_start < 1 || opt_start > 2)
				{
					printf("\n���������Ϸ���");
					system("pause");
					continue;
				}
				DataNode *tmp = NULL;
				printf("\n���������ݣ�");
				char find_data[20];
				scanf("%s", find_data);
				int find_retcode = FindStudent(student, opt_start, find_data, &tmp);
				if (find_retcode == 0)
					break;
				OutputStudent(tmp->data);
				printf("\n\n\n       ��1���޸�    ��2��ɾ��    ��3������\n\n�������������");
				int opt_finish = 0;
				if (scanf("%d", &opt_finish) != 1 || opt_finish > 3 || opt_finish < 1)
				{
					printf("\n���������Ϸ�����������ҳ�档\n");
					system("pause");
					break;
				}
				else if (opt_finish == 3)
					break;
				else if (opt_finish == 1)
					ChangeValue(&(tmp->data));
				else if (opt_finish == 2)
					DeleteStudent(student, tmp);
				break;
			}
		}
		else if (optcode == 3)
		{
			while (true)
			{
				ListFirstMenu();
				int opt_list = 0;
				if (scanf("%d", &opt_list) != 1 || opt_list < 1 || opt_list > 2)
				{
					printf("���������Ϸ���");
					system("pause");
					continue;
				}
				else if (opt_list == 1)
					SortStudent(student, 1, HeadHaveData);
				else if (opt_list == 2)
					SortStudent(student, 2, HeadHaveData);
				break;
			}
		}
	}
	return 0;
}
