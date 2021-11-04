/* 
 * File:   main.c
 * Author: Leonardo Silva
 *
 * Created on April 05, 2016, 20:35 PM
 * 
 * Enviar arquivo, em qualquer formato, contendo a Pilha e seus vResultado1es finais (bem como a indicação de onde fica o topo)
 *  e contendo a Fila e seus vResultado1es finais (bem como a indicação do Início e do Final da Fila).
 * Quais os dados restariam na pilha P e na fila F após a sequência de chamadas a seguir:
 * pilha *P; inicializa(&P);
 * fila *F;  inicializa(&F);
 * enqueue(&F,5); enqueue(&F,10); enqueue(&F,20);
 * push(&P,11); push(&P,22); push(&P,33);
 * push(&P,dequeue(&F)*top(P));
 * enqueue(&F,pop(&P)+pop(&P)+top(P)+2);
 * enqueue(&F,pop(&P));
 * push(&P,dequeue(&F)- dequeue(&F)+ top(P));
 * 
 */

#include "headers.h"

int main() {
    pilha *P;
    fIniciaPilha(P);
    fila *F;
   // fIniciaFila(F);
    char linha[80];
    char opcao;
    int sair = 0, vResultado1, vResultado2, vResultado3, vResultado4;


    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\nQuais Dados Restam após a sequência de Chamadas: "
                        "\nenqueue(&F,5); enqueue(&F,10); enqueue(&F,20);"
                        "\npush(&P,11); push(&P,22); push(&P,33);"
                        "\npush(&P,dequeue(&F)*top(P));"
                        "\nenqueue(&F,pop(&P)+pop(&P)+top(P)+2);"
                        "\nenqueue(&F,pop(&P));"
                        "\npush(&P,dequeue(&F)- dequeue(&F)+ top(P));");
/*
                enqueue(F, 5);
                enqueue(F, 10);
                enqueue(F, 20);
*/
/*
                printf("\n Foram Enfilerados: %d", F);
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                getchar();
*/
                push(P, 11);
                push(P, 22);
                push(P, 33);
                printf("\n Foram Empilhados: %d ", P);
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                getchar();
/*
                //vResultado1 = push(P, dequeue(F) * top(P));
                printf("\n Resultado: %d ", vResultado1);
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                getchar();
                //vResultado2 = enqueue(F, pop(P) + pop(P) + top(P) + 2);
                printf("\n Resultado: %d ",vResultado2);
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                getchar();
                //vResultado3 = enqueue(F, pop(P));
                printf("\n Resultado: %d ",vResultado3 );
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                getchar();
                //vResultado4 = push(P, dequeue(F) - dequeue(F) + top(P));
//                printf("\n Resultado: %d ",push(P, dequeue(F) - dequeue(F) + top(P)));
                puts("\n >>Pressione qualquer tecla para Continuar<<");
                //puts("\n >>Pressione qualquer tecla para voltar<<");
*/
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nLista Elementos da Lista! ");
                // fListarElementosLista(vListaCircular);
                //                lst_imprime_rec(vListaCircular);
                //                ordenarPeloCodigo(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nDigite um Elemento a Ser Pesquisado na Lista! ");
                fgets(linha, sizeof (linha), stdin);
                //sscanf(linha, "%f", &vFloat);
                //fPesquisa(vFloat, vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\n>> Removendo um Elemento do TOPO da Lista << ");
                // fExcluiElementoTopo(&vListaCircular);
                puts("\n >>Elemento Removido do TOPO com Sucesso!<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\n>> Digite um Elemento de N a ser Remevido da Lista << ");
                fgets(linha, sizeof (linha), stdin);
                ;
                // sscanf(linha, "%d", &vFloat);
                //fPesquisaRemove(vFloat, vListaCircular);
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
