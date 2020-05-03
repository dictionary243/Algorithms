#include<stdio.h>
void sort(int m, int x[ ]){
       int i, j, t;
       for(i = 1; i <= m-1; i++)
          for(j = 1; j <= m-i; j++)
             if(x[j-1] >= x[j])
             {
                t = x[j-1];
                x[j-1] = x[j];
                x[j] = t;
             }
}
int main(){
  int index,num,num_of_tracks,flag,initial_head,current_head,seek_count=0,temp,clockwise_rotation=0,countRight=0,countLeft=0,minLeft=2147483647,maxRight=-2147483648;

	printf("\nenter num_of_tracks:");
	scanf("%d",&num_of_tracks);

	printf("\nenter the head:");
	scanf("%d",&current_head);
	initial_head=current_head;

	printf("\nenter how many num u want to enter:");
	scanf("%d",&num);

	int arr_of_number[num],visited_sequence[num],visited[num];

	printf("\nenter numbers:");

	for(int i=0;i<num;i++){
		scanf("%d",&arr_of_number[i]);
		visited[i]=0;
	}
  sort(num,arr_of_number);
  maxRight=arr_of_number[num-1];
  minLeft=arr_of_number[0];
  for(int j=0;j<num;j++){
    if(arr_of_number[j]>initial_head){
          break;
        }
    else{
      countLeft++;
    }
  }
  countRight=num-countLeft;
  printf("%d node is on right %d node is left",countRight,countLeft);
  if(countLeft<countRight){
    clockwise_rotation=1;
  }

  index=(clockwise_rotation)?countLeft:(countLeft-1);
  printf("\nvisiting order:");

  for(int i=0;i<num;i++){
    visited_sequence[i]=arr_of_number[index];
    visited[index]=1;
    if(clockwise_rotation){
      index=(index+1)%num;
    }
    else{
      index=(index==0)?num-1:index-1;
    }
    seek_count+=(clockwise_rotation)?(visited_sequence[i]-current_head):(current_head-visited_sequence[i]);
    current_head=visited_sequence[i];
    if((clockwise_rotation)&&(visited_sequence[i]==maxRight)){
      seek_count+=((num_of_tracks-1)-maxRight);
      seek_count+=(num_of_tracks-1);
      current_head=0;
    }
    if((!clockwise_rotation)&&(visited_sequence[i]==minLeft)){
      seek_count+=minLeft;
      seek_count+=(num_of_tracks-1);
      current_head=num_of_tracks-1;
    }
    printf("\t %d ",visited_sequence[i]);
  }
  printf("\nseek count is %d",seek_count);
}
