#include <stdio.h>
#include <stdlib.h>
#define MAX 80
#define MAX_PESO 4000
#define limpiar_pantalla "cls"
#define LISTA_1 "pesos.txt"
#define LISTA_2 "pesos2.txt"
#define PESO "pesos.txt"


typedef struct
{
    int id, peso;
} teu_t;

typedef struct
{
    int suma;
    teu_t cont[MAX];

} barco_t;
