#include <stdio.h>

int main()
{
   long max = -1000000,sum =0 ;
   long n,i;
   int data;
   while((scanf("%ld",&n))!= EOF) 
   {
   max = -1000000;
   sum =0 ;
   for(i=1 ; i<= n ; i++)
   {
   scanf("%d",&data);
   if(sum >= 0)
   sum += data ;
   else
   sum = data ;
   if(sum > max)
   max = sum ;
   }
   printf("%ld\n",max);
   }
   return 0 ;
}
