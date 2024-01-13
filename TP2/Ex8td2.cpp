#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void saisi(char *nom){

    printf("Entrez Nom ? \n");
    scanf("%s" , nom);
}

int main(){
    char nom[20] ;
    int nbre = 0 ;
    do{
        saisi(nom);
        int len = strlen(nom);
        if(len>10)
        nbre++;
    } while(strcmp(nom,"fin")!=0);

    printf("Nombre des nom avec + de 10 caractere %d" , nbre ) ;
}
