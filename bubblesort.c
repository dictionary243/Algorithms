#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void bubblesort(int *a,int n)
{
  int i,j;

  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      if(*(a+j)>*(a+j+1)&&j!=n-1)
      {
        swap(a+j,a+j+1);
      }
    }
  }
}
void print(int *a,int n)
{
  int i;
  printf("\n so sorted list is\n");
  for(i=0;i<n;i++)
  {
    printf("\t%d",*(a+i));
  }
}
int main()
{
  int n,*a,i;
  printf("\n how many num do u want to enter:");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  printf("\n enter numbers:");
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  bubblesort(a,n);
  print(a,n);
}
