#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 3 // Quanitdade de vezes que o usuário poderá jogar

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int numeroSecreto;    // Número que o usuário terá de advinhar
    numeroSecreto = 42;

    int chute;            // Tentativa do jogador

    // Loop principal do jogo
    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
        printf("==================================\n");

        printf("Qual seu chute?\n");
        scanf("%d", &chute);
        printf("Seu %d chute foi: %d\n", i, chute);
        printf("----------------------------------\n");

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;
        
        if (acertou) {
            printf("Parabéns, você acertou!\n");
            break;
        // Caso o usuário não acerte, mostra uma "dica" a ele
        } else if (maior) { 
            printf("O seu chute foi maior que o número secreto.\n");
        } else {
            printf("O seu chute foi menor que o número secreto\n");
        }
    }

    printf("Fim de jogo!\n");
}