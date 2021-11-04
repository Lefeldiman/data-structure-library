/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 *
 * Considerar os 125 nomes completos gerados na TEA 07, ordenados em ordem alfabética crescente. 
 * Criar um arquivo binário que contenha os 125 nomes completos. 
 * Abrir o arquivo e escrever seu conteúdo na tela.
 * 
 * Created on March 9, 2016, 10:37 PM
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 *  Fazer um programa que gere 125 Nomes completos de pessoas, cada nome com 3 partes (Primeiro, Meio e Sobrenome), a partir dos vetores:

    char Primeiro[5][20] = { "Pedro","Tiago","Ana","Bruno","Camila" };
    char Meio[5][20] = { "Oliveira","Antunes","Ferreira","Santos","Cunha" };
    char Sobrenome[5][20]= { "Cardoso","Silva","Azevedo","Monteiro","Soares" };
    char NomeCompleto[125][60];

    Escrever na tela os 125 nomes completos na ordem gerada.

    Escrever na tela os 125 nomes completos na ordem alfabética crescente.

    Escrever na tela os 125 nomes completos na ordem alfabética decrescente.
 *
 * Created on March 2, 2016, 10:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
#define MAX 1000

typedef struct s_cel{
    int chave;
    char nome[20];
}cel;

typedef struct s_ind{
    int chave, endereco;
}ind;

int particao (ind a[],int l, int r);
int binsrch(ind a[], int x, int low, int high);
void quickSort(ind a[],int l, int r); 
void geraNomeCrescente(int status);
void geraNomeDecrescente(int status);
char tela();

int main() {
    char linha[80];
    char Primeiro[5][20] = {"Pedro", "Tiago", "Ana", "Bruno", "Camila"};
    char Meio[5][20] = {"Oliveira", "Antunes", "Ferreira", "Santos", "Cunha"};
    char Sobrenome[5][20] = {"Cardoso", "Silva", "Azevedo", "Monteiro", "Soares"};
    char vNomeCompleto[125][400];
    char vVazio[2];
    char opcao;
    int sair = 0, i, iPrimeiro, iSegundo, iTerceiro;
    
    FILE *p_arq;
    srand(time(NULL));
    int x,y,posi,opcao,resposta,chave;
    char nome[20];
    cel grava;
    ind index[MAX];
    
    if((p_arq = fopen("reg.txt","wt")) ==NULL){
        printf("Arquivo nao pode ser aberto.");
        getchar();
        exit(1);
    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\n125 Nomes Completos Na Ordem Gerada");
                for (iPrimeiro = 0; iPrimeiro < 5; iPrimeiro++) {
                    for (iSegundo = 0; iSegundo < 5; iSegundo++) {
                        for (iTerceiro = 0; iTerceiro < 5; iTerceiro++) {
                            printf("%s%s %s\n", Primeiro[iPrimeiro], Meio[iSegundo], Sobrenome[iTerceiro]);
                        }
                    }
                }
                printf("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case '2':
                puts("\n125 Nomes Completos Na Ordem Alfabética Crescente");
                //sscanf(linha, "%d", &numero);
                //geraNomeCrescente(numero);
                i=0;
                vVazio[0] = ' ';
                for (iPrimeiro = 0; iPrimeiro < 5; iPrimeiro++) {
                    for (iSegundo = 0; iSegundo < 5; iSegundo++) {
                        for (iTerceiro = 0; iTerceiro < 5; iTerceiro++) {
                                strcat(vNomeCompleto[i], Primeiro[iPrimeiro]);
                                strcat(vNomeCompleto[i],vVazio);
                                strcat(vNomeCompleto[i], Meio[iSegundo]);
                                strcat(vNomeCompleto[i],vVazio);
                                strcat(vNomeCompleto[i], Sobrenome[iTerceiro]);
                                printf("%s \n", vNomeCompleto[i]);
                                i++;
                        }
                    }
                }
                printf("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case '3':
                puts("\n125 Nomes Completos Na Ordem Alfabética Decrescente");
                i=0;
                vVazio[0] = ' ';
                for (iPrimeiro = 0; iPrimeiro < 5; iPrimeiro++) {
                    for (iSegundo = 0; iSegundo < 5; iSegundo++) {
                        for (iTerceiro = 0; iTerceiro < 5; iTerceiro++) {
                                strcat(vNomeCompleto[i], Primeiro[iPrimeiro]);
                                strcat(vNomeCompleto[i],vVazio);
                                strcat(vNomeCompleto[i], Meio[iSegundo]);
                                strcat(vNomeCompleto[i],vVazio);
                                strcat(vNomeCompleto[i], Sobrenome[iTerceiro]);
                                printf("%s \n", vNomeCompleto[i]);
                                i++;
                        }
                    }
                }
                printf("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opção Inválida<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts(">>> Gera 125 Nomes Completos de Pessoas <<<");
    puts("\n[1]>> Escrever Os 125 Nomes na Ordem Gerada \n[2]>> Escrever Os 125 Nomes Completos Na Ordem Alfabética Crescente \n[3]>> Escrever Os 125 Nomes Completos Na Ordem Alfabética Decrescente \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

void quickSort(ind a[],int l, int r){
    int j;
    if(l<r){
        j=particao(a,l,r);
        quickSort(a,l,j-1);
        quickSort(a,j+1,r);
    }
}


int particao (ind a[],int l, int r){
    int i,j;
    ind pivot,t;
    pivot = a[l];
    i = l;
    j = r+1;
    
    while (1){
        do{
            ++i;
        }while (a[i].chave <= pivot.chave && i<= r);
        do{
            --j; 
        }while (a[j].chave> pivot.chave);
        if(i>=j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    
    return j;
}


int binsrch(ind a[], int x, int low, int high){	
    int mid;
	if(low>high)
	   return(-1);
    mid = (low+high) / 2;
	if(x==a[mid].chave)
	   return(a[mid].endereco);
	if(x<a[mid].chave)
	   return(binsrch(a,x,low,mid-1));
	return(binsrch(a,x,mid+1,high));
}