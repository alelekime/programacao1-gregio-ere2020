#include "lista.h"

int cria_listas(t_lista *l, t_lista *m, t_lista *o, t_lista *c)
{
    printf("Criando lista l\n");
    if (!cria_lista(l))
    {
        printf("Erro: lista l nao foi criada.");
        return 0;
    }

    printf("Criando lista m\n");
    if (!cria_lista(m))
    {
        printf("Erro: lista m nao foi criada.");
        return 0;
    }

    printf("Criando lista o\n");
    if (!cria_lista(o))
    {
        printf("Erro: lista o nao foi criada.");
        return 0;
    }

    printf("Criando lista c\n");
    if (!cria_lista(c))
    {
        printf("Erro: lista c nao foi criada.");
        return 0;
    }
    return 1;
}
int testa_insercao_inicio(t_lista *l)
{
    int i;

    for (i = 1; i <= MAX; i++)
        if (!insere_inicio_lista(2 * i, l))
            return 0;
    return 1;
}

int testa_insercao_fim(t_lista *l)
{
    int i;

    for (i = 1; i <= MAX; i++)
        if (!insere_fim_lista(2 * i - 1, l))
            return 0;
    return 1;
}

int testa_insercao_ordenada(t_lista *l)
{
    if (!insere_ordenado_lista(8, l))
        return 0;
    if (!insere_ordenado_lista(10, l))
        return 0;
    if (!insere_ordenado_lista(0, l))
        return 0;
    if (!insere_ordenado_lista(9, l))
        return 0;
    if (!insere_ordenado_lista(12, l))
        return 0;
    if (!insere_ordenado_lista(2, l))
        return 0;
    if (!insere_ordenado_lista(3, l))
        return 0;
    return 1;
}

int testa_insercoes(t_lista *l, t_lista *m, t_lista *o)
{
    printf("Teste: inserir no inicio\n");
    if (!testa_insercao_inicio(l))
    {
        printf("Insercao no inicio falhou...");
        return 0;
    }
    printf("l: ");
    imprime_lista(l);
    printf("Teste: inserir no fim\n");
    if (!testa_insercao_fim(m))
    {
        printf("Insercao no fim falhou...");
        return 0;
    }
    printf("m: ");
    imprime_lista(m);
    printf("Teste: inserir ordenado\n");
    if (!testa_insercao_ordenada(o))
    {
        printf("Insercao ordenada falhou...");
        return 0;
    }
    printf("o: ");
    imprime_lista(o);
    return 1;
}
int main(int argc, char const *argv[])
{
    t_lista l, m, o, c;
    if (!cria_listas(&l, &m, &o, &c))
        return 1;
    if (!testa_insercoes(&l, &m, &o))
        return 1;

    return 0;
}
