#include <stdio.h>

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


int main(void){
    char texto[1000];

    printf("Ingrese un texto para conocer su grado\n");
    fgets(texto, 1000, stdin);
    limpiarN(texto);
    int longitud = calcularLongitud(texto);

    int oraciones = 0;
    int palabras = 1; //Comenzamos en 1 ya que siempre hay al menos 1 palabra
    int caracteres = 0;


    //Contamos oraciones: finalizan  en '.', '!', '?' 
    // Contamos palabras: cada espacio indica una nueva palabra ' ' 
    // Contamos caracteres: solo letras alfabeticas, mayusculas y minusculas
    for(int i = 0; i < longitud; i++){
        if(texto[i] == '.' || texto[i] == '!' || texto[i] == '?'){
            oraciones += 1;
        }
        if(texto[i] == ' '){
            palabras += 1;
        }
        if( (texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z') ){
            caracteres += 1;
        }
    }

    //Calculamos el indice de Coleman-Liau.
    //Grado = (0.0588 × L) − (0.296 × S) − 15.8
    float L = ( (float) caracteres / palabras) * 100; // L = Promedio de letras cada 100 palabras
    float S = ( (float) oraciones / palabras) * 100; // S = Promedio de oraciones cada 100 palabras

    float resultado = (0.0588 * L) - (0.296 * S) - 15.8;

    int grado =  resultado + 0.5;

    if(grado >= 16){
        printf("Grade 16+\n");
    } else if(grado < 1){
        printf("Before Grade 1\n");
    } else{
        printf("Grade %d\n", grado);
    }

    return 0;
}