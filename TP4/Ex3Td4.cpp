#include <stdio.h>


struct etudiant {
    char nom[15], prenom[15];
    int CNE;
    float notes[4], moyenne;
};


void saisirEtudiant(struct etudiant *etud) {
    printf("Nom : ");
    scanf("%s", etud->nom);

    printf("Prenom : ");
    scanf("%s", etud->prenom);

    printf("CNE : ");
    scanf("%d", &etud->CNE);

    printf("Notes (4 notes) : ");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &etud->notes[i]);
    }
}


void afficherEtudiant(struct etudiant etud) {
    printf("Nom : %s\n", etud.nom);
    printf("Prenom : %s\n", etud.prenom);
    printf("CNE : %d\n", etud.CNE);
    printf("Notes : %.2f %.2f %.2f %.2f\n", etud.notes[0], etud.notes[1], etud.notes[2], etud.notes[3]);
    printf("Moyenne : %.2f\n", etud.moyenne);
    printf("\n");
}


struct etudiant trouverMeilleurEtudiant(struct etudiant T[], int taille) {
    struct etudiant meilleurEtudiant = T[0];

    for (int i = 1; i < taille; i++) {
        if (T[i].moyenne > meilleurEtudiant.moyenne) {
            meilleurEtudiant = T[i];
        }
    }

    return meilleurEtudiant;
}




void echanger(struct etudiant *a, struct etudiant *b) {
    struct etudiant temp = *a;
    *a = *b;
    *b = temp;
}


void trie(struct etudiant T[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (T[j].moyenne < T[j + 1].moyenne) {
                echanger(&T[j], &T[j + 1]);
            }
        }
    }
}



main() {

    struct etudiant T[5];


    for (int i = 0; i < 5; i++) {
        printf("Saisie des informations pour l'etudiant %d :\n", i + 1);
        saisirEtudiant(&T[i]);
    }

  
    for (int i = 0; i < 5; i++) {
        float somme = 0;
        for (int j = 0; j < 4; j++) {
            somme += T[i].notes[j];
        }
        T[i].moyenne = somme / 4.0;
    }

 
    struct etudiant meilleurEtudiant = trouverMeilleurEtudiant(T, 5);
    printf("Informations pour l'etudiant avec la plus grande moyenne :\n");
    afficherEtudiant(meilleurEtudiant);


    trie(T, 5);


    printf("Tableau d'etudiants trie en ordre decroissant selon la moyenne :\n");
    for (int i = 0; i < 5; i++) {
        afficherEtudiant(T[i]);
    }


}

