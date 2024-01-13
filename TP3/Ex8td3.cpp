#include <stdio.h>

void RLE(int tab[], int t) {
    int i = 0;
   printf("\n\n [ ");
    while (i < t) {
        int c = 1;
        while (i < t - 1 && tab[i] == tab[i + 1]) {
            ++c;
            ++i;
        }
        printf("%d%d", c, tab[i]);
        ++i;
    }
    printf(" ]\n");
}

main() {
   
    int tab[] = {4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0};
    int t = sizeof(tab) / sizeof(tab[0]);

    printf("\t*** Tableau ***\n");
    for (int i = 0; i < t; ++i) {
        printf("%d ", tab[i]);
    }
    printf("\n\n\n");

    printf("\t*** Apres RLE ***");
    RLE(tab, t);

}
