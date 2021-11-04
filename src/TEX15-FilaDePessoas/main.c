/* 
 * File:   main.c
 * Author: Leonardo Silva
 *
 * Created on April 05, 2016, 20:35 PM
 * 
 * Enviar arquivo texto (.doc ou .c ou .txt) contendo a rotina solicitada.
 * Para a questão a seguir considere as seguintes estruturas de dados:
 * 
 * typedef struct {
 *   int ident;
 *   char sexo;
 *   char nome[50];
 * } pessoa;
 * 
 * typedef struct s_cel {
 *      pessoa esse;
 *      struct s_cel *prox;
 * } cel;
 * 
 * typedef struct {
 *   cel *inicio, *final;
 * } fila;
 * 
 * Considerando a estrutura de dados acima, com a qual definimos uma fila de “pessoas”, e também as seguintes funções:
 * void enqueue(fila *F, pessoa nova);
 * 
 * pessoa dequeue(fila *F);
 * void inicializa(fila *F);
 * int vazia(fila F);
 * 
 * Escreva uma rotina de receba uma fila de pessoas e que altere a sua ordem de forma que as mulheres venham antes dos homens, 
 * sendo que entre homens e mulheres a ordem deve ficar inalterada. 
 * Implemente a rotina utilizando somente as chamadas típicas de fila (enqueue, dequeue,  inicializa, vazia) sem implementá-las. 
 * Se necessário use filas temporárias.

 * 
 */

#include "headers.h"

int main() {
    fila PilhaMain1;
    fila PilhaMain2;
    fIniciaFila(&PilhaMain1);
    fIniciaFila(&PilhaMain2);
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
                enqueue(&PilhaMain1, vIdentidade, vGenero, vNome);
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
               // push(&PilhaMain2, vIdentidade, vGenero, vNome);
                printf("\n\nDados Inseridos na Pilha com Sucesso...! ");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nListando Registros da 1 Pilha! ");
               // fListarElementosPilha(PilhaMain1);
                puts("\n\nListando Registros da 2 Pilha! ");
                //fListarElementosPilha(PilhaMain2);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\nSeparando Registros das Pilhas 1 e 2! ");
                printf("\n\nSeparando As Pessoas Por Gênero Feminino!\n");
               // fSepararRegistrosGeneroFeminino(PilhaMain1);
                //fSepararRegistrosGeneroFeminino(PilhaMain2);
                printf("\n\nSeparando As Pessoas Por Gênero Masculino\n");
                //fSepararRegistrosGeneroMasculino(PilhaMain1);
                //fSepararRegistrosGeneroMasculino(PilhaMain2);
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

int** GeraTransposta(int **x, int n, int m) {
    int **pTransposta, i, j;
    pTransposta = (int **) malloc(m * sizeof (int *));
    for (i = 0; i < m; i++) {
        pTransposta[i] = (int *) malloc(n * sizeof (int));
        for (j = 0; j < n; j++)
            pTransposta[i][j] = x[j][i];
    }
    return (pTransposta);
}

int fatDuplo(int N) {
    if (N == 1) return 1;
    else return (fatDuplo(N - 2) * N);
}