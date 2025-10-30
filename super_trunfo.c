#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país
typedef struct {
    char nome[50];
    float populacao;          // em milhões
    float area;               // km²
    float pib;                // bilhões de USD
    float densidade;          // habitantes/km²
} Carta;

// Função para exibir atributos de uma carta
void mostrarCarta(Carta c) {
    printf("País: %s\n", c.nome);
    printf("1 - População: %.2f milhões\n", c.populacao);
    printf("2 - Área: %.2f km²\n", c.area);
    printf("3 - PIB: %.2f bilhões USD\n", c.pib);
    printf("4 - Densidade Demográfica: %.2f hab/km²\n", c.densidade);
}

// Função para obter valor do atributo escolhido
float valorAtributo(Carta c, int atributo) {
    switch(atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

// Função para mostrar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213.0, 8516.0, 1445.0, 25.0};
    Carta carta2 = {"Argentina", 45.0, 2780.0, 645.0, 16.0};

    int atributo1, atributo2;
    
    printf("Escolha os dois atributos para comparar as cartas:\n");
    
    // Menu do primeiro atributo
    do {
        printf("Escolha o primeiro atributo:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Demográfica\n");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 4);

    // Menu do segundo atributo, sem permitir repetir o primeiro
    do {
        printf("Escolha o segundo atributo (não pode ser igual ao primeiro):\n");
        for(int i = 1; i <=4; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Valores dos atributos escolhidos
    float val1Carta1 = valorAtributo(carta1, atributo1);
    float val1Carta2 = valorAtributo(carta2, atributo1);
    float val2Carta1 = valorAtributo(carta1, atributo2);
    float val2Carta2 = valorAtributo(carta2, atributo2);

    // Soma dos atributos
    float somaCarta1 = val1Carta1 + val2Carta1;
    float somaCarta2 = val1Carta2 + val2Carta2;

    // Exibição organizada dos resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("%-15s | %-10s | %-10s\n", "País", nomeAtributo(atributo1), nomeAtributo(atributo2));
    printf("%-15s | %-10.2f | %-10.2f\n", carta1.nome, val1Carta1, val2Carta1);
    printf("%-15s | %-10.2f | %-10.2f\n", carta2.nome, val1Carta2, val2Carta2);
    printf("Soma dos atributos: %s = %.2f | %s = %.2f\n", carta1.nome, somaCarta1, carta2.nome, somaCarta2);

    // Determinar vencedor
    if (somaCarta1 > somaCarta2) {
        printf("Vencedor: %s!\n", carta1.nome);
    } else if (somaCarta2 > somaCarta1) {
        printf("Vencedor: %s!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
