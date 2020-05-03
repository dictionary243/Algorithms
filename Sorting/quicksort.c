#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

int partition(int *a,int low,int high)
{
  int i,j,p;
  i=low-1;
  p=a[high];
  for(j=low;j<high;j++)
  {
  if(a[j]<p)
  {
    i++;
    if(i!=j)
    {
      swap(a+i,a+j);
    }
  }
  }
  i++;
  swap(a+i,a+high);
  return i;
}

void quicksort(int *a,int low,int high)
{
  int pivot;
  if(low<high)
  {
    pivot=partition(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);
  }
}
void main()
{
  int *a,n,i;
  printf("enter how many number u want to enter\n");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  quicksort(a,0,n-1);
  for(i=0;i<n;i++)
  {
    printf("\t%d",a[i]);
  }

}
