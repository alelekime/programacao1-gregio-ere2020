#include "mines.h"
#include "pilha.h"

void inicializa_campo(campo_minado *campoMinado)
{
    scanf("%d", &campoMinado->x);
    scanf("%d", &campoMinado->y);
    scanf("%d", &campoMinado->total_minas);
    campoMinado->falta_abrir = campoMinado->x * campoMinado->y - campoMinado->total_minas;
    zerar_campo(campoMinado);
    // gerar_minas(campoMinado);
    // contar_vizinhos_com_mina(campoMinado);
}

void zerar_campo(campo_minado *campoMinado)
{
    campoMinado->m = malloc(sizeof(quadrado *) * campoMinado->x);

    for (int i = 0; i < campoMinado->x; i++)
    {
        campoMinado->m[i] = malloc(sizeof(quadrado) * campoMinado->y);
    }
    for (int i = 0; i < campoMinado->x; i++)
    {
        for (int j = 0; j < campoMinado->y; j++)
        {
            if (eh_borda(i, j, campoMinado))
            {
                campoMinado->m[i][j]->info = BORDA;
            }
            else
            {
                campoMinado->m[i][j]->info = NADA;
                campoMinado->m[i][j]->revelado = false;
            }
        }
    }
}

bool eh_borda(int i, int j, campo_minado *campoMinado)
{
    if ((i == 0) || (i == campoMinado->x + 1) || (j == 0) || (j == campoMinado->y + 1))
    {
        return true;
    }
    return false;
}