#include "fila.h"

int main(int argc, char const *argv[])
{
    int *prioridades = malloc(sizeof(int) * 5);
    inicializa_prioridade(prioridades);
    filas *fila = malloc(sizeof(filas));
    inicializa_fila(fila, prioridades);
    imprime_lista(prioridades);
    return 0;
}
