#include "func.h"


void leituraVetor(int *vetor, int n){
  for (int i = 0; i < n; i++){
      scanf("%d", &vetor[i]);// leitura do vetor
  }
}

bool verificaVetor(int *sequenciaUm, int *sequenciaDois, int n){
    bool diferente = false;
    int i = 0;
    while (i < n && !diferente){
      // compara os elemento dos dois vetores com os mesmos indices
      // se os elementos forem diferentes, a variavel vai receber true e
      // o looping vai acabar
      if (sequenciaUm[i] != sequenciaDois[i])  {
          diferente = true;
      }
      i++;
    }
    return diferente; //true se diferente, false se nao
}


void imprimeExemplo() {
  printf("-------EXEMPLO---------\n");
  printf("5\n");
  printf("1 2 3 4 5 \n");
  printf("1 2 3 4 5 \n");
  printf("SIM, são iguais\n");
  printf("-----------------------\n");
  printf("-------EXEMPLO---------\n");
  printf("3\n");
  printf("1 2 3\n");
  printf("3 2 1\n");
  printf("Não, são diferentes\n");
  printf("-----------------------\n");
  printf("\n");
}
