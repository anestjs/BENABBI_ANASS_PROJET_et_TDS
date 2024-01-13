#include <stdio.h>

main() {
	// formalisme usell de tableau
    float t[3][4] = {{1.8, 2.5, 3.4, 4.2}, {5.1, 6.8, 7.1, 8.0}, {9.1, 10.2, 11.9, 12.0}};

    float s = 0.0;
    int i,j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            s += t[i][j];
        }
    }

    printf("*** La somme de T  : [ %.2f ]\n", s);


}

