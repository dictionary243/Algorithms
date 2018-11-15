#include<stdio.h>
#include<conio.h>
void tow(int a,char from,char to,char temp)
{
if(a==1)
{
printf("\n move ring 1 from %c to %c",from,to);
}
else
{
tow(a-1,from,temp,to);
printf("\n move ring %d from %c to %c",a,from,to);
tow(a-1,temp,to,from);
}
}
int main()
{
int n;
//lrscr();
printf("\n enter number of rings:");
scanf("%d",&n);
tow(n,'F','T','U');
//getch();
return 0;
}
