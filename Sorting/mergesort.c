#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int from,int to,int mid)//to merge the broken array
{                                         // first array is [from ,mid]
  int i=from;                             //second array is [mid+1,to]
  int j=mid+1;
  int k=0;
  int b[to-from+1];//it is temporary array to store sorted data after we will re assign it to main array
  while(i<=mid&&j<=to)//trivial one to sort 2 array
  {
  if(a[j]>a[i])
  {
    b[k]=a[i];
    i++,k++;
  }
  else
  {
    b[k]=a[j];
    j++,k++;
  }
}//we will come out from while if i will reach to mid+1 or j will reach to to+1
  while(i<=mid)//if j will be at to+1 than first array is having some element so we r assigning it to b
  {
    b[k]=a[i];
    k++,i++;
  }
  while(j<=to)//if i will be at mid +1 than second array is having some element so we r assigning it to b
  {
    b[k]=a[j];
    k++,j++;
  }
  for(k=from;k<=to;k++)//after this re assigning all data in a
  {
    a[k]=b[k-from];
  }

}
void mergesort(int *a,int from,int to)//declration of meregesort
{
  int mid;
  if(from<to)
  {
  mid=(from+to)/2;
  mergesort(a,from,mid);//divide and rule method
  mergesort(a,mid+1,to);
  merge(a,from,to,mid);//after dividing merging is done
  }
}
void main()
{
  int n,i;
  int *a;
printf("\nenter how many number u want to enter");//to find out how much size we have to allocate for array
scanf("%d",&n);
a=(int *)malloc(n*sizeof(int));//allocating array to store numbers
printf("\nenter numbers:");
for(i=0;i<n;i++)
{
scanf("%d",a+i);
}
mergesort(a,0,n-1);//calling function by reference it will do rest of the stuff
for(i=0;i<n;i++)
{
printf("\t%d",*(a+i));
}

}
