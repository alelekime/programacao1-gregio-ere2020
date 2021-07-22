#include "fila.h"

void inicializa_fila(filas *fila, int *prioridades)
{

    srand((unsigned)time(NULL));
    for (int i = 1; i < MAX; i++)
    {
        fila->prioridade = 1 + (rand() % 5);
        printf("%d\n", fila->prioridade);
        prioridades[fila->prioridade - 1]++;
        fila->prox = malloc(sizeof(fila));
        fila = fila->prox;
    }
    fila->prioridade = 1 + (rand() % 5);
    prioridades[fila->prioridade]++;
    fila->prox = NULL;
    printf("%d\n", fila->prioridade);
}

void inicializa_prioridade(int *prioridades)
{
    for (int i = 1; i < 5; i++)
    {
        prioridades[i] = 0;
    }
}
void imprime_lista(int *prioridades)
{
    printf("+++ FIM DO EXPEDIENTE +++ \n\nATENDIDOS:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("prioridade %d: %d ", i + 1, prioridades[i]);
        printf("\n");
    }
}
