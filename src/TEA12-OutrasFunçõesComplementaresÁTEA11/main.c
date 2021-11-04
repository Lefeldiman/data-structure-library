/* 
 * File:   main.c
 * Author: root
 *
 * Created on May 3, 2016, 9:50 PM
 * 
 * Usando a solução da TEA 11, acrescentar (criando e testando) as seguintes rotinas para árvores binárias não ordenadas:
 * - retorna a soma dos elementos de uma árvore passada como parâmetro;
 * - retorna a quantidade de elementos de uma árvore passada como parâmetro;
 * - retorna o Maior dos elementos de uma árvore passada como parâmetro;
 * - recebe uma  árvore e um valor inteiro - retorna o endereço do nó do elemento que possua tal valor inteiro, caso exista na árvore - retorna NULL caso não exista na árvore ;
 * - insere um inteiro X do lado (esquerdo ou direito) do elemento Y, caso  Y  exista na árvore e seu lado (esquerdo ou direito) esteja vago - caso não consiga inserir, escrever na tela mensagem adequada. 
 *   A rotina deve receber, como parâmetros: a árvore, X, lado e Y. Retorna VERDADEIRO (1) se duas árvores binárias (passadas como parâmetros) forem iguais e retorna FALSO (0) caso contrário;
 *   retorna a Altura de uma árvore binária passada como parâmetro.
 * 
 *  
 */

#include "headers.h"

int main() {
    no arvore;
    arvore = fCriaArvore();
    char linha[80];
    char opcao;
    int sair = 0, valor;
    
    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\nMontar Árvore de Dados [Digite 0, para sair]\n\n");
                fMontaArvore(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem InFixa ");
                fImprimeInFixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem PréFixa ");
                fImprimePreFixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\nImprimindo os Dados na Árvore em Ordem PósFixa ");
                fImprimePosFixa(arvore);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\nRetornar a Soma dos Elementos da Árvore ");
                printf("A Soma dos Elementos é: %d \n",fRetornaSomaElemento2(arvore));
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'f':
                system("clear");
                puts("\n\nRetornar a Quantidade dos Elementos da Árvore ");
                printf("A Quantidade dos Elementos Na Árvore é: %d \n",fRetornaQuantidadeElemento2(arvore));
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'g':
                system("clear");
                puts("\n\nRetornar o Maior Elemento da Árvore ");
                printf("O Maior Elemento Da Árvore é: %d \n",fRetornaElementoMaior2(arvore));
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'h':
                system("clear");
                puts("\n\nRetorna o Endereço do nó do Elemento que possua tal valor inteiro ");
                puts("\n\nDigite o Elemento a Ser Pesquisado: ");
                sscanf(linha, "%d", &valor);
                printf("O Endereço Do Elemento Na Árvore é: %d \n",fRetornaEnderecoNoElemento(arvore,valor));
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'i':
                system("clear");
                puts("\n\nPesquisar Elemento na Árvore ");
                puts("\n\nDigite o Elemento a Ser Pesquisado: ");
                sscanf(linha, "%d", &valor);
                fPesquisaElementoArvore(arvore, valor);
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

