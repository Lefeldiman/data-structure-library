/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   function.h
 * Author: inethosted
 *
 * Created on March 1, 2016, 12:00 AM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

void listar(char livro);
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

#ifdef __cplusplus
}
#endif

#endif /* FUNCTION_H */

