#include <stdio.h>

 main() {

    int num;
    int estPremier = 1;  

  
    printf("Entrez un nombre entier : ");
    scanf("%d", &num);

 
    if (num == 1) {
        printf("%d n'est pas un nombre premier.\n", num);
    } 
	else {
    
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                estPremier = 0; 
                break;
            }
        }

        if (estPremier) {
            printf("%d est un nombre premier.\n", num);
        } else {
            printf("%d n'est pas un nombre premier.\n", num);
        }
    }


}

