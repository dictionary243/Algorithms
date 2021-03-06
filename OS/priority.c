#include<stdio.h>
#include<stdlib.h>

int valid_index(int start,int end,int *bt,int *flag,int *at,int *priority,int tt){
	int min=0,i=start,index=-1;
	for(i=start;i<(end+1);i++){
		if(index!=-1){
		if((priority[i]==min)&&(flag[i]==0)&&(bt[i]<bt[index])&&(tt>=at[i])){
		//	printf("/nloop1 in valid_index");
			min=priority[i];
			index=i;
			}}
	if((priority[i]>min)&&(flag[i]==0)&&(tt>=at[i])){
		//	printf("/nloop2 in valid_index");
			min=priority[i];
			index=i;
			}

	}
	return index;
}

int condition(int *flag,int n){
	int i,temp=1;
	for(i=0;i<n;i++){
		if(flag[i]==0){
		temp=0;
		break;	}
	}
	return temp;
}
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
	int n;
	printf("\n----------------------------");
	printf("\nenter number of processes:");
	scanf("%d",&n);

	int at[n],bt[n],sort_at[n],btc[n],ct[n],tat[n],wt[n],j=0,i,tt,flag[n],priority[n];
	float avg_tat=0,avg_wt=0;

	for(i=0;i<n;i++){
//		at[i]=i;
//		bt[i]=0;
		ct[i]=0;
		tat[i]=0;
		wt[i]=0;
		flag[i]=0;
	}

	for(i=0;i<n;i++){
		printf("----------------------------");
    printf("\nfor process %d:",(i+1));
		printf("\n----------------------------");
		printf("\nenter at :");
		scanf("%d",&at[i]);
		sort_at[i]=at[i];
		printf("\nenter bt :");
		scanf("%d",&bt[i]);
		printf("\nenter priority :");
		scanf("%d",&priority[i]);
	}
	sort(n,sort_at);
	printf("\n----------------------------");
	tt=sort_at[0];
	pntf("\nqueue of processes in ready queue:");

	while(243){
			tt=(sort_at[j])>tt?sort_at[j]:tt;
			printf("   p%d",(i+1));
			i=valid_index(0,n-1,bt,flag,at,priority,tt);
			flag[i]=1;
			tt+=bt[i];
			ct[i]=tt;
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			if(condition(flag,n)){
				break;
			}
			j++;
	}

	printf("\n------------------------------------------------");
	printf("\nat	bt	priority	ct      tat     wt");

	for(i=0;i<n;i++){
		avg_tat+=(float)tat[i];
		avg_wt+=(float)wt[i];
		printf("\n%d	%d	%d		%d	%d	%d",at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
		printf("\n------------------------------------------------");
	}

	avg_tat=avg_tat/(float)n;
	avg_wt/=(float)n;
	printf("\n----------------------------");
	printf("\navg tat is :%f \navg bt is :%f \nthroughput is :%f",avg_tat,avg_wt,((float)n)/tt);
	printf("\n----------------------------");


}
