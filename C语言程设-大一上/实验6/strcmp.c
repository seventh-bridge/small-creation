/*
 * ��дstrcmp����
 * ZWT. 18/11/23
*/
#include <stdio.h>

int strcmp(char *s1,char *s2)  // ���庯��
{
    int i=0;
    while(1)
    {
        char a=*(s1+i),b=*(s2+i); // ��ȡ��ǰ��Ҫ�Ƚϵ��ַ�
        i++;
        if(a=='\0' && b=='\0')  // ���бȽ�
            return 0;
        else if(a>b)
            return 1;
        else if(a<b)
            return -1;
        else if(a==b)
            continue;
    }
}

int main()
{
    char s1[100],s2[100];
    gets(s1);  // ���������ַ���
    gets(s2);
    printf("strcmp returns %d",strcmp(s1,s2));  // ���strcmp�����ķ���ֵ
    return 0;
}
