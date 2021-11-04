/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * typedef struct {                          

                             char titulo[100];                       

                             int  codigo;              

                      } livro;
   Considerando a estrutura acima, faça um programa que aloque dinamicamente  
 * um vetor de “linhas” com 5 posições e que alimente esse vetor 
 * (lendo  do teclado os dados) e depois o liste na tela. 
 * Created on February 24, 2016, 11:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"

int main() { 
    char linhas[80]; 
    char opcao; 
    int sair = 0, LINHA[5], st, i, l;
        
    do { 
           opcao = tela(); 
           switch (opcao) { 
                  case 'i': 
                       puts("\nDigite os Livros ....: "); puts("\nDigite <999> Para Sair"); fgets(linhas,sizeof(linhas),stdin);; 
                      for(i=0;i!=4;i++)
                       {
                       sscanf(linhas, "%c", &LINHA);
                       }
                       printf("\nLivros >>>> ",LINHA);
                       getchar();
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