#include<stdio.h>

int valid_index(int head,int num,int *arr_of_number,int *visited){
	int i=0,closest=2147483647,index=-1,dist1,value,dist2,onLeft;
	dist1=closest-head;
	for(i=0;i<num;i++){
		onLeft=0;
		value=arr_of_number[i];
		dist2=value-head;
		if(dist2<0){
			onLeft=1;
			dist2=head-value;
		}
		if((dist2<dist1)&&(visited[i]==0)){
			dist1=dist2;
			index=i;
			closest=value;
		}
		if((dist2==dist1)&&(visited[i]==0)&&(onLeft==0)){
			index=i;
			closest=value;
		}
	}
	return index;

}


int main(){
	int index,num,num_of_tracks,initial_head,current_head,count=0,seek_count=0,temp;

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

	for(int i=0;i<num;i++){
		index=valid_index(current_head,num,arr_of_number,visited);
		current_head=arr_of_number[index];
		visited_sequence[count++]=arr_of_number[index];
		visited[index]=1;
	}
	printf("\nvisiting order:");

	for(int i=0;i<num;i++){
			if(i==0){
				temp=visited_sequence[i]-initial_head;
			}
			else{
				temp=visited_sequence[i]-visited_sequence[i-1];
			}
			if(temp<0){
				temp*=-1;
			}
			printf("\t %d",visited_sequence[i]);
			seek_count+=temp;
	}
	printf("\nseek count is %d",seek_count);
}
