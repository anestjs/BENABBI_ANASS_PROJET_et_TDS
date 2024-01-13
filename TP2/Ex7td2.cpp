#include <stdio.h>

int addition(int A, int B) {
     return A + B;
}

int soustraction(int A, int B) {
       return A - B;
}

int multiplication(int A, int B) {
         return A * B;
}

int division(int A, int B) {
     if (B != 0) {
            return A / B;
    } else {
          printf("*** :( On devise pas par 0 ***\n");
        return 0;
    }
}

int modulo(int A, int B) {
    if (B != 0) {
        return A % B;
    } else {
        printf("*** :( On devise pas par 0 ***\n");
          return 0;
    }
}

main() {
    char choix;
    do {
        int op1, op2, res;
        char operateur;

       
          printf("operant1 ?  operateur ? operant2 ?");
          scanf("%d %c %d", &op1, &operateur, &op2);

       
        switch (operateur) {
            case '+':
                res = addition(op1, op2);
                break;
            case '-':
                res = soustraction(op1, op2);
                break;
            case '*':
                res = multiplication(op1, op2);
                break;
            case '/':
                res = division(op1, op2);
                break;
            case '%':
                res = modulo(op1, op2);
                break;
            default:
                printf("Invalide\n");
                continue; 
        }

        printf("*** RESULTAT : [  %d  ] ***\n", res);

    
        printf("Recommencer? (O/N) : ");
        scanf(" %c", &choix);

    } while (choix == 'O' || choix == 'o');


}

