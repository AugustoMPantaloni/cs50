#include <stdio.h>
#include <ctype.h>
#include <string.h>

    //Funcion para limpiar '\n'
    void limpiarN (char variable[]){
        for(int i = 0; variable[i] != '\0'; i++){
            if(variable[i] == '\n'){
                variable[i] = '\0';
                break;
            }
        }
    }


int main(int argc, char *argv[]){

    // Determine length of the substitution key
    int longitud = strlen(argv[1]);

    // Check that exactly one key argument is provided
    if(argc != 2){
        printf("Usage: ./subsitucion key\n");
        return 1;
    }

    // Key must be exactly 26 characters
    if(longitud != 26 ){
        printf("key must contain 26 characters\n");
        return 1;
    }

    // Key must consist of only alphabetic characters
    for(int i = 0; i < longitud; i++){
        if(!( (argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z') )){
            printf("Usage: ./subsitucion key\n");
            return 1;
        }
    }

    // Key must not contain duplicate letters
    for(int i = 0; i < longitud; i++){
        for( int j = i+1; j < longitud; j++){
            if(argv[1][i] == argv[1][j]){
                printf("repeated character: %c\n", argv[1][i]);
                return 1;
            }
        }
    }

    // Prompt user for plaintext
    char plaintext[100];
    printf("plaintext:\n");
    fgets(plaintext, 100, stdin);
    limpiarN(plaintext);

    // Prepare ciphertext buffer (same length as plaintext)
    int textLeng = strlen(plaintext);
    char cipherText[textLeng + 1];

    for(int i = 0; i < textLeng; i++){
        int index = plaintext[i] - 'A';
        cipherText[i] = argv[1][index];
    }

    return 0;
}