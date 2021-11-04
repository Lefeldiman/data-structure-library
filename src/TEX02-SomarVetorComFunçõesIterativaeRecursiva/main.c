/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 *  Faça um programa que gere um vetor de 100 inteiros aleatórios entre 100 e 999. 
    Listar os elementos do vetor. 
    Calcular e escrever a vetor dos elementos do vetor de duas formas: 
    Usando uma função iterativa e usando uma função Recursiva.
 *
 * Created on March 2, 2016, 10:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int vetorVetRecursivo(int x, int y);
char tela();

int main() {
    int vetor[100];
    char opcao;
    int sair = 0, a = 0, b = 0, i, soma;

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nValores gerados em um vetor de 100 inteiros aleatórios entre 100 e 999");
                for (i = 1; i <= 100; i++){
                    printf("%d\n", rand() % 900 + 100);
                vetor[i] = rand() % 900 + 100;
                }
                puts("\n >>Pressione Qualquer Tecla para Voltar<<");
                getchar();
                
                break;
            case '2':
                puts("\nA Soma dos Valores gerados do Vetor de 100 inteiros aleatórios entre 100 e 999");
                for (i = 1; i <= 100; i++) {
                    printf("Vetor Na Posição [%d] = %d\n", i, vetor[i]);
                    soma = soma + vetor[i];
                }
                printf("\n\nA Soma do Vetor = %d", soma);
                puts("\n\n>>Pressione Qualquer Tecla para Voltar<<");
                getchar();
                break;
            case '3':
                vetorVetRecursivo(a, b);
                printf("\n\n Resultado da vetorVetplicação de: %d x %d RECURSiVO é: %d ", a, b, vetorVetRecursivo(a, b));
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
    puts(">>>Gera Vetor De 100 inteiros Aleatórios Entre 100 e 999 e Soma Na Forma iterativa e Recursiva<<<");
    puts("\n[1]>> Gera Vetor de 100 inteiros \n[2]>> Soma Vetor Na Forma iterativa \n[3]>> Soma Vetor Na Forma Recursiva, \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}


int vetorVetRecursivo(int x, int y) {
    if (x == 1)
        return y;
    return (y + vetorVetRecursivo(x - 1, y));
}
