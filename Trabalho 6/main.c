#include "fila.h"

void preenche_fila(filas *fila, int *prioridades){
  filas *p = fila;
  srand((unsigned)time(NULL));
  for (p = fila->prox; p != NULL; p = p->prox){
    fila->prioridade = 1 + (rand() % 5);
    printf("%d\n", fila->prioridade);
    prioridades[fila->prioridade -1]++;
  }
}

int main(int argc, char const *argv[]) {
    int *prioridades = malloc(sizeof(int) * 5);
    inicializa_prioridade(prioridades);
    filas *fila = malloc(sizeof(filas));
    fila->prox = NULL;
    filas *p = fila;
    inicializa_fila(fila, prioridades);
    preenche_fila(fila,prioridades);
    do{
        p = p->prox;
        printf("%d\n",p->valor );

    }while (p->prox != NULL);
    imprime_lista(prioridades);

    return 0;
}
