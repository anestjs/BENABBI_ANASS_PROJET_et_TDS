#include <stdio.h>




void crypt(char *caract) {

    if ((*caract >= 'A' && *caract <= 'Z') ||  (*caract >= 'a' && *caract <= 'z') ) {
        *caract += 5;

     
        if (  (*caract > 'Z') || (*caract > 'z' )) {
            *caract -= 26;
        }
    }
}

main() {
    int i;
    char msg[] = "anas is doing some cryptographie :)";
  
    for (i = 0; msg[i] != '\0'; i++) {
        crypt(&msg[i]);
    }


    printf("Crypte ----> [ %s ]\n", msg);


}

