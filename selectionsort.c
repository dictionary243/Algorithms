#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
int *a,i,j,t;
printf("\n enter how many num u want to insert");
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
printf("-------------------------------");
printf("\n enter  numbers:");
for(i=0;i<n;i++)
{
scanf("%d",a+i);
}
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
if(a[i]>a[j])
{
t=a[j];
a[j]=a[i];
a[i]=t;
}
}
}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d",*(a+i));
printf(" ");
}
}
