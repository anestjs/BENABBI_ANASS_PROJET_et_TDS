#include <stdio.h>


typedef struct {
    double real;
    double imag;
} Complex;

double imag(Complex z) {
    return z.imag;
}


double real(Complex z) {
    return z.real;
}


Complex mul(Complex z1, Complex z2) {
    Complex result;

    result.real = z1.real*z2.real - z1.imag*z2.imag;
    result.imag = z1.real* z2.imag + z1.imag *z2.real;

    return result;
}


void imag_parpt(Complex *z, double *result) {
    *result = z->imag;
}


void real_parpt(Complex *z, double *result) {
    *result = z->real;
}


void mul_parpt(Complex *z1, Complex *z2, Complex *result) {
    result->real = z1->real * z2->real - z1->imag * z2->imag;
    result->imag = z1->real * z2->imag + z1->imag * z2->real;
}

main() {
	
	  Complex complex1, complex2,result;
	
   printf("Entrez la partie reel de 1er nombbre : ");
    scanf("%lf", &complex1.real);

    printf("Entrez la partie imaginaire de 1er nombbre : ");
    scanf("%lf", &complex1.imag);

    printf("Entrez la partie reel de 2eme nombbre : ");
    scanf("%lf", &complex2.real);

    printf("Entrez la partie imaginaire de 2eme nombbre : ");
    scanf("%lf", &complex2.imag);
    
    
  
printf("\n\n");

    printf("Partie reel de x : %.2f\n", real(complex1));
    printf("partie imaginaire y : %.2f\n", imag(complex1));

printf("\n----------------------------------------------------\n");
    result = mul(complex1, complex2);
    printf("Mult de x et y : %.2f + %.2fi\n", result.real, result.imag);



printf("\n\n");
    double real_result, imag_result;
    real_parpt(&complex1, &real_result);
    imag_parpt(&complex1, &imag_result);

    printf("Partie reel de xpt  : %.2f\n", real_result);
    printf("Partie imaginaire de ypt  : %.2f\n", imag_result);

printf("\n----------------------------------------------------\n");
    mul_parpt(&complex1, &complex2, &result);
    printf("Mult de xpt et ypt  : %.2f + %.2fi\n", result.real, result.imag);

}

