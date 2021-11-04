/* 
 * File:   main.c
 * Author: siad02
 *
 * Created on 25 de Abril de 2016, 17:26
 */

//      Questão 4  
//Faça um programa que crie um arquivo Texto, contendo 5000 números inteiros 
//aleatórios entre 10 e 999. Para a gravação no arquivo texto, cada linha 
//deve conter apenas 10 valores.

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
int main ()
{  FILE *f;   int z;  srand(time(NULL));   
   f = fopen("Questao4.txt", "w");
   for (z=1;z<=5000;z++) 
   {    fprintf(f, "%7d", rand() % 990 + 10);
        if(z % 10 == 0)   fprintf(f, "\n");   
   } 
   fclose(f);   
   printf("Arquivo Texto 'Questao4.txt' gravado com 5000 numeros inteiros aleatorios entre 10 e 999.");
   printf("\n\nPressione qualquer tecla para TERMINAR o programa ...  ");        
   getchar();    return 0;
}
