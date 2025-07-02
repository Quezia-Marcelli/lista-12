#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_ALUNOS 30

typedef struct {
    char nome[100];
    float nota_ex;
    float nota_prova1;
    float nota_prova2;
}Aluno;

float calcularMediaFinal(Aluno x) {
    float mediaProvas = ((x.nota_prova1 * 0.4) + (x.nota_prova2 * 0.6));
    float mediaFinal = (mediaProvas * 0.8) + (x.nota_ex * 0.2);

    return mediaFinal;
}

typedef struct {
    Aluno lista_alunos[MAXIMO_ALUNOS]; //vetor de tamanho 30 (MAXIMO_ALUNOS)
    int quantidade_alunos; //controla a quantidade 
}Turma;

void imprimirMediasDaTurma(Turma t) {
    float media;
    printf("Medias da Turma: \n");
    for (int i = 0; i < t.quantidade_alunos; i++) {
        // Pega o aluno atual da lista
        Aluno aluno_atual = t.lista_alunos[i];
        // Calcula a média do aluno atual
        media = calcularMediaFinal(aluno_atual);
        // Imprime
        printf("Aluno: %s | Media Final: %.2f\n", aluno_atual.nome, media);
    }
    printf("\n");
}


int main() {
    Turma turmaAtp;
    turmaAtp.quantidade_alunos = 0; // Começa com 0 alunos

    // Aluno 1
    strcpy(turmaAtp.lista_alunos[0].nome, "Quezia Marcelli");
    turmaAtp.lista_alunos[0].nota_ex = 7.0;
    turmaAtp.lista_alunos[0].nota_prova1 = 8.8;
    turmaAtp.lista_alunos[0].nota_prova2 = 4.6;
    turmaAtp.quantidade_alunos ++; // Incrementa a quantidade de alunos

    // Aluno 2
    strcpy(turmaAtp.lista_alunos[1].nome, "Ana Julia");
    turmaAtp.lista_alunos[1].nota_ex = 9.2;
    turmaAtp.lista_alunos[1].nota_prova1 = 7.6;
    turmaAtp.lista_alunos[1].nota_prova2 = 5.9;
    turmaAtp.quantidade_alunos ++;

    //Aluno 3
    strcpy(turmaAtp.lista_alunos[2].nome, "Bruno Souza");
    turmaAtp.lista_alunos[2].nota_ex = 10;
    turmaAtp.lista_alunos[2].nota_prova1 = 9.3;
    turmaAtp.lista_alunos[2].nota_prova2 = 7.5;
    turmaAtp.quantidade_alunos ++;

    // Chama a função para imprimir as médias
    imprimirMediasDaTurma(turmaAtp);

    system("pause");
    return 0;
}