#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX 5

typedef struct filas
{
    int prioridade;
    struct filas *prox;
} filas;

void inicializa_fila(filas *fila, int *prioridades);
void inicializa_prioridade(int *prioridades);
void imprime_lista(int *prioridades);