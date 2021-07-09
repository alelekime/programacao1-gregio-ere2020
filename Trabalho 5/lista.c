#include "lista.h"

int cria_lista(t_lista *l)
{
    if ((l = malloc(sizeof(t_lista))) != NULL)
    {
        l->tamanho = 0;
        return 1;
    }
    return 0;
}

int lista_vazia(t_lista *l)
{
    if (l->tamanho == 0)
    {
        return 1;
    }
    return 0;
}

void destroi_lista(t_lista *l)
{
    t_nodo *item, *p;
    p = l->item->prox;
    l->item->prox = NULL;
    do
    {
        item = p->prox;
        free(p);
        p = item;
        l->tamanho--;
    } while (l->tamanho > 0);
}

int insere_inicio_lista(int x, t_lista *l)
{
    t_nodo *item;
    if ((item = malloc(sizeof(t_nodo))) != NULL)
    {
        item->valor = x;
        if (l->item == NULL)
        {
            l->item = item;
            item->prox = NULL;
        }

        else
        {
            item->prox = l->item;
            l->item = item;
        }

        l->tamanho++;
        return 1;
    }
    return 0;
}

int insere_fim_lista(int x, t_lista *l)
{
    t_nodo *item, *p;
    p = l->item;
    if ((item = malloc(sizeof(t_nodo))) != NULL)
    {
        item->valor = x;
        item->prox = NULL;
        if (l->item == NULL)
            l->item = item;
        else
        {
            while (p->prox != NULL)
                p = p->prox;
            p->prox = item;
        }
        l->tamanho++;
        return 1;
    }
    return 0;
}

int insere_ordenado_lista(int x, t_lista *l)
{
    printf("%d  ", x);
    t_nodo *item, *ant, *p;
    //ant = NULL;
    // p = l->item;

    if ((item = malloc(sizeof(t_nodo))) != NULL)
    {
        // printf("%d\n", p->valor);

        return 1;
    }
    return 0;
}

void imprime_lista(t_lista *l)
{
    printf("tam: %d -> ", l->tamanho);
    t_nodo *item;
    for (item = l->item; item != NULL; item = item->prox)
        printf("%d ", item->valor);
    printf("\n");
}