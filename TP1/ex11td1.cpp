#include <stdio.h>

 main() {
    int entier = 0;
    int choix;

    do {
        printf("La valeur actuelle de l entier est : %d\n", entier);

        printf("Menu :\n");
        printf("1. Ajouter 2\n");
        printf("2. Multiplier par 3\n");
        printf("3. Soustraire 5\n");
        printf("4. Quitter\n");


printf("\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                entier += 2;
                break;
            case 2:
                entier *= 3;
                break;
            case 3:
                entier -= 5;
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide :( \n");
        }
        
        
        
        printf("\n\n");


    } while (choix != 4);

 
}

