#include <stdio.h>

int main() {
    // Mostra a tela de boas-vindas
    printf("***********************************\n");
    printf("* Bem-vindo ao jovo de Advinhação *\n");
    printf("***********************************\n");

    int numeroSecreto;
    numeroSecreto = 42;

    int chute;

    printf("Qual seu chute?\n");
    scanf("%d", &chute);
    printf("Você chutou o número: %d\n", chute);
}