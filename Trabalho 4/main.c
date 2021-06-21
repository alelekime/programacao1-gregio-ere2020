#include "mines.h"
#include "pilha.h"

int main(int argc, char const *argv[])
{
    campo_minado *campoMinado = (campo_minado *)malloc(sizeof(campo_minado));
    inicializa_campo(campoMinado);

    return 0;
}
