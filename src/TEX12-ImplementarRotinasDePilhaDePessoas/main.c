/* 
 * File:   main.c
 * Author: Leonardo Silva
 *
 * Created on April 05, 2016, 20:35 PM
 * 
 * Enviar arquivo texto (.doc ou .c ou .txt) contendo as rotinas de implementação solicitadas, para Pilha de Pessoas.
 * Para a questão a seguir considere as seguintes estruturas de dados:
 * typedef struct {
 *   int ident;
 *   char sexo;
 *      char nome[50];
 * } pessoa;
 * typedef struct s_cel {
 *      pessoa esse;
 *      struct s_cel *prox;
 * } cel;
 * typedef cel* pilha;
 * Considerando que precisamos de uma pilha de dados do tipo “pessoa”,  implemente as rotinas básicas:
 * (push, pop, top, inicializa e vazia).
 * cuja interfaces são definidas abaixo.:
 * 
 * PUSH insere um dado de tipo pessoa na pilha. 
 * POP retira e retorna a pessoa retirada da pilha. 
 * TOP retorna a pessoa que está no topo da pilha. 
 * INICIALIZA cria uma pilha vazia. 
 * VAZIA retorna 1 (verdadeiro) ou 0 (falso) 
 * caso a pilha esteja, respectivamente, vazia ou não vazia.
 * 
 * A pilha deve ser construída usando uma lista encadeada simples cujas células são do tipo “cel”.
 * void push(pilha *P, pessoa nova);
 * pessoa pop(pilha *P);
 * pessoa top(pilha P);
 * void inicializa(pilha *P);
 * int vazia(pilha P);
 * 
 */

#include "headers.h"

int main() {
    pilha PilhaMain;
    fIniciaPilha(&PilhaMain);
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
                
                printf("\nDigite a Identidade de Pessoa para adicionar na pilha..: "
                        "\n(Somente Números de 7 dígitos).........................: ");
                scanf("%d", &vIdentidade);
                printf("\nDigite o Gênero de Pessoa para adicionar na pilha......: ");
                scanf("%s", &vGenero);
                printf("\nDigite o Nome de Pessoa para adicionar na pilha........: ");
               // fgets(linha, sizeof (linha), stdin);;
                fflush(stdin);
                scanf("%s", vNome);
                push(&PilhaMain, vIdentidade, vGenero, vNome);
                printf("\n\nDados Inseridos na Pilha com Sucesso...! ");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nListando Dados da Pilha! ");
                fListarElementosPilha(PilhaMain);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nDigite a identidade para retirar a pessoa da Pilha! ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &vIdentidade);
                pop(&PilhaMain, vIdentidade);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\nDigite a Identidade para Pesquisar na Pilha ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &vIdentidade);
                fPesquisaElementoPilha(vIdentidade, PilhaMain);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\nRetornando a pessoa Que Está No Topo da Pilha ");
                fprintf(stdout, "\n|--------------------------------------|\n");
                fprintf(stdout, "| Identidade...: %d               \n", top(PilhaMain));
                fprintf(stdout, "|----------------------------------------|\n");
                puts("\n\n >>Pressione qualquer tecla para voltar<<");
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
