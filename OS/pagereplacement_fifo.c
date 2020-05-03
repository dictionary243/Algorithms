#include<stdio.h>
#include<stdlib.h>

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
	int i,size,num,index,pagefault=0;
	printf("\n----------------------------");
	printf("\nenter the stacksize:");
	scanf("%d",&size);
	
	int list[size];

	for(i=0;i<size;i++){
		list[i]=-1;
	}
	
	printf("input the num if it is there it will show hit or it will be miss and enter -1 to break");
	index=0;

	while(243){
		printf("\n----------------------------");
		printf("\nenter num:");
		scanf("%d",&num);
		if(num==-1){
			break;
		}
		else{
			if(ispresent(list,size,num)!=-1){
				printf("\nhit");
			}
			else{
				pagefault++;
				printf("\nmiss");
				list[index]=num;
				//add(list,size,num,index);
				index=(index+1)%size;
			}
			printf("\n----------------------------");
			display(list,size);
		}
	}

	printf("pagefault is %d",pagefault);	

}
