#include <stdio.h>



int long_chain(char tableau[]) {
    int longueur = 0;

  
    while (tableau[longueur] != '\0') {
        longueur++;
    }

    return longueur;
}

main() {
 
 char cTab1[] = "I am Anas";
 char cTab2[] = "Anas is who am i";

    printf("nbre elts de ctab1 --> [ %d ]\n", long_chain(cTab1));
    printf("nbre elts de ctab1 --> [ %d ]\n", long_chain(cTab2));


}


