#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateHammingDistance(const char *s1, const char *s2) {
    int i, hamming = 0, len = strlen(s1);

    for (i = 0; i < len; i++) {
        if (s1[i] == s2[i])
            hamming = hamming + 1;
    }
    return hamming;
}

int calculateLanguageHammingDistance(const char **language, int numStrings, int stringLength) {
    int distance = 1;

    for (int i = 0; i < numStrings; i++) {
        for (int j = i + 1; j < numStrings; j++) {
            if (strcmp(language[i], language[j]) == 0) {
                distance = distance + 1;
            }
        }
    }

    return distance;
}

void decimalToBinary(int num1, int num2, char *binary1, char *binary2) {
    int remainder = 0, index = 7;

    do {
        remainder = num1 % 2;
        binary1[index] = '0' + remainder;
        index = index - 1;
        num1 = num1 / 2;
    } while (num1 > 0);

    while (index >= 0) {
        binary1[index] = '0';
        index = index - 1;
    }

    index = 7;
    remainder = 0;

    do {
        remainder = num2 % 2;
        binary2[index] = '0' + remainder;
        index = index - 1;
        num2 = num2 / 2;
    } while (num2 > 0);

    while (index >= 0) {
        binary2[index] = '0';
        index = index - 1;
    }
}

int calculateBinaryHammingDistance(char *a, char *b) {
    int hamming = 0;

    for (int i = 0; i < 8; i++) {
        if (a[i] != b[i])
            hamming = hamming + 1;
    }
    return hamming;
}

int main() {
    char str1[100], str2[100];
    char binary1[7], binary2[7];

    int hamming, value1, value2;

    printf("entrer une chaine de charactere:\n");
    scanf("%s", str1);
    printf("entrer la 2eme chain:\n");
    scanf("%s", str2);

    hamming = calculateHammingDistance(str1, str2);
    printf("la Hamming distance entre %s et %s est : %d\n", str1, str2, hamming);

    const char *language[] = {"aabbn", "xayy", "tghy", "xgyy"};
    int numStrings = sizeof(language) / sizeof(language[0]);
    int stringLength = strlen(language[0]);

    int distance = calculateLanguageHammingDistance(language, numStrings, stringLength);
    printf("hamming distance est : %d\n", distance);

    printf("entrer une valeur (dec):\n");
    scanf("%d", &value1);
    printf("une autre (dec):\n");
    scanf("%d", &value2);
    decimalToBinary(value1, value2, binary1, binary2);

    printf("haming distance entre %d et %d en binaire est : %d\t", value1, value2, calculateBinaryHammingDistance(binary1, binary2));
}

