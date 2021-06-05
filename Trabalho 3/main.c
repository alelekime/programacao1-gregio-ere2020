#include "func.h"

int main() {
    int n;
    imprimeExemplo();
    printf("Insira o numero de elementos : ");
    scanf("%d", &n);

    int sequenciaUm[n];
    int sequenciaDois[n];

    printf("LEITURA: insira o dados do primeiro vetor \n");
    leituraVetor(sequenciaUm, n);
    printf("LEITURA: insira o dados do segunda vetor \n");
    leituraVetor(sequenciaDois, n);

    if (!verificaVetor(sequenciaUm, sequenciaDois, n))
    {
        printf("SIM, são iguais\n");
    }
    else
    {
        printf("Não, são diferentes\n");
    }
}
