/*
 * Output the order of the chosen kids.
 * ZWT. 18/11/09
 */
#include <stdio.h>
#define M 10  // ����Mֵ

int main()
{
    int n,nowAt=0,totalOut=0,a[M]={0};   // ��ʼ��

    printf("Input n:");    // ����n
    scanf("%d",&n);

    while(totalOut != M)  // �ж��Ƿ��������������
    {
        int nowPassed=0;
        while(1)
        {
            if(a[nowAt]==0)   // ��������±�ָʾ������Ԫ��Ϊ0����ͨ����+1
                nowPassed++;
            if(nowPassed==n)  // ������Ǳ����ĵ�n��ͬѧ��������ѭ��
                break;
            nowAt++;
            if(nowAt == M)   // �����ǰ�±�Խ����ص���һ��Ԫ��
                nowAt=0;
        }
        a[nowAt]=1;     // ���ø�ѧ���Ѿ���Ȧ
        printf("%d ",nowAt+1);   // �����ѧ�����
        totalOut++;    // �Ѿ���������ָ���+1
    }
    return 0;
}
