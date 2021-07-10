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
    printf("%d  \n", x);
    t_nodo *item, *ant, *p, *prox;
    p = l->item;
    l->tamanho++;
    if (l->item == NULL)
    {
        l->item = malloc(sizeof(t_nodo));
        item->valor = x;
        imprime_lista(l);
        return 1;
    }
    // while (p->prox != NULL && p->valor < x)
    // {
    //     ant = p;
    //     p = p->prox;
    // }
    // prox = ant->prox;
    // ant->prox = malloc(sizeof(t_nodo));
    // ant = ant->prox;
    // ant->valor = x;
    // ant->prox = prox;
    return 0;
}

void imprime_lista(t_lista *l)
{
    if (l->item != NULL)
    {
        printf("tam: %d -> ", l->tamanho);
        t_nodo *item;
        for (item = l->item; item != NULL; item = item->prox)
            printf("%d ", item->valor);
        printf("\n");
    }
}

int remove_primeiro_lista(int *item, t_lista *l)
{
    item = &l->item->valor;
    printf("%d\n", *item);
    if (l != NULL)
    {
        l->item = l->item->prox;
        l->tamanho--;
    }

    return 1;
}

int remove_ultimo_lista(int *item, t_lista *l)
{
    t_nodo *p, *ant;
    p = l->item;
    if (l->tamanho == 1)
    {
        l->item = NULL;
        free(p);
        l->tamanho--;
        return 1;
    }

    while (p->prox != NULL)
    {
        ant = p;
        p = p->prox;
    }
    item = &p->valor;
    free(p->prox);
    ant->prox = NULL;
    l->tamanho--;
    return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l)
{
    t_nodo *p, *ant;
    p = l->item;
    if ((p != NULL) && (p->valor == chave))
    {
        l->item = p->prox;
        free(p);
        return 1;
    }

    while ((p != NULL) && (p->valor != chave))
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
    {
        return 0;
    }
    ant->prox = p->prox;
    free(p);
    return 1;
}

int pertence_lista(int chave, t_lista *l)
{
    t_nodo *p;
    p = l->item;
    while (p->prox != NULL)
    {
        if (p->valor == chave)
        {
            return 1;
        }
        p = p->prox;
    }
    return 0;
}

int concatena_listas(t_lista *l, t_lista *m)
{

    t_nodo *p, *q, *ant, *prox;
    p = l->item;
    q = m->item;
    ant = m->item;
    while (p->prox != NULL)
        p = p->prox;
    while (q != NULL)
    {
        p->prox = malloc(sizeof(t_nodo));
        p = p->prox;
        p->valor = q->valor;
        q = q->prox;

        l->tamanho++;
    }
    prox = m->item->prox;
    m->item = NULL;
    while (prox->prox != NULL)
    {
        ant = prox;
        prox = prox->prox;
        free(ant);
    }
    m->tamanho = 0;
    return 1;
}

int copia_lista(t_lista *l, t_lista *m)
{
    t_nodo *p, *fim = NULL;
    p = l->item;
    m->tamanho = 1;
    m->item = malloc(sizeof(t_nodo));
    m->item->valor = p->valor;
    fim = m->item;
    p = p->prox;
    do
    {
        fim->prox = malloc(sizeof(t_nodo));
        fim = fim->prox;
        fim->valor = p->valor;
        fim->prox = NULL;
        p = p->prox;
        m->tamanho++;
    } while (!(m->tamanho == l->tamanho));
    return 1;
}