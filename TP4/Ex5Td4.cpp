#include <stdio.h>
#include <string.h>


int nb_occurrence(char T[], int n, char c, int *p_occ, int *d_occ) {
    int occurrence = 0;

    *p_occ = -1;
    *d_occ = -1;

    for (int i = 0; i < n; i++) {
        if (T[i] == c) {
            occurrence++;
            if (*p_occ == -1) {
                *p_occ = i;
            }
            *d_occ = i;
        }
    }

    return occurrence;
}

main() {
    char c;
    char T[100];
    int n;


    printf("Entrez la chaine de caracteres : ");
    fgets(T, sizeof(T), stdin);


    printf("Entrez le caractere a rechercher : ");
    scanf(" %c", &c);



   // hadi bch n7eyd le caractere de retour a la ligne
    n = strlen(T) - 1;
    T[n] = '\0'; 

    int p_occurrence, d_occurrence;


    int occurrences = nb_occurrence(T, n, c, &p_occurrence, &d_occurrence);


    printf("Le nombre d occurrences de %c dans la chaine est : %d\n", c, occurrences);
    printf("\n\n");
    printf("Premiere occurrence a l indice : %d\n", p_occurrence);
    printf("Derniere occurrence a l indice : %d\n", d_occurrence);


}

