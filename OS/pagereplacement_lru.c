#include<stdio.h>
#include<stdlib.h>
int extract_max(int *arr,int size){
	int i,valid_index=0;
	for(i=0;i<size;i++){
		if(arr[i]==-1){
			valid_index=i;
			break;		
		}
		if(arr[valid_index]<arr[i]){
			valid_index=i;
		}
	}
	return valid_index;
}

void update_lru(int *arr,int size){

	int i=0;

	for(i=0;i<size;i++){
		if(arr[i]!=-1){
			arr[i]++;
		}
	}	
}

int ispresent(int *arr,int size,int number){
	int i,flag=-1;
	for(i=0;i<size;i++){
		if(arr[i]==number){
			flag=i;
			break;		
		}		
	}
	return flag;
}
void display(int *arr,int size){
	int i=0;
	printf("\n list ");
	printf("\n------");
	
	for(i=size-1;i>-1;i--){
		if(arr[i]==-1){
			printf("\n|  --  |");
		}
		else{
			printf("\n| %d 	|",arr[i]);			
		}		
	}
}

int main(){
	int i,size,num,index,pagefault=0,valid_index;
	printf("\n----------------------------");
	printf("\nenter number of stacksize:");
	scanf("%d",&size);
	
	int list[size],lru[size];

	for(i=0;i<size;i++){
		list[i]=-1;
		lru[i]=-1;
	}
	
	printf("input the num if it is there it will show hit or it will be miss and enter -1 to break");
	
	
	while(243){
		printf("\n----------------------------");
		printf("\nenter num:");
		scanf("%d",&num);
		if(num==-1){
			break;
		}
		else{
			index=ispresent(list,size,num);
			if(index!=-1){
				update_lru(lru,size);
				lru[index]=0;	
				printf("\nhit");
					
			}
			else{
				pagefault++;
				printf("\nmiss");
				valid_index=extract_max(lru,size);				
				list[valid_index]=num;
				update_lru(lru,size);
				lru[valid_index]=0;	
				
			}
			printf("\n----------------------------");
			display(list,size);
		}
	}

	printf("pagefault is %d",pagefault);	

}
