#include <stdio.h>


main() {

    int nombre, totalValeurs = 0, somme = 0, minimum = 999999;
    int sommePositives = 0, minimumPositives;

 
    do {
      
        printf("entrez un nombre entier ( 999 pour terminer ) : ");
        scanf("%d", &nombre);

        if (nombre != 999) {
       
            totalValeurs++;
            somme += nombre;

            if (nombre < minimum) {
                minimum = nombre;
            }

        
            if (nombre > 0) {
                sommePositives += nombre;

                if (nombre < minimumPositives) {
                    minimumPositives = nombre;
                }
            }
        }

    } while (nombre != 999);

    printf("\n\n\n");

    printf("Le nombre total de valeurs de la suite : %d\n", totalValeurs);
    printf("La somme des valeurs lues : %d\n", somme);
    printf("Le minimum : %d\n", minimum);
    printf("La somme des valeurs strictement positives : %d\n", sommePositives);

    if (sommePositives > 0) {
        printf("Le minimum des valeurs strictement positives : %d\n", minimumPositives);
    } else {
        printf("Il n y a pas de valeurs strictement positives \n");
    }


}

