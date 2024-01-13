#include <stdio.h>



void aff_mat(int matr[5][5]) {
    int i, j, c;

    printf("\n\t *** MATRICE ***\n\n");

    for (i = 0; i < 5; i++) {
        if (i == 0) {
            for (c = 1; c <= 5; c++)
                printf("[ %d ]  ", c);
          printf("\n");
        }

        for (j = 0; j < 5; j++) {
            printf("[ %d ]  ", matr[i][j]);
            if (j == 5 - 1) {
                        printf("\n");
            }
        }
    }
}

int main() {
    int matr[5][5] = {
        {11, 12, 13, 14, 15},{21, 22, 23, 24, 25},{31, 32, 33, 34, 35},{41, 42, 43, 44, 45},{51, 52, 53, 54, 55}
    };

    aff_mat(matr);

}
