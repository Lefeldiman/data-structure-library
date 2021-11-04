/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 *  Faça um programa que gere um vetor de 120 reais aleatórios entre 27.3 e 91.8 
    (todos com exatamente uma casa decimal), e Listar os elementos do vetor. 
    Ordenar o vetor em ordem crescente e reescrever o vetor na tela. 
    Gerar uma tabela com todos os inteiros de 28 até 91;
    Ao lado de cada valor inteiro, escrever (duas vezes) se o mesmo pertence ou não ao vetor, 
    usando pesquisa binária (criar e usar uma função Iterativa e outra Recursiva para tal).
 *
 * Created on March 2, 2016, 10:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int somaVetReaisiterativo(int x, int y);
int somaVetReaisRecursivo(int x, int y);
char tela();

int main() {
    char linha[80];
    int soma[100];
    char opcao;
    int sair = 0, a = 0, b = 0, i;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nValores Gerados Em Um Vetor de 120 Reais Aleatórios Entre 27.3 e 91.8 ");
                for (i = 1; i <= 100; i++)
                    printf("%d\n", rand() % 900 + 100);
                soma = rand() % 900 + 100;
                getchar();
                printf("%d",soma);
                //sscanf(linha, "%d", &a);
                //somaVetReaisiterativo(a, b);
                getchar();
                break;
            case '2':
                puts("\nValores gerados em um vetor de 100 inteiros aleatórios entre 100 e 999");
                sscanf(linha, "%d", &a);
                puts("\nDigite um número natual para usar uma função de somaVetReaisplicação usando a soma iTERATiVA");
                sscanf(linha, "%d", &b);
                somaVetReaisiterativo(a, b);
                break;
            case '3':
                puts("\nDigite um número natual para usar uma função de somaVetReaisplicação usando a soma RECURSiVA");
                sscanf(linha, "%d", &a);
                puts("\nDigite um número natual para usar uma função de somaVetReaisplicação usando a soma RECURSiVA");
                sscanf(linha, "%d", &b);
                somaVetReaisRecursivo(a, b);
                printf("\n\n Resultado da somaVetReaisplicação de: %d x %d RECURSiVO é: %d ", a, b, somaVetReaisRecursivo(a, b));
                printf("\n\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opcao inválida<< \n >>Pressione Qualquer Tecla para Voltar<<");
                getchar();
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts(">>>Vetor de Reais com Pesquisa Binária Na Forma iterativa e Recursiva<<<");
    puts("\n[1]>> Gera Vetor de 120 Reais Aleatórios Entre 27.3 e 91.8 \n[2]>> Ordenar Vetor em Ordem Crescente \n[3]>> Gerar Tabela Com Inteiros de 28 até 91 \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int somaVetReaisiterativo(int x, int y) {
    int i, ret = 0;
    for (i = x; i > 0; i--)
        ret += y;
    printf("\n O Resultado da somaVetReaisplicação de: %d x %d iTERATiVO é: %d ", x, y, ret);
    printf("\n\n >>Pressione qualquer tecla para voltar<<");
    getchar();
}

int somaVetReaisRecursivo(int x, int y) {
    if (x == 1)
        return y;
    return (y + somaVetReaisRecursivo(x - 1, y));
}
