/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 * Faça um programa que gere 20 valores inteiros entre -15 e 30. 
 * Fazer uma tabela de potências onde cada linha tenha um numero gerado e seu valor elevado a 5.
   Para efeito didático, faça uma função iterativa que receba uma Base e um Expoente inteiros, e retorne o valor da Base elevada ao Expoente.
   Também para efeito didático, faça uma função recursiva que receba uma Base e um Expoente inteiros, e retorne o valor da Base elevada ao Expoente.
   Ao final do programa, comparar os resultados com a aplicação de pow.
 *
 * Created on March 2, 2016, 10:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int potenciaIterativo(int base, int expoente);
int potenciaRecursivo(int base, int expoente);
char tela();

int main() {
    char linha[80];
    char opcao;
    int sair = 0, x, y;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nDigite um número Para elevá-lo a 5");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &x);
                y = exp(x);
                printf("\n A potência de de: %d é igual a:%d ", x, y);
                printf("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case '2':
                puts("\nDigite a base da potência usando uma função ITERATIVA");
                sscanf(linha, "%d", &x);
                puts("\nDigite o expoente da potência usando uma função ITERATIVA");
                sscanf(linha, "%d", &y);
                potenciaIterativo(x, y);
                break;
            case '3':
                puts("\nDigite a base da potência usando uma função RECURSIVA");
                sscanf(linha, "%d", &x);
                puts("\nDigite o expoente da potência usando uma função RECURSIVA");
                sscanf(linha, "%d", &y);
                potenciaRecursivo(x, y);
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opcao Inválida<<");
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts("Seqüência de Fibonacci de 0 até 45");
    puts("\n[1]>> Gera Potência elevado a 5 \n[2]>> Potência Iterativa, \n[3]>> Potência Recursiva, \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int potenciaIterativo(int base, int expoente) {
    int p;
    p = pow(base, expoente);
    printf("\n A potência de de: %d^%d é igual a:%d ", base, expoente, p);
    printf("\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}

int potenciaRecursivo(int base, int expoente) {
    int p;
    p = pow(base, expoente);
    printf("\n A potência de de: %d^%d é igual a: %d", base, expoente, p);
    printf("\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}