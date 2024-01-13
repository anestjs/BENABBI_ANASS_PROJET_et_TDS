#include <stdio.h>
#include <stdlib.h>

 main() {
 
    int nombre, cpaire = 0;
    int * paires;
	
	paires = (int *) malloc(sizeof(int)*cpaire);

    
    for (int i = 1; i <= 20; ++i) {
    
        printf("Entrez le nombre %d : ", i);
        scanf("%d", &nombre);

        if (nombre % 2 == 0) {
         
            paires[cpaire] = nombre;
            cpaire++;
        }
    }
    
    
    printf("Nombre total d'entrees : 20\n");
    printf("Nombre d'entrees paires : %d\n", cpaire);
    
    printf("\n\n");
    
    printf("Les carree des nombres paires entree : \n");
    
   for ( int i = 0; i< cpaire;i++)
   {
   	printf("[ %d ]\t",paires[i]*paires[i]);
  
   }


}

