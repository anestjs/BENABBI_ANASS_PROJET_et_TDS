
#include <stdio.h>
#include <stdlib.h>


int Pal(char *chaine) {
   
    int Long = 0;
    while (chaine[Long] != '\0') {
        Long++;
    }

    char *D = chaine;
    char *F = chaine + Long - 1;

    while (D < F) {
        if (*D != *F) {
            return 0; 
        }

        D++;
        F--;
    }

    return 1;
}


main() {
    char chaine[30];

    printf("Entrez une chaine >\t");
    scanf("%s", chaine);
    
    printf("\t *** RESULTAT ***");

    if (Pal(chaine)) {
        printf("[ %s ] est  palindrom :)\n", chaine);
    } else {
        printf("[ %s ] n'est pas palindrom :(\n", chaine);
    }
}

