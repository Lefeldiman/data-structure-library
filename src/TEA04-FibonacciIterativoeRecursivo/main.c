/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 *  a) Fazer um programa que escreva na tela a seqüência de Fibonacci de 0 até 45.

    b) Em seguida, escrevê-la novamente, usando uma função iterativa que retorne o resultado na seqüência de um inteiro 
 *  recebido como parâmetro (aplicar a função para os 46 numeroes).

    c) Em seguida, escrevê-la novamente, usando uma função recursiva que retorne o resultado na seqüência de um inteiro 
 *  recebido como parâmetro (aplicar a função para os 46 numeroes).

    Obs. A seqüência de Fibonacci é assim definida :

    Fib(0) = 1 , por definição
    Fib(1) = 1 , por definição
    Fib(2) = 2
    Fib(3) = 3
    Fib(4) = 5
    Fib(5) = 8
    Fib(6) = 13
    Fib(N) = Fib(N-2) + Fib(N-1)

 * Created on March 2, 2016, 10:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

int fibonacciIterativo(int numero);
int fibonacciRecursivo(int numero);
char tela();

int main() {
    char linha[80];
    char opcao;
    int sair = 0, numero;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nDigite um número para Gerar a Sequencia de Fibonacci");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &numero);
                fibonacciIterativo(numero);
                break;
            case '2':
                puts("\nDigite um número para Gerar a Sequencia de Fibonacci usando uma função iterativa");
                sscanf(linha, "%d", &numero);
                fibonacciIterativo(numero);
                break;
            case '3':
                puts("\nDigite um número para Gerar a Sequencia de Fibonacci usando uma função recursiva");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &numero);
                fibonacciRecursivo(numero);
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opcao Invalida<<");
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts("Seqüência de Fibonacci de 0 até 45");
    puts("\n[1]>> Gera Sequencia \n[2]>> Escreve na Forma Iterativa, \n[3]>> Escreve na forma Recursiva, \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int fibonacciIterativo(int numero) {
    int fib = 0, fibn_2 = 1, auxiliar, i, n;
    printf("Série de Fibonacci:\n");
    printf("%d\n", fibn_2);
    for (i = 0; i <= numero; i++) {
        auxiliar = fib + fibn_2;
        fib = fibn_2;
        fibn_2 = auxiliar;
        printf("%d\n", auxiliar);
    }
    printf("\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}

int fibonacciRecursivo(int numero) {
    if ((numero == 0) || (numero == 1)) return 1;
    return (fibonacciRecursivo(numero - 2) + fibonacciRecursivo(numero - 1));

    printf("\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}