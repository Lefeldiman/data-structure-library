/* 
 * File:   main.c
 * Author: root
 *
 * Created on May 3, 2016, 9:50 PM
 * 
 * Fazer um programa que gere uma árvore binária não ordenada de inteiros lidos do teclado. 
 * Usar rotina "le_arvore()" do slide 18 da EDA 06. 
 * Escrever as rotinas recursivas de impressão de uma árvore binária em ordem infixa, prefixa e posfixa. 
 * Utilizar tais rotinas para escrever os elementos da árvore.
 * 
 */

#include "headers.h"

int main() {
    no arvore;
    arvore = cria_arv();
    char opcao;
    int sair = 0;

    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\nMontar Árvore de Dados [Digite 0, para sair]\n\n");
                monta_arv(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem InFixa ");
                infixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem PréFixa ");
                prefixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem PósFixa ");
                prefixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 's':
                system("clear");
                sair = 1;
                break;
            default:
                system("clear");
                puts("\n>>Opção Inválida<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
        }
        system("clear");
    } while (!sair);
}

