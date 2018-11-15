#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
  int t=*x;
  *x=*y;
  *y=t;
}
void insertion(int *a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      if(*(a+j)>*(a+i))
      {
          swap(a+j,a+i);
      }
    }
  }
}
void main()
{
  int n,*a,i;
  printf("\nhow many num u want to enter :");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  printf("\nenter numbers:");
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  insertion(a,n);
  for(i=0;i<n;i++)
  {
    printf("\t%d",*(a+i));
  }

}
