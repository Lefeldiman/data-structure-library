/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 *
 * Adapte o algoritmo de busca binária recursiva para localizar o matricula de uma pessoa numa tabela dada sua matrícula.
Considere que o cadastro de pessoas é um  vetor onde cada posição é uma estrutura do tipo “registro” definido abaixo.
Esse vetor não está ordenado.
Uma estrutura de índice, constituída de  um vetor do tipo “pessoa” deve ser usado para obter a posição do registro no  cadastro.
O índice esta ordenado por matrícula.

typedef struct dado {
       int matricula;
       int matricula;
} pessoa;

typedef struct reg {
       int matricula;
       char nome[50];
} registro;

Faça um cadastro de pessoas (de 10 a 30 registros), com Matrícula e Nome - se preferir faça-o em arquivo.
O programa deve ler matrículas e escrever o Nome equivalente das pessoas.
 * 
 * Created on March 2, 2016, 10:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef struct reg {
    int matricula;
    char nome[100];
    int status;
} tag;

int busca(int matricula);
void inserir(int matricula);
void listagem(int status, int matricula);
char tela();

int main() {
    char linha[80];
    char opcao;
    //char sit;
    int sair = 0, valor, st;

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
            case 'i':
                puts("\nDigite a Matrícula ...: ");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                inserir(valor);
                break;
            case 'r':
                puts("\nQual contato deseja remover? [digite o matricula]");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                //remover(ptlista, valor); 
                break;
            case 'l':
                st = 1;
                listagem(st, valor);
                break;
            case 'p':
                puts("\nDigite a Matrícula ...: \nou Digite '999' Para Pesquisar Todos");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                busca(valor);
                if (valor == 999)
                    busca(valor);
                else
                    if (busca(valor) == -1)
                    puts("\n>>Matrícula Inexistente<< \n >>Pressione Qualquer Tecla para Voltar<<");
                else
                    listagem(st, valor);
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
    puts(">>>>Matrículas de Alunos<<<<");
    puts("\n[I]>> Inserir Aluno \n[L]>> Listar Alunos \n[R]>> Remover Alunos \n[P]>> Pesquisar Alunos \n[S]>> Sair");
    fgets(linha, sizeof (linha), stdin);
    sscanf(linha, "%c", &opcao);
    return tolower(opcao);
}

int busca(int matricula) {
    FILE *arq;
    tag reg;
    int pos = 0;
    if (matricula == 999)
        return 1;
    arq = fopen("alunos.txt", "r");
    fread(&reg, sizeof (reg), 1, arq);
    while ((matricula != reg.matricula)&&(!feof(arq))) {
        fread(&reg, sizeof (reg), 1, arq);
        pos = pos + 1;
        fread(&reg, sizeof (reg), 1, arq);
    }
    if (matricula == reg.matricula)
        return (pos);
    else
        return (-1);
    fclose(arq);
}

void inserir(int matricula) {
    int pos;
    FILE *arq;
    tag reg;
    pos = busca(matricula);
    if (pos >= 0) {
        printf("\n>>> Matrícula Já Existente <<<");
        arq = fopen("alunos.txt", "r");
        fseek(arq, pos * sizeof (reg), SEEK_SET);
        fread(&reg, sizeof (reg), 1, arq);
        printf("\nMatrícula ...: %d\n", reg.matricula);
        printf("\nNome ........: %s\n", reg.nome);
        reg.status = 1;
        fclose(arq);
        printf("\n>>> Gravação Concluída <<<");
    } else {
        arq = fopen("alunos.txt", "a+");
        reg.matricula = matricula;
        printf("\nNome ...: ");
        scanf("%s", &reg.nome);
        reg.status = 1;
        fwrite(&reg, sizeof (reg), 1, arq);
        printf("\n>>> Gravação Concluída <<<");
        fclose(arq);
        getchar();
    }
}

void listagem(int status, int matricula) {
    FILE *arq;
    tag reg;
    int qtde = 0;
    arq = fopen("alunos.txt", "r");
    while (!feof(arq)) {
        fread(&reg, sizeof (reg), 1, arq);
        qtde = qtde + 1;
        if (reg.status == status) {
            printf("Matrícula ...: %d\n", reg.matricula);
            printf("Nome ........: %s\n", reg.nome);
            printf("------------------------------------------------\n");
        } else
            if (matricula == reg.matricula) {
            printf("Matrícula ...: %d\n", reg.matricula);
            printf("Nome ........: %s\n", reg.nome);
            printf("------------------------------------------------\n");
        }

    }
    fclose(arq);
    getchar();
}