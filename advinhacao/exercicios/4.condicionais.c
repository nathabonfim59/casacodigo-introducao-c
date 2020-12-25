#include <stdio.h>

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int numeroSecreto;
    numeroSecreto = 42;

    int chute;

    for (int i = 1; i <= 3; i++) {
        printf("==================================\n");

        printf("Qual seu chute?\n");
        scanf("%d", &chute);
        printf("Seu %d chute foi: %d\n", i, chute);
        printf("----------------------------------\n");

        int acertou = chute == numeroSecreto;
        
        if (acertou) {
            printf("Parabéns, você acertou!\n");
            break;
        } else {
            
            int maior = chute > numeroSecreto;
            if (maior) {
                printf("O seu chute foi maior que o número secreto.\n");
            } else {
                printf("O seu chute foi menor que o número secreto\n");
            }
        }
    }

    printf("Fim de jogo!\n");
}