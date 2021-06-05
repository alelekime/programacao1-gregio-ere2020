#include <stdio.h>
#include <stdbool.h>

void leituraVetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

bool verificaVetor(int *sequenciaUm, int *sequenciaDois, int n)
{
    bool diferente = false;
    int i = 0;
    while (i < n && !diferente)
    {
        if (sequenciaUm[i] != sequenciaDois[i])
        {
            diferente = true;
        }
        i++;
    }
    return diferente;
}

int main()
{
    int n;
    scanf("%d", &n);

    int sequenciaUm[n];
    int sequenciaDois[n];
    printf("LEITURA: insira o dados do primeiro vetor \n");
    leituraVetor(sequenciaUm, n);
    printf("LEITURA: insira o dados do segunda vetor \n");
    leituraVetor(sequenciaDois, n);

    if (!verificaVetor(sequenciaUm, sequenciaDois, n))
    {
        printf("SIM, são iguais");
    }
    else
    {
        printf("Não, são diferentes");
    }
}
