#include <stdio.h>

#define MAX_CONTACTS 50


struct Contact {
    char nom[30];
    char prenom[30];
    char telephone[15];
};


void saisirContact(struct Contact *contact) {
    printf("Nom : ");
    scanf("%s", contact->nom);

    printf("Prenom : ");
    scanf("%s", contact->prenom);

    printf("Telephone : ");
    scanf("%s", contact->telephone);
}


void afficherRepertoire(struct Contact repertoire[], int taille) {
    printf("\n \t*** Repertoire ***:\n");
    for (int i = 0; i < taille; i++) {
        printf("Contact %d :\n", i + 1);
        printf("Nom : %s\n", repertoire[i].nom);
        printf("Prénom : %s\n", repertoire[i].prenom);
        printf("Téléphone : %s\n", repertoire[i].telephone);
        printf("\n");
    }
}

main() {
    struct Contact repertoire[MAX_CONTACTS];
    int nbContacts;

    printf("Combien de contacts vous voulue saisir ? : ");
    scanf("%d", &nbContacts);



    for (int i = 0; i < nbContacts; i++) {
        printf("\n \t*** Saisie des informations pour le contact %d *** \n ", i + 1);
        saisirContact(&repertoire[i]);
    }


    afficherRepertoire(repertoire, nbContacts);


}

