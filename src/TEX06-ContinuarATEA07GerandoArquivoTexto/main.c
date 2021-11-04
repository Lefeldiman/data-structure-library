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
 * Criar um arquivo texto que contenha os 125 nomes completos; 
 * Um nome completo em cada linha do arquivo; 
 * Abrir o arquivo e escrever seu conteúdo na tela;
 * 
 * Created on March 9, 2016, 10:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef struct reg {
    char vNomeComp[125];
    int status;
} tag;

void listagem(int status);
char tela();

int main() {
    struct reg vNome;
    char linha;
    char Primeiro[5][20] = {"Pedro", "Tiago", "Ana", "Bruno", "Camila"};
    char Meio[5][20] = {"Oliveira", "Antunes", "Ferreira", "Santos", "Cunha"};
    char Sobrenome[5][20] = {"Cardoso", "Silva", "Azevedo", "Monteiro", "Soares"};
    char vNomeCompleto[125][400];
    char vFlag[1];
    char vVazio[2];
    char opcao;
    int sair = 0, i, st, iPrimeiro, iSegundo, iTerceiro, valor;


    FILE *arq;
    arq = fopen("nomes.txt", "r");
    if (arq == NULL) {
        arq = fopen("nomes.txt", "a+");
        fclose(arq);
    } else {
        fclose(arq);
    }

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nMostrar os Nomes Sem Armazenar \n >>>Aguarde<<<");
                //fgets(linha, sizeof (linha), stdin);;
                i = 0;
                vVazio[0] = ' ';
                vFlag[0] = '1';
                for (iPrimeiro = 0; iPrimeiro < 5; iPrimeiro++) {
                    for (iSegundo = 0; iSegundo < 5; iSegundo++) {
                        for (iTerceiro = 0; iTerceiro < 5; iTerceiro++) {
                            strcpy(vNomeCompleto[i], Primeiro[iPrimeiro]);
                            strcat(vNomeCompleto[i], vVazio);
                            strcat(vNomeCompleto[i], Meio[iSegundo]);
                            strcat(vNomeCompleto[i], vVazio);
                            strcat(vNomeCompleto[i], Sobrenome[iTerceiro]);
                            printf("%s \n", vNomeCompleto[i]);
                            i++;
                        }
                    }
                }
                printf("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case '2':
                puts("\n>> Armazenar 125 Nomes dentro do Arquivo txt");
                //fgets(linha, sizeof (linha), stdin);;
                arq = fopen("nomes.txt", "a+");
                i = 0;
                vVazio[0] = ' ';
                for (iPrimeiro = 0; iPrimeiro < 5; iPrimeiro++) {
                    for (iSegundo = 0; iSegundo < 5; iSegundo++) {
                        for (iTerceiro = 0; iTerceiro < 5; iTerceiro++) {
                            strcat(vNomeCompleto[i], Primeiro[iPrimeiro]);
                            strcat(vNomeCompleto[i], vVazio);
                            strcat(vNomeCompleto[i], Meio[iSegundo]);
                            strcat(vNomeCompleto[i], vVazio);
                            strcat(vNomeCompleto[i], Sobrenome[iTerceiro]);
                            strcpy(vNome.vNomeComp[i], vNomeCompleto[i]);
                            vNome.status = 1;
                            i++;
                            fwrite(&vNome, sizeof (vNome), 1, arq);
                        }
                    }
                }
                printf("\n >>Pressione qualquer tecla para voltar<<");
                fclose(arq);
                getchar();
                break;
            case '3':
                puts("\nQual nome deseja remover? [digite o nome]");
                //fgets(linha, sizeof (linha), stdin);
                ;
                //sscanf(linha, "%d", &valor);
                //remover(ptlista, valor); 
                break;
            case '4':
                st = 1;
                listagem(st);
                break;
            case 's':
                sair = 1;
                break;
            default:
                puts("\n>>Opção Inválida<< \n >>Pressione Qualquer Tecla para Voltar<<");
                break;
        }
        system("clear");
    } while (!sair);
}

char tela() {
    char opcao, linha[80];
    puts(">>>>   Armazenamento de NOMES   <<<<");
    puts("\n[1]>> Mostrar os Nomes Sem Armazenar \n[2]>> Armazenar 125 Nomes dentro do Arquivo txt \n[3]>> Remover Nome \n[4]>> Pesquisar Nome \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

void listagem(int status) {
    FILE *arq;
    tag reg;
    int qtde = 0;
    arq = fopen("nomes.txt", "r");
    while (!feof(arq)) {
        fread(&reg, sizeof (reg), 1, arq);
        qtde = qtde + 1;
        if (reg.status == status) {
            printf("Nome ........: %s\n", reg.vNomeComp);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq);
    getchar();
}