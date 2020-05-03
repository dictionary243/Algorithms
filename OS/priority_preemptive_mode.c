#include<stdio.h>
#include<stdlib.h>

int valid_index(int start,int end,int *btc,int *flag,int *at,int *priority,int tt){
	int min=0,i=start,index=-1;
	for(i=start;i<(end+1);i++){
		if(index!=-1){
            if((priority[i]==min)&&(flag[i]==0)&&(btc[i]<btc[index])&&(tt>=at[i])){
                min=priority[i];
                index=i;
                }
			}
        if((priority[i]>min)&&(flag[i]==0)&&(tt>=at[i])){
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
            break;
		}
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

	int at[n],sort_at[n],bt[n],btc[n],ct[n],tat[n],wt[n],i,j=0,tt,flag[n],priority[n];
	float avg_tat=0,avg_wt=0;

	for(i=0;i<n;i++){
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
		btc[i]=bt[i];
		printf("\nenter priority :");
		scanf("%d",&priority[i]);
	}

	sort(n,sort_at);
	printf("\n----------------------------");
	tt=sort_at[0];
	printf("\nqueue of processes in ready queue:");

	while(243){
			tt=(sort_at[j])>tt?sort_at[j]:tt;
			i=valid_index(0,n-1,btc,flag,at,priority,tt);
			tt++;
			printf(" p%d",(i+1));

			if(btc[i]==1){
                flag[i]=1;
                ct[i]=tt;
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
								j++;
			}

			btc[i]--;
			if(condition(flag,n)){
				break;
				}

	}

    	printf("\n--------------------------------------------");
	printf("\nat    bt      priority    ct      tat     wt");

	for(i=0;i<n;i++){

		avg_tat+=(float)tat[i];
        	avg_wt+=(float)wt[i];
        	printf("\n--------------------------------------------");
        	printf("\n%d	%d	%d	   %d	    %d	    %d",at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);

	}

	avg_tat=avg_tat/(float)n;
	avg_wt/=(float)n;
	printf("\n----------------------------");
	printf("\navg tat is :%f \navg bt is :%f \nthroughput is :%f",avg_tat,avg_wt,((float)n)/tt);
	printf("\n----------------------------");

}
