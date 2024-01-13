#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
  int age;
  int sexe;
  
  printf("\n Entrez svp votre age : \n");
  scanf("%d",&age);
  
  printf("\n\t\t Choisissez svp votre sexe : \n *** \n 1-Masculin \n 2-feminin \n");
  scanf("%d",&sexe);
  
  if((sexe == 1 && age > 20) || (sexe = 2 && age >= 18 && age <=35) )
  printf("\n\t\t vous devez payer les impots :) \n");
  else
  printf("\n\t\t vous n'etes pas imposable :( \n");
	
	
	return 0;
}
