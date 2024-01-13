#include <stdio.h>

struct date {
    int jour;
    char mois[10];
    int annee;
};

struct employe {
    char nom[15], prenom[15];
    struct date date_naissance, date_embauche;
};

void afficherEmploye(struct employe emp) {
    printf("Nom: %s\n", emp.nom);
    printf("Prenom: %s\n", emp.prenom);
    printf("Date de naissance: %d %s %d\n", emp.date_naissance.jour, emp.date_naissance.mois, emp.date_naissance.annee);
    printf("Date d'embauche: %d %s %d\n", emp.date_embauche.jour, emp.date_embauche.mois, emp.date_embauche.annee);
    printf("\n");
}

 main() {
    struct employe employes[4];

    
    for (int i = 0; i < 4; i++) {
        printf("Saisie des informations pour l'employé %d:\n", i + 1);
        
        printf("Nom : ");
        scanf("%s", employes[i].nom);
        
        printf("Prenom : ");
        scanf("%s", employes[i].prenom);

        printf("Date de naissance (jour mois annee) : ");
        scanf("%d %s %d", &employes[i].date_naissance.jour, employes[i].date_naissance.mois, &employes[i].date_naissance.annee);

        printf("Date d'embauche (jour mois annee) : ");
        scanf("%d %s %d", &employes[i].date_embauche.jour, employes[i].date_embauche.mois, &employes[i].date_embauche.annee);

        printf("\n");
    }


    for (int i = 0; i < 4; i++) {
        printf("Informations pour l'employé %d:\n", i + 1);
        afficherEmploye(employes[i]);
    }


}

