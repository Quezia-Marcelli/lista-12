#include <stdio.h>
#include <stdlib.h> 

// Nó que guarda cada elemento da matriz
typedef struct NoMatriz {
    int valor;
    int linha;
    int coluna;
    NoMatriz* proximo; // Ponteiro para o próximo elemento
}NoMatriz;

//A Matriz que aponta para o início da lista de nós
typedef struct {
    NoMatriz* inicio_da_lista;
    int total_linhas;
    int total_colunas;
}Matriz;

// Função para criar uma matriz vazia
void inicializarMatriz(Matriz* m, int linhas, int colunas) {
    m->inicio_da_lista = NULL; // A lista de nós começa vazia
    m->total_linhas = linhas;
    m->total_colunas = colunas;
}

// Função para inserir um valor (um novo nó) na matriz
void inserirValor(Matriz* m, int linha, int coluna, int valor) {
    if (valor == 0) 
        return; // Não guardamos zeros

    // Cria o novo nó
    NoMatriz* novo_no = (NoMatriz*) malloc(sizeof(NoMatriz));
    novo_no->linha = linha;
    novo_no->coluna = coluna;
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    // Insere o nó na lista 
    if (m->inicio_da_lista == NULL) {
        m->inicio_da_lista = novo_no;
    } else {
        novo_no->proximo = m->inicio_da_lista;
        m->inicio_da_lista = novo_no;
    }
}

// Função para imprimir a matriz 
void imprimirMatriz(Matriz m) {
    printf("Matriz %dx%d:\n", m.total_linhas, m.total_colunas);
    for (int i = 0; i < m.total_linhas; i++) {
        for (int j = 0; j < m.total_colunas; j++) {
            NoMatriz* atual = m.inicio_da_lista;
            int valor_encontrado = 0;
            // Procura se existe um nó para a posição (i, j)
            while (atual != NULL) {
                if (atual->linha == i && atual->coluna == j) {
                    printf("%d ", atual->valor);
                    valor_encontrado = 1;
                    break;
                }
                atual = atual->proximo;
            }
            if (!valor_encontrado) {
                printf("0 "); // Imprime 0 se não achou o nó
            }
        }
        printf("\n");
    }
}


int main() {
    Matriz matriz;
    inicializarMatriz(&matriz, 3, 3);

    // Inserindo valores não nulos
    inserirValor(&matriz, 0, 1, 5);  // Linha 0, Coluna 1 = 5
    inserirValor(&matriz, 1, 2, 9);  // Linha 1, Coluna 2 = 9
    inserirValor(&matriz, 2, 0, 3);  // Linha 2, Coluna 0 = 3

    imprimirMatriz(matriz);

    // Liberar a memória alocada 
    struct NoMatriz* atual = matriz.inicio_da_lista;
    while(atual != NULL) {
        struct NoMatriz* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    system("pause");
    return 0;
}