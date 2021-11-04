/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 *  Escreva rotinas (uma Iterativa e outra Recursiva) que calculem o MDC de dois inteiros usando o Algoritmo de Euclides. 
    Faça um programa que leia e valide dois inteiros positivos e escreva seu MDC duas vezes, usando ambas as rotinas. 
 *
 * Created on March 2, 2016, 10:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int mdcIterativo(int x, int y);
int mdcRecursivo(int x, int y);
char tela();

int main() {
    char linha[80];
    char opcao;
    int sair = 0, um, dois;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nDigite um Número inteiro positivo para calcular o MDC na Forma ITERATIVA");
                scanf("%d", &um);
                puts("\nDigite outro Número inteiro positivo para calcular o MDC na Forma ITERATIVA");
                scanf("%d", &dois);
                mdcIterativo(um, dois);
                break;
            case '2':
                puts("\nDigite um Número inteiro positivo para calcular o MDC na Forma RECURSIVA");
                sscanf(linha, "%d", &um);
                puts("\nDigite um Número inteiro positivo para calcular o MDC na Forma RECURSIVA");
                sscanf(linha, "%d", &dois);
                mdcRecursivo(um, dois);
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opção Inválida<< \n >>Pressione Qualquer Tecla para Voltar<<");
                getchar();
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts(">>>Cálculo do MDC de Dois Inteiros Usando o Algoritmo de Euclides na forma Iterativa e Recursiva<<<");
    puts("\n[1]>> Calcula MDC na forma Iterativa \n[2]>> Calcula MDC na forma Recursiva \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int mdcIterativo(int x, int y) {
    int a, b, z, mdc=0, dividendo=0, divisor=0;

    dividendo = a;
    divisor = b;
    while (z != 0) {
        z = dividendo % divisor;
        dividendo = divisor;
        divisor = z;
    };
    mdc = dividendo;
    return a;
    printf("\n O Resultado da mdcplicação de: %d um %d iTERATiVO é: %d ", a, b, mdc);
    printf("\n\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}

int mdcRecursivo(int x, int y) {
    if (x == 1)
        return y;
    return (y + mdcRecursivo(um - 1, y));
}
