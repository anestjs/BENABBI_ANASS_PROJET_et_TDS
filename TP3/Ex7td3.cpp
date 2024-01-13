
#include <stdio.h>

int searchvaleur(float tableau[], int taille, float valeur) {
    for (int i = 0; i < taille; ++i) {
        if (tableau[i] == valeur) {
            return i;  
        }
    }
    return -1; 
}

main() {
    int t;
    
    printf("Entrez la taille du tableau : ");
    scanf("%d", &t);

    float tab[t];

    
    for (int i = 0; i < t; ++i) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%f", &tab[i]);
    }

    
    float vch;
    printf("Entrez la valeur a rechercher : ");
    scanf("%f", &vch);

    
    int pos = searchvaleur(tab, t, vch);

    
    if (pos != -1) {
        printf("la position de la valeur est %d \n", vch, pos+1);
    } else {
        printf("valeur n existe pas");
    }

}
