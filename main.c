/*
 * To change this license header, choose License Headers in Prolect Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * Fazer um programa que crie uma matriz M de inteiros, na área dinâmica de memória. 
 * A quantidade de linhas e a quantidade de colunas de M devem ser lidas via 
 * teclado. Inicializar cada M[ i ][ l ] com o valor de ( i + l ). 
 * Escrever M na tela, em formato matricial.
 * 
 * Created on February 24, 2016, 11:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"

int main() { 
    char opcao; 
    int sair = 0, linhas,colunas, i, j;
    int **M;
        
    do { 
           opcao = tela(); 
           switch (opcao) { 
                  case 'i': 
                       puts("\nDigite os dados da Linha ....: ");
                       scanf("%d", &linhas);
                       puts("\nDigite os dados da Coluna ...: ");
                       scanf("%d", &colunas);
                       M = (int **) malloc(sizeof(int *) * linhas);
                       for (i = 0; i < linhas; i++)
                       M[i] = (int *) malloc(sizeof(int) * colunas);  
                       for (i = 0; i < linhas; i++)
                       for (j = 0; j < colunas; j++)
                       M[i][j] = i + j;
                       printf("\n\n Matriz Criada : \n\n");
                       for (i = 0; i < linhas; i++)
                       {      for (j = 0; j < colunas; j++)
                       printf("%4d ", M[i][j]);
                       printf("\n\n");
                       getchar();
                        }
                       break; 
                  case 's': 
                       sair = 1; 
                       break; 
                  default: 
                          puts("\nOpcao invalida."); 
                          break; 
           } 
           system("clear");
    } while (!sair); 
}