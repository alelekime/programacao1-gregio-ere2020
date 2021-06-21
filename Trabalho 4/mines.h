#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MINA 1;
#define NADA 0;
#define GANHOU 1;
#define PERDEU 2;
#define EM_ANDAMENTO 3;

#define BORDA -2;

typedef struct
{
    int info;
    bool revelado;
} quadrado;

typedef struct
{
    int x, y;
    int total_minas;
    int falta_abrir;
    int status;
    quadrado **m;
} campo_minado;

void inicializa_campo(campo_minado *campoMinado);
void zerar_campo(campo_minado *campoMinado);
bool eh_borda(int i, int j, campo_minado *campoMinado);