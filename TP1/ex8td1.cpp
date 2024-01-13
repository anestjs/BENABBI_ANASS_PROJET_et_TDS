#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
	for(int i = 1; i<= 6;i++)
	{
			printf("\n");
		for(int j=6-i+1;j>=1;j--)
		{
			printf("%d",j);
		}
	}
	
	printf("\n");
	printf("\n");

   for(int i = 0; i<=9;i++)
   {
   	printf("\n");
   	
   	
   	 for(int j =0;j<=i;j++)
     {
     printf(" ");
	 }

   	 
     for(int j = 9-i+1;j>=1;j--)
     {
     	printf("%d",i);
	 }
   }
   
   
}



