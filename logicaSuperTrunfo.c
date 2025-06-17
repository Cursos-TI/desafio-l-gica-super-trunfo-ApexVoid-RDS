#include <stdio.h>
#include <string.h>

// Estrutura de carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função auxiliar para mostrar menu de atributos
void mostrarAtributosDisponiveis(int excluido) {
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    struct Carta carta1 = {"Brasil", 203000000, 8515767.0, 2200.5, 45, 0};
    struct Carta carta2 = {"Argentina", 46000000, 2780400.0, 600.75, 25, 0};

    // Cálculo de densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int atributo1 = 0, atributo2 = 0;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("===== Super Trunfo - Comparação com 2 Atributos =====\n\n");

    // Escolha do primeiro atributo
    do {
        printf("Escolha o PRIMEIRO atributo para comparar:\n");
        mostrarAtributosDisponiveis(0);
        printf("Opção: ");
        scanf("%d", &atributo1);
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo (sem repetir)
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        mostrarAtributosDisponiveis(atributo1);
        printf("Opção: ");
        scanf("%d", &atributo2);
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Função auxiliar para obter o valor de um atributo de uma carta
    float obterValor(struct Carta c, int atributo) {
        switch (atributo) {
            case 1: return (float)c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return (float)c.pontosTuristicos;
            case 5: return c.densidadeDemografica;
            default: return 0;
        }
    }

    // Obter os valores dos atributos escolhidos para ambas as cartas
    valor1_carta1 = obterValor(carta1, atributo1);
    valor1_carta2 = obterValor(carta2, atributo1);
    valor2_carta1 = obterValor(carta1, atributo2);
    valor2_carta2 = obterValor(carta2, atributo2);

    // Mostrar dados
    printf("\n===== Comparação =====\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n", carta2.nomePais);
    printf("\nAtributo 1 escolhido: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica (menor vence)\n"); break;
    }

    printf("%s: %.2f | %s: %.2f\n", carta1.nomePais, valor1_carta1, carta2.nomePais, valor1_carta2);

    printf("\nAtributo 2 escolhido: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica (menor vence)\n"); break;
    }

    printf("%s: %.2f | %s: %.2f\n", carta1.nomePais, valor2_carta1, carta2.nomePais, valor2_carta2);

    // Cálculo da pontuação final (respeitando regra da densidade)
    float pontuacao_carta1 = 0, pontuacao_carta2 = 0;

    // Comparação atributo 1
    if (atributo1 == 5) {
        pontuacao_carta1 += valor1_carta1 < valor1_carta2 ? valor1_carta1 : 0;
        pontuacao_carta2 += valor1_carta2 < valor1_carta1 ? valor1_carta2 : 0;
    } else {
        pontuacao_carta1 += valor1_carta1 > valor1_carta2 ? valor1_carta1 : 0;
        pontuacao_carta2 += valor1_carta2 > valor1_carta1 ? valor1_carta2 : 0;
    }

    // Comparação atributo 2
    if (atributo2 == 5) {
        pontuacao_carta1 += valor2_carta1 < valor2_carta2 ? valor2_carta1 : 0;
        pontuacao_carta2 += valor2_carta2 < valor2_carta1 ? valor2_carta2 : 0;
    } else {
        pontuacao_carta1 += valor2_carta1 > valor2_carta2 ? valor2_carta1 : 0;
        pontuacao_carta2 += valor2_carta2 > valor2_carta1 ? valor2_carta2 : 0;
    }

    printf("\n===== Resultado Final =====\n");
    printf("Soma dos valores (considerando quem venceu cada atributo):\n");
    printf("%s: %.2f\n", carta1.nomePais, pontuacao_carta1);
    printf("%s: %.2f\n", carta2.nomePais, pontuacao_carta2);

    // Resultado da comparação geral
    (pontuacao_carta1 > pontuacao_carta2) ? 
        printf("\nVencedor: %s\n", carta1.nomePais) :
    (pontuacao_carta2 > pontuacao_carta1) ?
        printf("\nVencedor: %s\n", carta2.nomePais) :
        printf("\nEmpate!\n");

    return 0;
}