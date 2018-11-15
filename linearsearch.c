#include<stdio.h>
#include<stdlib.h>

int search(int *a,int n,int value)//a is address of array n is total numbers in array value is value to be searched
{
  int i,j=-1;
  for(i=0;i<n;i++)
  {
    if(value==a[i])//when value is in the list
    {
      j=i;
      break;
    }
  }
  return j;
}
void main()
{
  int *a,n,i,j;
  printf("how many number u want to enter :\n");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  printf("enter numbers:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("enter num u want to search:");
  scanf("%d",&i);
  j=search(a,n,i);
  if(j!=-1)
  {
    printf("search succesful:value %d is present at index %d",i,j);
  }
  else
  {
    printf("searched number is not present");
  }
}
