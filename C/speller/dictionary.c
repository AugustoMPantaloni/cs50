// Implementa la funcionalidad de un diccionario

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

// Representa un nodo en una tabla hash
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Elegir el número de compartimentos (buckets) en la tabla hash
const unsigned int N = 26;

// Tabla hash
node *table[N];

int count = 0;

// Devuelve verdadero si la palabra está en el diccionario, falso en caso contrario
    bool check(const char *word)
{   
    int index =  hash(word);

    char lowerWord[LENGTH + 1];
    int i;
    for (i = 0; word[i]!= '\0'; i++)
    {
        lowerWord[i] =  tolower(word[i]);
    }
    lowerWord[i] = '\0';
    
    node *cursor = table[index];

    while(cursor)
    {
        if(strcmp(cursor->word, lowerWord) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashea una palabra a un número
    unsigned int hash(const char *word)
{
    unsigned int add = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        add += tolower(word[i]);
    }

    return add % N;
}


// Carga el diccionario en memoria, devuelve verdadero si tuvo éxito, falso en caso contrario 
    bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if(source == NULL)
    {
        printf("Error opening file.");
        return false;
    }
    

    count = 0;

    char buffer[LENGTH + 1];
    while(fscanf(source, "%s", buffer) != EOF)
    {
        int index = hash(buffer);
        
        node *newNode = malloc(sizeof(node));
        if(newNode == NULL)
        {   
            fclose(source);
            printf("Memory error");
            return false;
        } 

        strcpy(newNode->word, buffer);
        newNode->next = table[index];
        table[index] = newNode;
        count += 1;
    }
    
    fclose(source);
    return true;
}

// Devuelve el número de palabras en el diccionario si se cargó, o 0 si aún no se cargó
    unsigned int size(void)
{
    return count;
}

// Libera el diccionario de la memoria, devuelve verdadero si tuvo éxito, falso en caso contrario
    bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while(cursor)
        {
            node *tmp = cursor;
            cursor = cursor ->next;
            free(tmp);
        }
    }
    return true;
}
