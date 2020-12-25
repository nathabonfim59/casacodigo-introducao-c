#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 3 // Quanitdade de vezes que o usuário poderá jogar

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int numeroSecreto = 42;    // Número que o usuário terá de advinhar
    int chute;                 // Tentativa do jogador
    int ganhou = 0;            // Verifica se o usuário acertou o número secreto
    int tentativas = 1;        // Número atual de tentativas do usuário

    // Loop principal do jogo
    while (!ganhou) {
        printf("Qual seu chute?\n");
        scanf("%d", &chute);
        printf("Seu %d chute foi: %d\n", tentativas, chute);
        printf("----------------------------------\n");

        if (chute < 0) {
            printf("Você não pode chutar números negativos\n");
            tentativas--;
            continue;
        }

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;
        
        if (ganhou) {
            printf("Parabéns, você acertou!\n");
            break;
        // Caso o usuário não acerte, mostra uma "dica" a ele
        } else if (maior) { 
            printf("O seu chute foi maior que o número secreto.\n");
        } else {
            printf("O seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        if (NUMERO_DE_TENTATIVAS < tentativas) {
            printf("Você perdeu, que pena!\n");
            break;
        }
    }

    printf("Fim de jogo!\n");
}