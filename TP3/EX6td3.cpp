
#include <stdio.h>

void elimspace(char *phrase) {
	
char *dest = phrase;
char dernierCaractere = ' ';

    while (*phrase != '\0') {
        if (*phrase == ' ' || *phrase == '\t') {
            if (dernierCaractere != ' ') {
                *dest++ = ' ';
            }
            dernierCaractere = ' ';
        } else {
            *dest++ = *phrase;
            dernierCaractere = *phrase;
        }
        ++phrase;
    }

    *dest = '\0';
}

main() {
    char phrase[] =  "  Bonjour   tout   le   monde,   je   suis   Anas ,   a   tout   a   l heure   :)";

    printf("--> LA PHRASE : [%s]\n\n", phrase);

    elimspace(phrase);

    printf("--> LA PHRASE Modifier : [%s]\n\n", phrase);

 
}
