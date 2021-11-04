/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 *
 * Faça um programa que converta o arquivo texto de números inteiros "Dados.txt" (anexo a eia tarefa) em arquivo binário. 
 * Após a gravação, abrir o arquivo binário gerado e escrever na tela seu conteúdo, com 8 valores por linha.
 * 
 * Created on March 9, 2016, 10:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char tela();

int main() {
    char linha[80];
    char opcao;
    int sair = 0, valor, i;

    FILE *arq;
    arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        arq = fopen("alunos.txt", "a+");
        fclose(arq);
    } else {
        fclose(arq);
    }

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nConvertendo arquivo de TEXTO para BINARIO");
                FILE *dados;
                FILE *bin;
                dados = fopen("dados.txt", "r");
                bin = fopen("Binario.dat", "wb");
                while (fscanf(dados, "%d", &valor) != EOF)
                    fwrite(&valor, sizeof (int), 1, bin);
                fclose(dados);
                fclose(bin);
                printf("Conteudo do Arquivo Binario Gerado: \n\n");
                bin = fopen("Binario.dat", "rb");
                while (fread(&valor, sizeof (int), 1, bin) == 1) {
                    printf("%5d", valor);
                    i++;
                    if (i % 8 == 0)
                        printf("\n");
                }
                fclose(bin);
                getchar();
                return 0;
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
    puts(">>>> Conversão de Arquivo de Texto para Arquivo Binário <<<<");
    puts("\n[1]>> Converter Arquivo e Moirar na Tela \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

