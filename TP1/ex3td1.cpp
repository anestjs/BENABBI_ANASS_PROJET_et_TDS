#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
   
    int nombrePhotocopies;
    float facture = 0;

   
    printf("Entrez le nombre de photocopies : ");
    scanf("%d", &nombrePhotocopies);

 
    if (nombrePhotocopies <= 10) {
        facture = nombrePhotocopies * 1.0; 
    } else if (nombrePhotocopies <= 30) {
        facture = 10 * 1.0 + (nombrePhotocopies - 10) * 0.6; 
    } else {
        facture = 10 * 1.0 + 20 * 0.6 + (nombrePhotocopies - 30) * 0.4; 
    }

   
    printf("La facture pour %d photocopies est de : %.2f DH\n", nombrePhotocopies, facture);

    return 0;
}



