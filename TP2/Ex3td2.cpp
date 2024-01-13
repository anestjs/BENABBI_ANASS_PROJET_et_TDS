
#include <stdio.h>

int iNb_jours[13];  


void init_iNb_jours() {
    int i;

    for (i = 1; i <= 12; i++) {
        if (i == 2)
            iNb_jours[i] = 28;
        else if ((i % 2 == 0 && i <= 7) || (i % 2 != 0 && i > 7))
              iNb_jours[i] = 30;
        else
              iNb_jours[i] = 31;
    }
}


void imp_iNb_jours() {
    int i;
    for (i = 1; i <= 12; i++) {
        printf("mois [ %d ] --> %d jour \n", i, iNb_jours[i]);
    }
}

void imp_nb_jours_mois(int mois) {
    if (mois >= 1 && mois <= 12) {
        printf("mois [ %d ] --> %d jour \n", mois, iNb_jours[mois]);
    } else {
        printf("invalide \n");
    }
}

main() {
	
    init_iNb_jours();
    imp_iNb_jours();
    
    
      int mois;
      printf("\n Choisir un mois >");
    scanf("%d", &mois);
    imp_nb_jours_mois(mois);

 
}

