#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 10

typedef struct filas
{
    int prioridade;
    int valor;
    struct filas *prox;
} filas;

void inicializa_fila(filas *fila, int *prioridades);
void inicializa_prioridade(int *prioridades);
int insere_ordenado_fila(int x, filas *fila, int prioridade);
int insere_inicio_fila(int x, filas*fila, int prioridade);
void destroi_fila(filas*fila);
int remove_primeiro_lista(filas*fila);
void imprime_lista(int *prioridades);
