/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   function.h
 * Author: inethosted
 *
 * Created on February 29, 2016, 11:34 PM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

void inserir(int VAL1, int VAL2);
char tela ();

char tela () 
{ 
     char opcao, linha[80]; 
     puts("\n>>> Matriz <<<"); 
     puts("\n[I]nserir \n[L]istar, \n[S]air"); 
     fgets(linha,sizeof(linha),stdin); 
     sscanf(linha, "%c", &opcao); 
     return tolower(opcao); 
}

void inserir(int VAL1, int VAL2)
{
int i = 0, j =0;
int matriz[i][j];

for(i=0;i<VAL1;i++) { // fixa o indice da linha
for(j=0;j<VAL2;j++) {
printf("%5d",matriz[i][j]) ;
}
putchar('\n') ; // '\n' no final de cada linha
}
}

#ifdef __cplusplus
}
#endif

#endif /* FUNCTION_H */

