#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NIVEL_FACIL_TENTATIVAS 15 // Quanitdade de vezes que o usuário poderá jogar
#define NIVEL_MEDIO_TENTATIVAS 7 // Quanitdade de vezes que o usuário poderá jogar
#define NIVEL_DIFICIL_TENTATIVAS 3 // Quanitdade de vezes que o usuário poderá jogar
#define PONTUACAO_MAXIMA 1000; // Quantidade máxima de pontos disponíveis

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int nivel;
    int totalDeTentativas;

    printf("-----------------------------------\n");
    printf("|  Qual o nível de dificuldade?   |\n");
    printf("-----------------------------------\n");
    printf(" (1) Fácil  (2) Médio  (3) Difícil\n");
    printf("Escolha: \n");
    scanf("%d", &nivel);

    switch (nivel) {
    case 1:
        totalDeTentativas = NIVEL_FACIL_TENTATIVAS;
        break;
    case 2:
        totalDeTentativas = NIVEL_MEDIO_TENTATIVAS;
        break;
    case 3:
        totalDeTentativas = NIVEL_DIFICIL_TENTATIVAS;
        break;
    
    default:
        totalDeTentativas = NIVEL_FACIL_TENTATIVAS;
        break;
    }


    int numeroSecreto;
    numeroSecreto = 42;

    int chute;

    for (int i = 1; i <= totalDeTentativas; i++) {
        int segundos = time(0);
        srand(segundos);
        int numeroAleatorio = rand();

        int numeroSecreto = numeroAleatorio % 100;    // Número que o usuário terá de advinhar
        int chute;                                    // Tentativa do jogador
        int ganhou = 0;                               // Verifica se o usuário acertou o número secreto
        int tentativas = 1;                           // Número atual de tentativas do usuário
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
                printf("Você fez %.2f pontos", pontos);
                exit(0);
            // Caso o usuário não acerte, mostra uma "dica" a ele
            } else if (maior) { 
                printf("O seu chute foi maior que o número secreto.\n");
            } else {
                printf("O seu chute foi menor que o número secreto\n");
            }

            int pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
            pontos = pontos - pontosPerdidos;

            tentativas++;

            if (totalDeTentativas < tentativas) {
                printf("Você perdeu, que pena!\n");
                printf("O número secreto era: %d\n", numeroSecreto);
                exit(0);
            }
        }
    }

    printf("Fim de jogo!\n");
    exit(0);
}
