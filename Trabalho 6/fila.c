#include "fila.h"

void inicializa_fila(filas *fila, int *prioridades) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAX; i++) {
      insere_ordenado_fila(1 + (rand() % 100), fila);
    }
}


int insere_ordenado_fila(int x, filas *fila){
    srand((unsigned)time(NULL));
    filas *item, *ant = NULL, *p;

    item = malloc(sizeof(filas));
    item->valor = 1 + (rand() % 100;
    item
    item->prox = NULL;

    if (fila->prox == NULL)
    {
        fila->prox = item;
        return 1;
    }

    p = fila->prox;

    while (p != NULL && p->valor > x)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL) {
      insere_inicio_lista(x, fila);

    }
    else{
      item -> prox = p;
      ant -> prox = item;
    }

    return 1;

}

int insere_inicio_lista(int x, filas*fila)
{

    filas *item = malloc(sizeof(filas));

    item-> valor = x;
    if (fila->prox == NULL)
    {
        fila->prox = item;
        item->prox = NULL;
    }

    else
    {
        item->prox = fila->prox;
        fila->prox= item;
    }

    return 1;

}

int insere_fim_lista(int x, filas*fila)
{
    filas *item, *p;
    p = fila->prox;
    if ((item = malloc(sizeof(filas))) != NULL)
    {
        item->valor = x;
        item->prox = NULL;
        if (fila->prox == NULL)
            fila->prox = item;
        else
        {
            while (p->prox != NULL)
                p = p->prox;
            p->prox = item;
        }
        return 1;
    }
    return 0;
}

void inicializa_prioridade(int *prioridades) {
    for (int i = 1; i < 5; i++) {
        prioridades[i] = 0;
    }
}
void imprime_lista(int *prioridades) {
    printf("+++ FIM DO EXPEDIENTE +++ \n\nATENDIDOS:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("prioridade %d: %d ", i + 1, prioridades[i]);
        printf("\n");
    }
}
