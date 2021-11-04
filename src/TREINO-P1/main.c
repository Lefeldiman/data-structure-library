/* 
 * File:   main.c
 * Author: siad02
 *
 * Created on 13 de Abril de 2016, 08:13
 *
 * 
 * Escreva uma rotina em C que receba duas pilhas de “pessoas” com um número desconhecido de dados em cada uma. 
 * Na entrada existem homens (sexo=’M’) e mulheres (sexo=’F’) misturados nas duas pilhas. 
 * A rotina deve tratar o conjunto de pessoas da união das duas pilhas e separá-las por sexo de forma que: 
 * na primeira pilha fiquem somente mulheres e na segunda somente homens. Note que o conjunto de pessoas da entrada, 
 * definido pela união das duas pilhas, deve  ser o mesmo da saída. Implemente a rotina utilizando somente as chamadas típicas de pilha 
 * (push, pop, top, inicializa, vazia) sem implementar tais chamadas típicas, utilizando pilhas temporárias se necessário. 
 * As funções da pilha de pessoa são definidas da seguinte forma:
 * 
 * pessoa pop(pilha *P);
 * void push(pilha *P, pessoa nova);
 * pessoa top(pilha P);
 * void inicializa(pilha *P);
 * int vazia(pilha P);
 * 
 */

#include "headers.h"

int main() {
    pilha PilhaMain1;
    pilha PilhaMain2;
    fIniciaPilha(&PilhaMain1);
    fIniciaPilha(&PilhaMain2);
    char linha[80];
    char opcao;
    char vGenero;
    char vNome[50];
    int vSair = 0, vIdentidade;
    int x = 8, y;


    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                printf("\nQuestão 1"
                        "\n\nTexto-base"
                        "\nPonteiros são tipos especiais de variáveis, que permitem armazenar endereços válidos de memória. "
                        "\nVia ponteiro, podemos acessar o endereço de uma variável e manipular o conteúdo armazenado na mesma. "
                        "\nA citada variável pode ser de qualquer tipo elementar "
                        "\n(int, float, double, char, ... ), de qualquer tipo definido pelo programador e, até mesmo, "
                        "\nser outro ponteiro (nesse caso teremos “ponteiro para ponteiro”).\n");
                int *p, **q, *r;
                r = &x;
                q = &p;
                (*q) = &y;
                (*p) = x + (*r);
                r = p;
                (**q) = x + 2;
                p = &x;
                printf("%d  %d  %d  %d  %d\n", y, x, *p, *r, **q);
                getchar();
                break;
            case 'b':
                system("clear");
                printf("\nDigite a Identidade de Pessoa para adicionar na 2 Pilha..: "
                        "\n(Somente Números de até 7 dígitos).......................: ");
                scanf("%d", &vIdentidade);
                printf("\nDigite o Gênero de Pessoa para adicionar na 2 Pilha......: ");
                scanf("%s", &vGenero);
                printf("\nDigite o Nome de Pessoa para adicionar na 2 Pilha........: ");
                fflush(stdin);
                scanf("%s", vNome);
                push(&PilhaMain2, vIdentidade, vGenero, vNome);
                printf("\n\nDados Inseridos na Pilha com Sucesso...! ");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nListando Registros da 1 Pilha! ");
                fListarElementosPilha(PilhaMain1);
                puts("\n\nListando Registros da 2 Pilha! ");
                fListarElementosPilha(PilhaMain2);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\nSeparando Registros das Pilhas 1 e 2! ");
                printf("\n\nSeparando As Pessoas Por Gênero Feminino!\n");
                fSepararRegistrosGeneroFeminino(PilhaMain1);
                fSepararRegistrosGeneroFeminino(PilhaMain2);
                printf("\n\nSeparando As Pessoas Por Gênero Masculino\n");
                fSepararRegistrosGeneroMasculino(PilhaMain1);
                fSepararRegistrosGeneroMasculino(PilhaMain2);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 's':
                system("clear");
                vSair = 1;
                break;
            default:
                system("clear");
                puts("\n>>Opção Inválida<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
        }
        system("clear");
    } while (!vSair);
}