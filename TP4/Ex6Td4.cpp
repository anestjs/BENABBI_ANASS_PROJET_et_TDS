#include <stdio.h>


struct Panneau {
    int largeur;
    int longueur;
    int epaisseur;
    int typeBois;
};


void saisirPanneau(struct Panneau *panneau) {
    printf("Entrez la largeur du panneau  : ");
    scanf("%d", &panneau->largeur);

    printf("Entrez la longueur du panneau  : ");
    scanf("%d", &panneau->longueur);

    printf("Entrez l'epaisseur du panneau  : ");
    scanf("%d", &panneau->epaisseur);

    printf("Entrez le type de bois (0 pour Pin, 1 pour chene, 2 pour hetre) : ");
    scanf("%d", &panneau->typeBois);
}


void afficherPanneau(struct Panneau panneau) {
    printf("Panneau de bois :\n");
    printf("Largeur : %d mm\n", panneau.largeur);
    printf("Longueur : %d mm\n", panneau.longueur);
    printf("Epaisseur : %d mm\n", panneau.epaisseur);


    switch (panneau.typeBois) {
        case 0:
            printf("Type de bois : Pin\n");
            break;
        case 1:
            printf("Type de bois : Chene\n");
            break;
        case 2:
            printf("Type de bois : Hetre\n");
            break;
        default:
            printf("Type de bois inconnu\n");
    }
}


double calculerVolume(struct Panneau panneau) {
  
    double volume = (panneau.largeur/1000) * (panneau.longueur/1000) * (panneau.epaisseur/1000);
    return volume;
}

main() {

    struct Panneau monPanneau;

    saisirPanneau(&monPanneau);

    afficherPanneau(monPanneau);


    double volume = calculerVolume(monPanneau);
    printf("Le volume du panneau est : %.3f \n", volume);

 
}

