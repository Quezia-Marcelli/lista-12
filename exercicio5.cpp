#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representa um produto
typedef struct {
    char nome[50];
    float preco;
    int qtdVendida;
} Produto;

// Representa o menu
typedef struct {
    Produto* itens; // Ponteiro para uma lista de produtos
    int totalItens;
} Menu;

// Inicializa o menu a partir de um arquivo
void inicializarMenu(Menu* cardapio, const char* arquivo) {
    FILE* arquivoMenu = fopen(arquivo, "r");
    if (arquivoMenu == NULL) {
        printf("Erro ao abrir ao arquivo!\n");
        exit(1); // Encerra o programa se o arquivo não for encontrado
    }

    // Lê o número total de itens do menu
    fscanf(arquivoMenu, "%d", &cardapio->totalItens);

    // Aloca memória dinamicamente para a lista de produtos
    cardapio->itens = (Produto*) malloc(cardapio->totalItens * sizeof(Produto));
    if (cardapio->itens == NULL) {
        printf("Erro ao alocar!\n");
        exit(1);
    }

    // Lê os itens do arquivo e preenche a lista de produtos
    for (int i = 0; i < cardapio->totalItens; i++) {
        fscanf(arquivoMenu, "%s %f", cardapio->itens[i].nome, &cardapio->itens[i].preco);
        cardapio->itens[i].qtdVendida = 0; // Inicializa a quantidade vendida como 0
    }

    fclose(arquivoMenu);
}

int main() {
    // Declara uma variável do tipo Menu
    Menu cardapio;

    // Chama a função para carregar os dados do menu.txt para a struct
    inicializarMenu(&cardapio, "menu.txt");

    // Imprime o menu na tela
    printf("\nMENU:\n");
    for (int i = 0; i < cardapio.totalItens; i++) {
        printf("%d - %s (R$ %.2f)\n", i + 1, cardapio.itens[i].nome, cardapio.itens[i].preco);
    }
    printf("\n");

    //cliente fazer o pedido
    int opcaoItem, quantidade;
    do {
        printf("Digite o numero do item (0 para finalizar): ");
        scanf("%d", &opcaoItem);

        if (opcaoItem > 0 && opcaoItem <= cardapio.totalItens) {
            printf("Quantidade de %s: ", cardapio.itens[opcaoItem - 1].nome);
            scanf("%d", &quantidade);
            // Atualiza a quantidade vendida do produto específico
            cardapio.itens[opcaoItem - 1].qtdVendida += quantidade;
        } else if (opcaoItem != 0) {
            printf("Item invalido.\n");
        }
    } while (opcaoItem != 0);

    // Geração do boleto
    FILE *boleto = fopen("boleto.txt", "w");
    if (boleto == NULL) {
        printf("Erro ao criar o arquivo\n");
        return 1;
    }

    float valorTotal = 0;
    fprintf(boleto, "BOLETO:\n");
    for (int i = 0; i < cardapio.totalItens; i++) {
        if (cardapio.itens[i].qtdVendida > 0) {
            float subtotal = cardapio.itens[i].qtdVendida * cardapio.itens[i].preco;
            fprintf(boleto, "%s x%d - R$ %.2f\n", cardapio.itens[i].nome, cardapio.itens[i].qtdVendida, subtotal);
            valorTotal += subtotal;
        }
    }
    fprintf(boleto, "\n");
    fprintf(boleto, "TOTAL: R$ %.2f\n", valorTotal);
    fprintf(boleto, "\n");

    fclose(boleto);

    printf("\nBoleto gerado em 'boleto.txt'.\n");

    // Libera a memória que foi alocada para a lista de itens
    free(cardapio.itens);

    system("pause");
    return 0;
}