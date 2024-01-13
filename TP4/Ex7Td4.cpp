#include <stdio.h>


struct Produit {
    int reference;
    int code;
    float prix;
    int quntite;
};


void saisirProduit(struct Produit *produit) {
    printf("Entrez la reference du produit : ");
    scanf("%d", &produit->reference);

    printf("\t *** Entrez le code du produit *** \n1- pour cartes meres \n2- pour processeurs \n3- pour barrettes memoire \n4- pour cartes graphiques \n\n\t ");
    scanf("%d", &produit->code);

    printf("\nEntrez le prix du produit en DH : ");
    scanf("%f", &produit->prix);

    printf("\nEntrez la quantite disponible du produit : ");
    scanf("%d", &produit->quntite);
}

void afficherProduit(struct Produit produit) {
    printf("Produit avec reference %d :\n", produit.reference);
    printf("Code : %d\n", produit.code);
    printf("Prix : %.2f DH\n", produit.prix);
    printf("Quantite disponible : %d\n", produit.quntite);
}


void saisirCommande(struct Produit *produit) {
    int quantiteCommandee;

    printf("Entrez la quantite commande du produit : ");
    scanf("%d", &quantiteCommandee);

    if (quantiteCommandee > 0 && quantiteCommandee <= produit->quntite) {
        float prixTotal = quantiteCommandee * produit->prix;

        printf("\nCommande du produit :\n");
        printf("Reference du produit : %d\n", produit->reference);
        printf("Code : %d\n", produit->code);
        printf("Prix unitaire : %.2f DH\n", produit->prix);
        printf("Quantité commande : %d\n", quantiteCommandee);
        printf("Prix total de la commande : %.2f DH\n", prixTotal);
    } else {
        printf("\n Quntite commande invalide ou indisponible.\n");
    }
}

int main() {
    struct Produit monProduit;

 
    saisirProduit(&monProduit);


    afficherProduit(monProduit);


    saisirCommande(&monProduit);

    return 0;
}

