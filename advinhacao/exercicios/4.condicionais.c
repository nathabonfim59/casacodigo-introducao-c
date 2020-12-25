#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DE_TENTATIVAS 3 // Quanitdade de vezes que o usuário poderá jogar
#define PONTUACAO_MAXIMA 1000;

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int numeroSecreto = 42;    // Número que o usuário terá de advinhar
    int chute;                 // Tentativa do jogador
    int ganhou = 0;            // Verifica se o usuário acertou o número secreto
    int tentativas = 1;        // Número atual de tentativas do usuário
    double pontos = PONTUACAO_MAXIMA;

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

        int ganhou = chute == numeroSecreto;
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

        int pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;

        tentativas++;

        if (NUMERO_DE_TENTATIVAS < tentativas) {
            printf("Você perdeu, que pena!\n");
            break;
        }
    }

    printf("Você fez %.2f pontos", pontos);
    printf("Fim de jogo!\n");
}