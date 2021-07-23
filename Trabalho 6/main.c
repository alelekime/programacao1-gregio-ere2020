#include "fila.h"

void preenche_fila(filas *fila, int *prioridades) {
  int i;
  int *a = malloc(sizeof(int) * MAX);
  int *b = malloc(sizeof(int) * MAX);

  srand(time(NULL));
  for (i = 0; i < MAX; i++) {

    a[i] = 1 + (rand() % 5);
    b[i] = 1 + (rand() % 100);
  }
  for (i = 0; i < MAX; i++) {
    insere_ordenado_fila(b[i], fila, a[i]);
  }
  free(a);
  free(b);

}



void processa_fila(filas *fila, int *prioridades){

  int prioridade;
  int valor;
  int tempo = 0;
  filas *p = fila;
  p=p->prox;
  while (1) {
    tempo += p->prioridade;
    sleep(p->prioridade);
    remove_primeiro_lista(p);
    prioridade = abs(1 + (p-> valor  % 5));
    valor = abs(1 + (p-> valor % 100));
    prioridades[p->prioridade- 1]++;
    insere_ordenado_fila(valor, p, prioridade);
    if (tempo >= 30) {
      destroi_fila(p);
      imprime_lista(prioridades);
      printf("\n  Total do expediente: %d segundos\n", tempo);
      break;
    }
    p = p-> prox;
  }
}

int main(int argc, char const *argv[]) {
    filas fila;
    int *prioridades = malloc(sizeof(int) * 5);
    inicializa_prioridade(prioridades);

    inicializa_fila(&fila, prioridades);

    preenche_fila(&fila,prioridades);

    processa_fila(&fila, prioridades);

    free(prioridades);

    return 0;
}
