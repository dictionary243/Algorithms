#include<stdio.h>
#include<conio.h>

long floatfactorial(long float x)
{
if(x==1||x==0)
return 1;
else
return x*factorial(x-1);
}
void main()
{
long float a,b;
clrscr();
printf("\n enter a number of which u want to find out fact:");
scanf("%f",&a);
b=factorial(a);
printf("\n so input was:%f \n output is:%f",a,b);
getch();
}