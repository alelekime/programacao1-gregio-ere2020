#include "fila.h"

void preenche_fila(filas *fila, int *prioridades){
  int *a = malloc(sizeof(int) * MAX);
  int *b = malloc(sizeof(int) * MAX);
filas *p = fila;
  srand(time(NULL));
  for (int i = 0; i < MAX; i++) {

    a[i] = 1 + (rand() % 5);
    printf("- PRIORIDADE: %d\n", a[i]);
    //prioridades[a[i] - 1]++;
    b[i] = 1 + (rand() % 100);
    printf("- VALOR: %d\n", b[i]);
  }
  for (int i = 0; i < MAX; i++) {
    insere_ordenado_fila(b[i], fila, a[i]);
  }
  do{
    p=p->prox;
    printf("VALOR: %d\n", p->valor);
    printf("PRIORIDADE: %d\n", p->prioridade);

  }while(p-> prox!= NULL);
}



void processa_fila(filas *fila, int *prioridades){

  int prioridade;
  int valor;
  int tempo = 0;
  filas *p = fila;
  p=p->prox;
  while (1) {
    tempo += p->prioridade;
    printf(" PRIORIDADE %d - VALOR %d\n", p->prioridade, p-> valor );
    sleep(p->prioridade);
    remove_primeiro_lista(p);
    prioridade = abs(1 + (p-> valor  % 5));
    valor = abs(1 + (p-> valor % 100));
    prioridades[p->prioridade- 1]++;
    insere_ordenado_fila(valor, p, prioridade);
    // printf("___________________________\n");
    // filas *q = p;
    // do{
    //   q=q->prox;
    //
    //   printf("PRIORIDADE: %d\n", q->prioridade);
    //   printf("VALOR: %d\n", q->valor);
    // }while(q-> prox!= NULL);
    // printf("___________________________\n");
    if (tempo >= 30) {
      printf("%d\n", tempo );
      destroi_fila(p);
      imprime_lista(prioridades);
      printf("Total do expediente: %d segundos\n", tempo);
      break;
    }
    p = p-> prox;
  }
}

int main(int argc, char const *argv[]) {
    int *prioridades = malloc(sizeof(int) * 5);
    inicializa_prioridade(prioridades);
    filas *fila = inicializa_fila(fila, prioridades);
    filas *p = fila;

    preenche_fila(fila,prioridades);
    printf("------------------\n");
    do{
      p=p->prox;
      printf("VALOR: %d\n", p->valor);
      printf("PRIORIDADE: %d\n", p->prioridade);

    }while(p-> prox!= NULL);

    processa_fila(fila, prioridades);
    free(prioridades);
    free(fila);
    free(p);

    return 0;
}
