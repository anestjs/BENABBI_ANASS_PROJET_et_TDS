#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
	float a,b,s;
	char c;
	
    
	printf("Donner un nombre a et b \n");
	scanf("%f%f",&a,&b);
                 
	printf("\nDonner  operateur Arithmitique \n");
	getchar();
    scanf("%c",&c); 
                          
		                   
	switch (c)  
	{
		case '+' : s = a+b; 
		 printf("le resultat de %.2f + %.2f est :%.2f",a,b,s);
	
		  
		 break;
		case '*' : s = a*b;
		 printf("le resultat de %.2f * %.2f est :%.2f",a,b,s);
		 break;
		 
		case '/' : s = a/b;
		 printf("le resultat de %.2f / %.2f est :%.2f",a,b,s);
		 break;
		 
		case '-' : s = a-b;
		 printf("le resultat de %.2f - %.2f est :%.2f",a,b,s);
		 break;
		 
		 
		default : printf("\nsvp entrez un operateur arithmetique valide :(\n");
	
 	  }  
 	  
		    
		     
		  
    
  
	
	return 0;
}
