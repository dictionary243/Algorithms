#include<stdio.h>
#include<conio.h>

int hcf(int a,int b)
{
if(b>a)
return hcf(b,a);
else if(b==0)
return a;
else
return hcf(b,a%b);
}
void main()
{
int x,y,z;
float s;
clrscr();
printf("\n enter 1st num:");
scanf("%d",&x);
printf("\n enter 2nd num:");
scanf("%d",&y);
z=hcf(x,y);
s=(x*y)/z;
printf("\n hcf of %d and %d is %d",x,y,z);
printf("\n lcm of %d and %d is %f",x,y,s);
getch();
}