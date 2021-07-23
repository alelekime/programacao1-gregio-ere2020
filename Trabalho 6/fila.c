#include "fila.h"

void inicializa_fila(filas *fila, int *prioridades) {
  fila->prox = NULL;
}

int insere_ordenado_fila(int x, filas *fila, int prioridade){
    srand((unsigned)time(NULL));
    filas *item, *ant = NULL, *p;

    item = malloc(sizeof(filas));
    item->valor= x;
    item->prioridade = prioridade;
    item->prox = NULL;

    if (fila == NULL)
    {
        fila = item;
        return 1;
    }

    p = fila->prox;

    while (p != NULL && p->prioridade >= prioridade)
    {
        ant = p;
        p = p->prox;
    }
    if (ant == NULL) {
      insere_inicio_fila(x, fila, prioridade);

    }
    else{
      item -> prox = p;
      ant -> prox = item;
    }

    return 1;

}

int insere_inicio_fila(int x, filas*fila, int prioridade){

    filas *item = malloc(sizeof(filas));

    item-> valor = x;
    item->prioridade = prioridade;
    if (fila == NULL)
    {
        fila = item;
        item->prox = NULL;
    }

    else
    {
        item->prox = fila->prox;
        fila->prox= item;
    }

    return 1;

}

int remove_primeiro_lista(filas*fila){

  fila = fila->prox;

  return 1;
}

void destroi_fila(filas*fila) {
    filas *p;
    if (fila == NULL) {
      printf("Nao destruida: lista vazia\n");
      return;
    }
    for (p = fila; p != NULL; p = p->prox)
      remove_primeiro_lista(fila);
}

void inicializa_prioridade(int *prioridades) {
  int i;
    for (i = 1; i < 5; i++) {
        prioridades[i] = 0;
    }
}

void imprime_lista(int *prioridades) {
  int i;
    printf("\n  +++ FIM DO EXPEDIENTE +++ \n\n  ATENDIDOS:\n\n");
    for (i = 0; i < 5; i++) {
        printf("  prioridade %d: %d ", i + 1, prioridades[i]);
        printf("\n");
    }
}
