/* 
 * File:   main.c
 * Author: Leonardo Silva
 *
 * Created on April 05, 2016, 20:35 PM
 * 
 * Enviar arquivo texto (.doc ou .c ou .txt) contendo a rotina solicitada.
 * Para a questão a seguir considere as seguintes estruturas de dados:
 * typedef struct {
 *   int ident;
 *   char sexo;
 *   char nome[50];
 * } pessoa;
 * typedef struct s_cel {
 *      pessoa esse;
 *      struct s_cel *prox;
 * } cel;
 * typedef cel* pilha;
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


    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                printf("\nDigite a Identidade de Pessoa para adicionar na 1 Pilha..: "
                        "\n(Somente Números de até 7 dígitos).......................: ");
                scanf("%d", &vIdentidade);
                printf("\nDigite o Gênero de Pessoa para adicionar na 1 Pilha......: ");
                scanf("%s", &vGenero);
                printf("\nDigite o Nome de Pessoa para adicionar na 1 Pilha........: ");
                fflush(stdin);
                scanf("%s", vNome);
                push(&PilhaMain1, vIdentidade, vGenero, vNome);
                printf("\n\nDados Inseridos na Pilha com Sucesso...! ");
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