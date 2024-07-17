#include<stdio.h>
#include<string.h>
void main()
{
    char a[50], b[50];
    printf("Enter two strings a and b\n");
    scanf("%s",a);
    scanf("%s",b);
    int n = strlen(a);
    int m = strlen(b);
    int j, flag = 0;
    
    for(int i = 0; i <= n-m; i++)
    {
        j = 0;
        while(j < m && a[i+j] == b[j])
            j = j + 1;

            if(j == m)
            {
                printf("%d\n",j);
                flag = 1;
                printf("%d",i);
                break;
            }
    }
    if(flag == 0)
        printf("String not matched");
}
