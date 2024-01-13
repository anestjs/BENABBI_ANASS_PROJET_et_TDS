#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Nmax 20


int i ;


void saisie(int Tab[] , int n){
        for(i=0 ; i<n ; i++){
            printf("element  %d ",i+1);
            scanf("%d",&Tab[i]);
        }
}

void affichage(int Tab[] , int n){
    printf("tableau : \n");
    for(i =0 ; i<n ; i++){
        printf("N %d = %d\n",i+1,Tab[i]);
    }
}

void moyenne(int Tab[] , int n){
    int s = 0 ;
    float moy ;

    for(i=0;i<n;i++){
        s += Tab[i] ;
    }
    moy = s / n ;
    printf("\n moyenne est %.2f \n",moyenne);
}

int max_element(int Tab[] , int n){
    int max = 0 , pos =0 ;
    for (i=0;i<n;i++){
        if(max<Tab[i]){
            max = Tab[i];
            pos = i ;
        }
    }
    return pos ;
}
int supp_max(int Tab[] , int n , int pos){
    for(i=pos;i<n;i++){
        Tab[i]=Tab[i+1];
    }
    n = n - 1 ;
    return  n ;
}
int min_element(int Tab[] , int n){
    int min = Tab[0] , pos =0 ;
    for (i=0;i<n;i++){
        if(min>Tab[i]){
            min = Tab[i];
            pos = i ;
        }
    }
    return pos ;
}
int supp_min(int Tab[] , int n , int pos){
    for(i=pos;i<n;i++){
        Tab[i]=Tab[i+1];
    }
    n = n - 1 ;
    return n ;
}

void ajout(int Tab[] , int n ){
    int val , pos , temp ;
    printf("Entrez la valeur a inserer ");
    scanf("%d" , &val);
    printf("Entrez la position ou inserer ");
    scanf("%d" , &pos) ;
    pos = pos - 1 ;

    for(i=pos ; i<n ;i++){
        temp = Tab[i] ;
        Tab[i] = val ;
        val = Tab[i+1];
    }
}

main(){
    int Tab[Nmax];
    int NE , pmax ,pmin;
    
    char choix ;



    while(1){
    	
    printf("\na- saisie et affichage. \n");
    printf("b- moyenne. \n");
    printf("c- suppression du Max et affichage. \n");
    printf("d- suppression du Min et affichage. \n");
    printf("e- ajout d'un entier a une position donnee. \n");
    printf("q- quitter. \n\n");
 
    scanf(" %c",&choix);
     
        switch (choix){

        case 'A' :
          case 'a':

            printf("Saisir le nombre d'elements a inserer : ");
            scanf("%d",&NE);
            if(NE>Nmax){
                printf("Saisir un nombre inferieur a 20");
            }else{
                saisie(Tab,NE) ;
                printf("\n\n");
                affichage(Tab,NE);
            }
            break;
        case 'B' :
          case 'b' :
            moyenne(Tab,NE);
            break ;
        case 'C' :
            case 'c' :
            pmax = max_element(Tab,NE);
            NE = supp_max(Tab,NE,pmax);
            affichage(Tab,NE);
            break ;
        case 'D' :
            case 'd' :
            pmin = min_element(Tab,NE);
            printf("min pos %d",pmin);
            NE = supp_min(Tab,NE,pmin);
            affichage(Tab,NE);
            break ;
        case 'E' :
            case 'e' :
            ajout(Tab , NE) ;
            affichage(Tab,NE);
            break ;
        case 'Q' :
            case 'q' :
    
            break ;
        default : printf("default");
    }

    }

}
