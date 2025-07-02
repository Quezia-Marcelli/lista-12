#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor_inteiro; // Ex: 12.3456 é guardado como 123456
}Decimal;

// Função para criar um decimal a partir de um double
Decimal criarDecimal(double valor_inicial) {
    Decimal d;
    d.valor_inteiro = (int)(valor_inicial * 10000);

    return d;
}

// Função para imprimir o valor
void imprimirDecimal(Decimal d) {
    // Imprime a parte inteira e a parte fracionária
    printf("%d.%04d\n", d.valor_inteiro / 10000, d.valor_inteiro % 10000);
}

// Função para somar dois decimais
Decimal somarDecimais(Decimal d1, Decimal d2) {
    Decimal resultado;
    resultado.valor_inteiro = d1.valor_inteiro + d2.valor_inteiro;

    return resultado;
}

// Função para subtrair dois decimais
Decimal subtrairDecimais(Decimal d1, Decimal d2) {
    Decimal resultado;
    resultado.valor_inteiro = d1.valor_inteiro - d2.valor_inteiro;

    return resultado;
}

int main() {
    Decimal num1 = criarDecimal(15.50);    // Guarda 155000
    Decimal num2 = criarDecimal(5.2550);   // Guarda 52550

    printf("Numero 1: ");
    imprimirDecimal(num1);

    printf("Numero 2: ");
    imprimirDecimal(num2);

    Decimal soma = somarDecimais(num1, num2);
    printf("Soma: ");
    imprimirDecimal(soma); 

    Decimal subtracao = subtrairDecimais(num1, num2);
    printf("Subtracao: ");
    imprimirDecimal(subtracao); 

    system("pause");
    return 0;
}