#include <stdio.h>
#include <ctype.h>
#include <string.h>

void limpiarN(char variable[]) {
    for(int i = 0; variable[i] != '\0'; i++) {
        if(variable[i] == '\n') {
            variable[i] = '\0';
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    // Check that exactly one key argument is provided
    if(argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Determine length of the substitution key
    int longitud = strlen(argv[1]);
    
    // Key must be exactly 26 characters
    if(longitud != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Key must consist of only alphabetic characters and check for duplicates
    int letras[26] = {0};
    for(int i = 0; i < longitud; i++) {
        if(!isalpha(argv[1][i])) {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        char upper = toupper(argv[1][i]);
        if(letras[upper - 'A']) {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        letras[upper - 'A'] = 1;
        argv[1][i] = upper; 
    }

    // Prompt user for plaintext
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, 100, stdin);
    limpiarN(plaintext);

    // Prepare ciphertext buffer
    int textLeng = strlen(plaintext);
    char cipherText[textLeng + 1];

    // Replace each letter of the text with the corresponding one in the key
    for(int i = 0; i < textLeng; i++) {
        if(isupper(plaintext[i])) {
            cipherText[i] = argv[1][plaintext[i] - 'A'];
        } else if(islower(plaintext[i])) {
            cipherText[i] = tolower(argv[1][plaintext[i] - 'a']);
        } else {
            cipherText[i] = plaintext[i];
        }
    }
    cipherText[textLeng] = '\0';

    printf("ciphertext: %s\n", cipherText);
    return 0;
}