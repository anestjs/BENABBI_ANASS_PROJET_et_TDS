#include <stdio.h>

int main() {
    char ch;
    int chiffres = 0, espacements = 0, autres = 0;

    printf("Entrez la chaine ( enter --> FIN ) :\n");

    while ((ch = getchar()) != '\n') {
        if (ch >= '0' && ch <= '9') {
            chiffres++;
        } else if (ch == ' ' || ch == '\n' || ch == '\t' ) {  
            espacements++;
        } else {
            autres++;
        }
    }

    printf("Chiffres: [ %d ]\nEspacements: [ %d ] \nAutres: [ %d ]\n", chiffres, espacements, autres);

    return 0;
}
