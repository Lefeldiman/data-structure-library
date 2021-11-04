/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Paulino Silva - UC07022711
 * 
 * Considere a seguinte estrutura :

typedef  struct {
                      int  Matricula;
                     char  Sexo;
                    float Salario;
                          } Empregado;
Criar um vetor de 30 empregados na Área Dinâmica de Memória. Para cada empregado, 
 * gerar aleatoriamente a Matrícula (entre 1000 e 9999);
 * gerar aleatoriamente o Sexo (‘M’ ou ‘F’);
 * gerar aleatoriamente o Salário (entre R$ 894,31 e R$ 9.346,19 – todos com duas casas decimais);
 * Após a criação do vetor, escrever os 3 dados de cada empregado, na ordem em que foram gerados. 
 * Ordenar CRESCENTE o vetor pelo campo Matrícula. 
 * Escrever os 3 dados de cada empregado, em ordem crescente de Matrícula.
 *
 * Created on February 24, 2016, 11:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef struct reg {
    int matricula;
    char genero[10];
    float salario;
    int status;
} tag;

int busca(int matricula);
void inserir(int matricula);
void listagem(int status);
char tela();

int main() {
    char linha[80];
    char opcao;
    char vGeneroMasc[9] = "MASCULINO";
    char vGeneroFem[8] = "FEMININO";
    int sair = 0, st, i, vGenero;


    FILE *arq;
    arq = fopen("empregados.txt", "r");
    if (arq == NULL) {
        arq = fopen("empregados.txt", "a+");
        fclose(arq);
    } else {
        fclose(arq);
    }

    do {
        opcao = tela();
        switch (opcao) {
            case '1':
                puts("\nGerar Aleatoriamente a Matricula!");
                //fgets(linha, sizeof (linha), stdin);
                //;
                //sscanf(linha, "%ld", &valor);
                for (i = 1; i <= 30; i++)
                    tag.matricula = (rand() % 9999 + 1000);
                tag->status = 1;
                puts("\nGeração de Matrículas feita com sucesso! \n >>Pressione Qualquer Tecla para Voltar<< ");
                break;
            case '2':
                puts("\nGerar o Gênero");
                //fgets(linha, sizeof (linha), stdin);
                //;
                for (i = 1; i <= 30; i++)
                    vGenero = rand() % 2 + 0;
                if (vGenero == 0)
                    tag->genero = vGeneroMasc;
                else
                    tag->genero = vGeneroFem;
                puts("\nGeração de Gêneros feita com sucesso! \n >>Pressione Qualquer Tecla para Voltar<< ");
                break;
            case '3':
                puts("\nGerar aleatoriamente o Salário (entre R$ 894,31 e R$ 9.346,19 – todos com duas casas decimais)");
                fgets(linha, sizeof (linha), stdin);
                ;
                for (i = 1; i <= 30; i++) {
                    tag->salario = ((rand() % (894, 31 - 9.346, 19 + 1) + 9.346, 19) / 100.00);
                    //printf("%5.2f\n", X);
                }
                puts("\nGeração de Salários feita com sucesso! \n >>Pressione Qualquer Tecla para Voltar<< ");
                break;
            case '4':
                puts("\nEscrever os 3 dados de cada empregado na ordem em que foram gerados");
                fgets(linha, sizeof (linha), stdin);
                ;
                st = 1;
                listagem(st);
                break;
            case '5':
                puts("\nOrdenar CRESCENTE o vetor pelo campo Matrícula");
                fgets(linha, sizeof (linha), stdin);
                ;
                listagem(st);
                break;
            case '6':
                puts("\nEscrever os 3 dados de cada empregado, em ordem crescente de Matrícula");
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
    puts(">>>>Empregados<<<<");
    puts("\n[1]>> Gerar a Matrícula Aleatoreamente "
            "\n[2]>> Gerar o Gênero "
            "\n[3]>> Gerar Aleatoriamente o Salário "
            "\n[4]>> Escrever os 3 dados de cada empregado na ordem em que foram gerados "
            "\n[5]>> Ordenar CRESCENTE o vetor pelo campo Matrícula "
            "\n[6]>> Escrever os 3 dados de cada empregado, em ordem crescente de Matrícula "
            "\n[S]>> Sair");
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
    arq = fopen("empregados.txt", "r");
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
        arq = fopen("empregados.txt", "r");
        fseek(arq, pos * sizeof (reg), SEEK_SET);
        fread(&reg, sizeof (reg), 1, arq);
        printf("\nMatrícula ...: %d\n", reg.matricula);
        printf("\nNome ........: %s\n", reg.salario);
        reg.status = 1;
        fclose(arq);
        printf("\n>>> Gravação Concluída <<<");
    } else {
        arq = fopen("empregados.txt", "a+");
        reg.matricula = matricula;
        printf("\nNome ...: ");
        scanf("%s", &reg.salario);
        reg.status = 1;
        fwrite(&reg, sizeof (reg), 1, arq);
        printf("\n>>> Gravação Concluída <<<");
        fclose(arq);
        getchar();
    }
}

void listagem(int status) {
    FILE *arq;
    tag reg;
    int qtde = 0;
    arq = fopen("empregados.txt", "r");
    while (!feof(arq)) {
        fread(&reg, sizeof (reg), 1, arq);
        qtde = qtde + 1;
        if (reg.status == status) {
            printf("Matrícula ...: %d\n", reg.matricula);
            printf("Gênero ........: %s\n", reg.genero);
            printf("Salário ........: %s\n", reg.salario);
            printf("------------------------------------------------\n");
            /*
                    } else
                        if (matricula == reg.matricula) {
                        printf("Matrícula ...: %d\n", reg.matricula);
                        printf("Gênero ........: %s\n", reg.genero);
                        printf("Salário ........: %s\n", reg.salario);
                        printf("------------------------------------------------\n");
             */
        }

    }
    fclose(arq);
    getchar();
}