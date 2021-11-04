/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 * Criar uma Lista Encadeada Simples de Inteiros. Para tal, implementar as seguintes operações:            
 * - Inicializar Lista;            
 * - Inserir no TOPO (início) da Lista;            
 * - Inserir na CAUDA (final) da Lista;            
 * - Retirar elemento do TOPO (início) da Lista;            
 * - Retirar elemento da CAUDA (final) da Lista;            
 * - Listar elementos da Lista;            
 * - Lista vazia (V ou F).
 * Criar programa com MENU para testar as operações de inserção, retirada e listagem dos elementos.
 *
 * Created on Marc 22, 2016, 11:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

struct ListaC {
    int data;
    struct ListaC *prox;
};
typedef struct ListaC listac;

char tela();
struct tElemento *cria_no();
void insere(struct tElemento *, int);
void meu_remove(struct tElemento *, int);
void listar(struct tElemento *);

int main() {
    struct tElemento *ptlista;
    char linha[80];
    char opcao;
    int sair = 0, valor;

    ptlista = cria_no();
    listac->prox = listac;


    do {
        opcao = tela();
        switch (opcao) {
            case 'i':
                puts("Qual dado a inserir?");
                gets(linha);
                sscanf(linha, "%d", &valor);
                insere(ptlista, valor);
                break;
            case 'r':
                puts("Qual dado a remover?");
                gets(linha);
                sscanf(linha, "%d", &valor);
                meu_remove(ptlista, valor);
                break;
            case 'l':
                listar(ptlista);
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("Opcao invalida.");
                break;
        }
    } while (!sair);
}

char tela () 
{ 
     char opcao, linha[80]; 
     puts("Lista Encadeada Simples de Inteiros"); 
     puts("\n[1]>> Inserir Dado \n[2]>> Remover Dado, \n[3]>> Listar Dado, \n[S]air"); 
     fgets(linha,sizeof(linha),stdin); 
     sscanf(linha, "%c", &opcao); 
     return tolower(opcao); 
}

void listar(struct tElemento *ptlista) {

    int i = 0;
    struct tElemento *pont;

    pont = ptlista->prox;
    while (pont != ptlista) {
        printf("Elemento %d = %d\n", i++, pont->info);
        pont = pont->prox;
    }
}

void insere(struct tElemento *ptlista, int valor) {

    struct tElemento *pont, *ant, *pt;

    /* Aqui esta o algoritmo de busca em uma lista circular */

    ant = ptlista;
    pont = ptlista->prox;
    ptlista->info = valor;

    while (pont->info < valor) {
        ant = pont;
        pont = pont->prox;
    }
    if (pont->info == valor && pont != ptlista)
        puts("Elemento ja existe na tabela.");
    else {
        pt = cria_no();
        pt->info = valor;
        pt->prox = pont;
        ant->prox = pt;
    }
}

void insereCircularnaOrdem(cel **P_L, int dado) {
    listac *tmp, tmp2;

    if (*P_l) == NULL) {
            (*P_l) = criacel(dado);
            (*P_l) = prox = (*P_l);
            return;
        }
    tmp = (*P_l);
    while (tmp->prox->val > tmp->val)
        tm = tmp->prox;
    if ((dado > tmp->val)if (dado < tmp->prox - val)) {
            tmp2 = criacel(dado);
            tmp2->prox = tmp->prox;
            tmp->prox = tmp2;
            return;
        }
    tmp = tmp->prox;
    while (tmp->prox->val < dado)
        return;
    tmp2 = criacel(dado);
    tmp2->prox = tmp->prox;
    tmp->prox = tmp2;
    (*P_l) = tmp2;
}



void meu_remove(struct tElemento *ptlista, int valor) {
    struct tElemento *pont, *ant;

    ant = ptlista;
    pont = ptlista->prox;
    ptlista->info = valor;

    while (pont->info < valor) {
        if (pont->info < valor) {
            ant = pont;
            pont = pont->prox;
        }
    }

    if (pont->info == valor && pont != ptlista) {
        ant->prox = pont->prox;
        free(pont);
    }
    else puts("Elemento nao existe na tabela.");
}