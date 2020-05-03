#include<stdio.h>
#include<stdlib.h>
int *visited,n,*queue;
int front=-1,rear=-1;
void insert(int *q,int value)
{
  if(rear<n-1)
  {
    q[++rear]=value;
  }
  if(front==-1)
  front++;
}
void visitdfs(int **adjmatrix,int i)
{
  int j;
  if(!visited[i])
  {
    printf("\t%d",i);
    visited[i]++;
  }
  for(j=0;j<n;j++)
  {
    if(adjmatrix[i][j]==1&!visited[j])
    {
      insert(queue,j);
    }
  }
}
void bfs(int **matrix,int key)
{
  int i=0;
  insert(queue,key);
  do {
    printf("%d",queue[i]);
    visitdfs(matrix,queue[i]);
    i++;
  } while(rear!=n);
}
void main()
{
  int i,j;
  int **matrix;
  printf("%d how many numbers of vertex are there:");
  scanf("%d",&n);
  visited=(int *)malloc(n*sizeof(int));
  queue=(int *)malloc(n*sizeof(int));
  matrix=(int **)malloc(sizeof(int *)*n+sizeof(int)*n* n);
  //*matrix=(int *)malloc(n*sizeof(int));
  printf("enter adj matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&matrix[i][j]);
    }
    visited[i]=0;
  }
  printf("enter from which key u want to traversal:");
  scanf("%d",&i);
  bfs(matrix,i);
}
