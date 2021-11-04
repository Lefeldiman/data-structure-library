/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 * Escreva rotinas que façam a multiplicação de dois números naturais de forma iterativa e recursiva (usando só a adição). 
 * Faça um programa que leia e valide dois naturais e escreva seu produto duas vezes (usando ambas as rotinas).

 *
 * Created on March 2, 2016, 10:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int multiIterativo(int x, int y);
int multiRecursivo(int x, int y);
char tela();

int main() {
    char linha[80];
    char opcao;
    int sair = 0, a = 0, b = 0;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nDigite um número natual para usar uma função de multiplicação usando a soma ITERATIVA");
                sscanf(linha, "%d", &a);
                puts("\nDigite um número natual para usar uma função de multiplicação usando a soma ITERATIVA");
                sscanf(linha, "%d", &b);
                multiIterativo(a, b);
                break;
            case '2':
                puts("\nDigite um número natual para usar uma função de multiplicação usando a soma RECURSIVA");
                sscanf(linha, "%d", &a);
                puts("\nDigite um número natual para usar uma função de multiplicação usando a soma RECURSIVA");
                sscanf(linha, "%d", &b);
                multiRecursivo(a, b);
                printf("\n\n Resultado da multiplicação de: %d x %d RECURSIVO é: %d ", a, b, multiRecursivo(a, b));
                printf("\n\n >>Pressione qualquer tecla para voltar<<");
                getchar();
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
    puts(">>>Multiplicação de dois números naturais de forma Iterativa e Recursiva<<<");
    puts("\n[1]>> Multiplica Somando dois números de forma Iterativa \n[2]>> Multiplica Somando dois números de forma Recursiva, \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int multiIterativo(int x, int y) {
    int i, ret = 0;
    for (i = x; i > 0; i--)
        ret += y;
    printf("\n O Resultado da multiplicação de: %d x %d ITERATIVO é: %d ", x, y, ret);
    printf("\n\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}

int multiRecursivo(int x, int y) {
    if (x == 1)
        return y;
    return (y + multiRecursivo(x - 1, y));
}