#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main() {
    float media;

    Aluno aluno1 = {"Quezia Marcelli", 7.0, 8.8, 4.6};
    
    media = calcularMediaFinal(aluno1);
    printf("A media final do(a) aluno(a) %s eh: %.2f\n", aluno1.nome, media);

    system("pause");
    return 0;
}