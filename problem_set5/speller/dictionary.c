// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26; //hacemos un nodo por letra del abecedario y guardamos las palagras que empiezan con esa letra en ese nodo.

int counter_word = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);

    node *nodePtr = table[key]; //se mete en el bloque.

    while(nodePtr != NULL)
    {
        if(strcasecmp(nodePtr->word, word) == 0) //compara palabras.
        {
            return true;
        }

        nodePtr = nodePtr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;

    for(int i=0; word[i]!= '\0'; i++) //lee la palabra entera.
    {
        value += tolower(word[i]); //Las variables del tipo Tipo de dato carácter(char) almacenan el código ASCII del carácter.
    }                              //tolower() le suma 32 al número entero correspondiente al código ASCII del carácter.

    return value % N; //sumo el valor de todas las letras en value. Divido por N (candidad de letras) y obtengo resto.
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file_dic = fopen(dictionary, "r");
    if(file_dic == NULL)
    {
       return false;
    }

    for(int i=0; i<N; i++) // genero tabla (nodos) vacíos.
    {
        table[i] = NULL;
    }

    char tempword[LENGTH + 1]; //mismo tamaño que word.

    while(fscanf(file_dic, "%s", tempword) != EOF) //fscanf() la usamos para leer palabra por palabra dentro de dictionary.
    {
        node *n = malloc(sizeof(node)); //genero nuevo nodo n, el cual es un nodo temporario.
        if (n == NULL)
        {
            unload();
            return false;
        }
        strcpy(n -> word, tempword); //copia la palabra en un bloque(nodo) de la memoria.

        int key = hash(tempword); //ubica la palabra en uno de esos 26 nodos.

        if(table[key] == NULL) //caso en que el bloque de la tabla esté vacío.
        {
            n->next = NULL;
            table[key] = n;
        }
        else //caso en que ya haya palabras guardadas en ese bloque.
        {
            n->next = table[key]; //señalo al siguiente nodo (hago esa conexion). La primera palabra que figura en la lista.
            table[key] = n;  //hago que la palabra añadida sea señalada por el bloque de la table. Quedando esta nuebra palabra añadida, en la cabecera.
        }

        counter_word++;
    }
    fclose(file_dic);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i=0; i<N; i++)
    {
        node *nodePtr = table[i];

        while(nodePtr != NULL)
        {
            node *deleteMe = nodePtr;
            nodePtr = nodePtr->next;
            free(deleteMe);
        }
        table[i]= NULL;
    }
    return true;
}
