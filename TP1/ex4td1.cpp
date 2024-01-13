#include <stdio.h>

 main() {
    
    float prixInitial, remise, prixFinal;

    
    printf("Entrez le prix initial du produit en DH : ");
    scanf("%f", &prixInitial);


    if (prixInitial < 100) {
        remise = prixInitial * 0.3;
    } else if (prixInitial >= 100 && prixInitial <= 200) {
        remise = prixInitial * 0.4;
    } else {
        remise = prixInitial * 0.5;
    }

    prixFinal = prixInitial - remise;

  
    printf("\n\n\n*** prix initial : %.2f Dh \n", prixInitial);
    printf(":) remise : %.2f Dh \n\n", remise);
    printf("\t[ Prix final : %.2f Dh ]\n", prixFinal);

 
}

