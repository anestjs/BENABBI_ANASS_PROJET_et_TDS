#include <stdio.h>

main() {
    int nombre;

   
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);

   
    if (nombre % 2 == 0) {

        printf("Nombres pairs inferieurs a %d :\n", nombre);


        for (int i = nombre - 2; i > 0; i -= 2) {
            printf("%d ", i);
        }

        printf("\n");
    } else {

        printf("%d n est pas un nombre pair.\n", nombre);
    }


}
