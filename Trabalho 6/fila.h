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
    int valor;
    struct filas *prox;
} filas;

void inicializa_fila(filas *fila, int *prioridades);
void inicializa_prioridade(int *prioridades);
int insere_ordenado_fila(int x, filas *fila);
int insere_inicio_lista(int x, filas*fila);
int insere_fim_lista(int x, filas*fila);
void imprime_lista(int *prioridades);
