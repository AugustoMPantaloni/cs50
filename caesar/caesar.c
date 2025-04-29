#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

   //Elimina el salto de linea final de un string
    void limpiarN (char variable[]){
    for(int i = 0; variable[i] != '\0'; i++){
        if(variable[i] == '\n'){
            variable[i] = '\0';
            break;
        }
    }
}

    //Calcula la longitud de un string
    int calcularLongitud (char variable[]){
        int i;
        for(i = 0; variable[i] != '\0'; i++);
        return i;
    }


    //Este codigo es un programa para cifrar un mensaje segun una clave.
    //Esta clave es la cantidad de letras que va a desplazarce cada letra en el abecedario.
    //Ej: Si la clave es "2", la letra "A" se transforma en "C", y asi se cifra todo un texto.
    int main (int argc, char *argv[]){
        
        if(argc != 2){
            printf("Usage: ./caesar key\n");
            return 1;
        }

        for (int i = 0; argv[1][i] != '\0'; i++){
            if(!isdigit(argv[1][i])){
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]);
        if (key < 0) {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        //Si la clave es mayor a 26 (Cantidad de letras en el abecedario) usamos modulo 26 para mantener el desplazamiento dentro del alfabeto.
        if(key > 26){ 
            key = key % 26;
        }

        char plaintext[100];
        char ciphertext[100];

        printf("plaintext:\n");
        fgets(plaintext, 50, stdin);
        limpiarN(plaintext);
        int longitud = calcularLongitud(plaintext);

        for( int i = 0; i < longitud; i++){
            if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
                ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
            } else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
                ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A'; 
            } else{
                ciphertext[i] = plaintext[i];
            }
        }
        ciphertext[longitud] = '\0';

        printf("ciphertext: %s\n", ciphertext);

        return 0;
}