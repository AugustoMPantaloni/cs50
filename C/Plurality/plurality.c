#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Los candidatos tienen nombre y contador de votos
typedef struct
{
    string nombre;
    int votos;
} candidato;

// Arreglo de candidatos
candidato candidatos[MAX]; 

// Número de candidatos
int cantidad_de_candidatos;

// Prototipos de funciones
bool votar(string nombre);
void imprimir_ganador(void);

int main(int argc, string argv[])
{
    // Verificar uso incorrecto
    if (argc < 2)
    {
        printf("Uso: pluralidad [candidato ...]\n");
        return 1;
    }

    // Llenar el arreglo de candidatos
    cantidad_de_candidatos = argc - 1;
    if (cantidad_de_candidatos > MAX)
    {
        printf("El número máximo de candidatos es %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < cantidad_de_candidatos; i++)
    {
        candidatos[i].nombre = argv[i + 1];
        candidatos[i].votos = 0;
    }

    int cantidad_de_votantes = get_int("Número de votantes: ");

    // Bucle sobre todos los votantes
    for (int i = 0; i < cantidad_de_votantes; i++)
    {
        string nombre = get_string("Voto: ");

        // Verificar voto inválido
        if (!votar(nombre))
        {
            printf("Voto inválido.\n");
        }
    }

    // Mostrar el ganador de la elección
    imprimir_ganador();
}

// Actualizar el total de votos dado un nuevo voto
bool votar(string nombre)
{
    for(int i = 0; i < cantidad_de_candidatos; i++){
        if(strcmp(candidatos[i].nombre, nombre) == 0){
            candidatos[i].votos += 1;
            return true;
        }
    }
    return false;
}

// Imprimir el ganador (o los ganadores) de la elección
void imprimir_ganador(void)
{   
    int mayor_voto = 0;

    for(int i = 0; i < cantidad_de_candidatos; i++){
        if(candidatos[i].votos > mayor_voto){
            mayor_voto = candidatos[i].votos;
        }
    }

    for(int i = 0; i < cantidad_de_candidatos; i++){
        if(candidatos[i].votos == mayor_voto){
            printf("%s\n", candidatos[i]. nombre);
        }
    }

    return;
}
