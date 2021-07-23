#include "fila.h"

int random_numero(int a){
  
  return (1 + (rand() % a));
}

filas *inicializa_fila(filas *fila, int *prioridades) {
  fila = malloc(sizeof(filas));
  fila->prox = NULL;
  return fila;
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
      insere_inicio_lista(x, fila, prioridade);

    }
    else{
      item -> prox = p;
      ant -> prox = item;
    }

    return 1;

}

int insere_inicio_lista(int x, filas*fila, int prioridade){

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

int insere_fim_lista(int x, filas*fila){
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
