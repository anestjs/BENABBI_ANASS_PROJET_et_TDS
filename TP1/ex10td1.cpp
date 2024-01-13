#include<stdio.h>

main() {
    int n; 
    printf("Entrer  n : ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {

            if (i == n - 1 || j == n - 1 - i || j == n - 1 + i) {
                printf("*");
            } else {

                printf(" ");
            }
        }

        printf("\n");
    }


}

