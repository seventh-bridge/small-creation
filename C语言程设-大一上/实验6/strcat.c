/*
 * ��дstrcat����
 * ZWT. 18/11/23
*/
#include <stdio.h>

char* strcat(char *dst,char *src)  // ���庯��
{
    int i,j;
    for(i=0;*(dst+i)!='\0';i++)  // �ﵽdstĩβ
        continue;
    for(j=0;*(src+j)!='\0';j++)  // ��dst������ڴ渴д
        *(dst+i+j)=*(src+j);
    *(dst+i+j)='\0';  // ��ӽ������ַ�
    return dst;
}

int main()
{
    char s1[100],s2[100];
    gets(s1);  // ���������ַ���
    gets(s2);
    strcat(s1,s2);  // ����ƴ��
    printf("%s",s1);
    return 0;
}
