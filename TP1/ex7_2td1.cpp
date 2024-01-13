#include <stdio.h>
#include <stdlib.h>

 main() {
 
    int nombre, cpaire = 0,ptotal = 0,ntotal = 0;
    int * paires;
	
	paires = (int *) malloc(sizeof(int)*cpaire);

    do
      {
        printf("Entrez Un nombre ( 100 pour s arreter ) : ");
        scanf("%d", &nombre);

        if (nombre % 2 == 0 && nombre !=100) {
         
            paires[cpaire] = nombre;
            cpaire++;
        }
        if(nombre !=100)
        {
        	ntotal++;
		}
        
    }while (nombre != 100);
    
    printf("\n\n");
    
    
    printf("Nombre total d'entrees : %d\n",ntotal);
    printf("Nombre d'entrees paires : %d\n", cpaire);
   
    
    
    printf("\n\n");
    
    printf("Les carree des nombres paires entree : \n");
    
   for ( int i = 0; i< cpaire;i++)
   {
   	printf("[ %d ]\t",paires[i]*paires[i]);
  
   }


}

