/* 
 * File:   main.c
 * Author: Leonardo Silva
 *
 * Created on April 05, 2016, 20:35 PM
 * 
 * Enviar arquivo texto (.doc ou .c ou .txt) contendo as rotinas de implementação solicitadas, para Fila de Pessoas.
 * Para a questão a seguir considere as seguintes estruturas de dados:
 * 
 * typedef struct {
 *   int ident;
 *   char sexo;
 *   char nome[50];
 * } pessoa;
 * typedef struct s_cel {
 *      pessoa esse;
 *      struct s_cel *prox;
 * } cel;
 * 
 * typedef struct {
 * cel *inicio, *final;
 * } fila;
 * 
 * Considerando que precisamos de uma fila de dados do tipo “pessoa”, 
 * implemente as rotinas básicas (enqueue, dequeue,  inicializa e vazia), 
 * cuja interfaces são definidas abaixo. 
 * ENQUEUE insere um dado de tipo pessoa na fila. 
 * DEQUEUE retira e retorna a pessoa retirada da fila. 
 * INICIALIZA cria uma fila vazia. 
 * VAZIA retorna 1 (verdadeiro) ou 0 (falso) caso a fila esteja, respectivamente, vazia ou não vazia.
 * 
 * A fila deve ser construída usando uma lista encadeada simples cujas células são do tipo “cel”.
 * void enqueue(fila *F, pessoa nova);
 * pessoa dequeue(fila *F);
 * void inicializa(fila *F);
 * int vazia(fila F);
 * 
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
