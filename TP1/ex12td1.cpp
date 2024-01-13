#include <stdio.h>

 main() {

int L;
int i ,j;

printf("Veuillez saisir le nombre de lignes: "); 
scanf("%d", &L);

for(i=1;i<=L;i++) {
	for(j=1;j<=L;j++) {
      if(i==1 || j==1 || i==L || j==L )
         printf(" *");
    else if ( i == (L+1)/2 && j != (L+1)/2)
    printf(" |");
    
     else if (j == (L+1)/2 && i != (L+1)/2)
    printf(" -");
    
     else if ( i == (L+1)/2 && j == (L+1)/2)
    printf(" +");
    
    
    else if ( i==j || j==L-i+1)
    printf(" +");
       else
         printf("  ");	
}
printf("\n");
} 


}

