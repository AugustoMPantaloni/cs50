#include <stdio.h>

    //Funcion para limpiar '\n'
    void limpiarN (char variable[]){
        for(int i = 0; variable[i] != '\0'; i++){
            if(variable[i] == '\n'){
                variable[i] = '\0';
                break;
            }
        }
    }

    //Funcion para calcular la longitud
    int longitud (char variable[]){
        int i;
        for(i = 0; variable[i] != '\0'; i++);
        return i;
    }

    //Funcion para transformar cada caracter en su indice a=0, b=1, c=2 ..., z=25 y pasar las mayus a minusculas.
    int calcularIndice (char letra){
        int indice;
        if((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')){
            if(letra >= 'A' && letra <= 'Z'){
                letra += 32;
            }
            indice = letra - 'a';
            return indice;
        } else {
            return -1;
        }
    }


int main(void){

    char player1[20];
    char player2[20];

    printf("Player1:");
    fgets(player1, 20, stdin);
    limpiarN(player1);
    int longitudP1 = longitud(player1);

    printf("player2:");
    fgets(player2, 20, stdin);
    limpiarN(player2);
    int longitudP2 = longitud(player2);

    // Declaramos los puntos para cada letra del abacedario respetando su posicion 
    int puntos[] = {
        1, // A
        3, // B
        3, // C
        2, // D
        1, // E
        4, // F
        2, // G
        4, // H
        1, // I
        8, // J
        5, // K
        1, // L
        3, // M
        1, // N
        1, // O
        3, // P
        10,// Q
        1, // R
        1, // S
        1, // T
        1, // U
        4, // V
        4, // W
        8, // X
        4, // Y
        10 // Z
    };

    // Usando la funcion calcularIndice() obtenemos el indice del caracter en el abecedario y lo usamos en el array de puntos[] para saber el valor del caracter y lo agregamos al array puntosP1[]
    int puntosP1[20];
    for(int i = 0; i < longitudP1; i++){
        int indice = calcularIndice(player1[i]);
        if(indice == -1){
            puntosP1[i] = 0;
        } else{
            puntosP1[i] = puntos[indice];
        }
    }
    
    //Lo mismo pero para el player2
    int puntosP2[20];
    for(int i = 0; i < longitudP2; i++){
        int indice = calcularIndice(player2[i]);
        if(indice == -1){
            puntosP2[i] = 0;
        }else{
            puntosP2[i] = puntos[indice];
        }
    }

    //Sumamos los puntos del array puntosP1[]
    int totalP1 = 0;
    for(int i = 0; i < longitudP1; i++){
        totalP1 += puntosP1[i]; 
    }

    //Lo mismo pero para puntosP2[]
    int totalP2 = 0;
    for(int i = 0; i < longitudP2; i++){
        totalP2 += puntosP2[i]; 
    }

    //Verificamos cual fue el jugador con mayor puntaje o si fue empate
    if(totalP1 > totalP2){
        printf("Player 1 wins\n");
    } else if( totalP1 < totalP2){
        printf("Player 2 wins\n");
    } else{
        printf("Tie!\n");
    }

    return 0;
}