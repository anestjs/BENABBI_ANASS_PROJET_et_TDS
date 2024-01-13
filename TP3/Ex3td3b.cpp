#include <stdio.h>

int main() {
	// formalisme des pointeur 
  float t[3][4] = {{1.8, 2.5, 3.4, 4.2}, {5.1, 6.8, 7.1, 8.0}, {9.1, 10.2, 11.9, 12.0}};
    float s = 0.0;
    float *p = &t[0][0];
    
    int i;

    for (i = 0; i < 3 * 4; i++) {
        s += *(p + i);
    }

    printf("La somme de T est : [ %.2f ]\n", s);

    return 0;
}
