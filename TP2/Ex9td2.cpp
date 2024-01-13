#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void saisir(char *ch){
    printf("\nSaisir la chaine : ");
    scanf(" %[^\n]", ch);   // pour saisir les espaces aussi
}
void afficher(const char *ch){
    puts(ch);
}
void inverse(char *ch){
    int len = strlen(ch)  , i , j ;
    char tmp ;
    for ( i=0 , j=len-1 ; i<j ; i++,j--){
        tmp = ch[i] ;
        ch[i] = ch[j];
        ch[j] = tmp ;
    }
}
void nbre_mots(const char *ch){
    int len = strlen(ch) ;
    int i , compteur = 0 ;
    for(i=0;i<len;i++){
        if(ch[i] ==' ')
            compteur = compteur + 1 ;
    }
    compteur = compteur + 1 ;
    printf("Le nombre de mots est %d" , compteur);
}
main(){
    int choix ;
    char chaine[100]="";

    while(1){
    printf("\n1- Saisir \n");
    printf("\n2- Afficher \n");
    printf("\n3- Afficher l'inverse \n");
    printf("\n4- Le nombre de mots \n");
    printf("\n5- Quitter\n");
    printf("\n");
    printf("\n\tchoix > ");
    
    scanf("%d",&choix);
    printf("\n");
    
        switch (choix)
        {
        case 1 :
            saisir(chaine);
            break;
        case 2 :
        	printf("\n***********************************************\n");
            afficher(chaine);
            printf("\n***********************************************\n");
            break ;
        case 3 :
            inverse(chaine);
            printf("\n***********************************************\n");
            afficher(chaine);
            	printf("\n***********************************************\n");
            break ;
        case 4 :
        		printf("\n***********************************************\n");
            nbre_mots(chaine);
            	printf("\n***********************************************\n");
            break;
        case 5 :
            exit(0) ;
        default:
            break;
        }
    }

}
