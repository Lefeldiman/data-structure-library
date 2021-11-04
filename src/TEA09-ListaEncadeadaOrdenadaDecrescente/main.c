/* 
 * File:   main.c
 * Author: root
 *
 * Created on March 29, 2016, 20:35 PM
 * 
 * Gerar um inteiro aleatório N, entre 10 e 50. 
 * Criar uma Lista Encadeada de Inteiros,Ordenada Decrescente, com N inteiros aleatórios ente 0 e 15 (ou seja, com N células). 
 * Criar as seguintes operações/rotinas relativas a Lista Encadeada Ordenada Decrescente de inteiros:
 * - inicializar uma lista;
 * - inserir elemento na lista (levar em conta que a lista admite valores repetidos);
 * - retirar um valor (inteiro passado como parâmetro) da Lista, em todas as suas   ocorrências, retornando a quantidade de ocorrências;
 * - apresentar na tela todos os elementos da lista.
 * Crie um menu com as opções para Retirar Elemento e Listar todos os Elementos da Lista Encadeada Ordenada Decrescente.  
 * 
 */
#include "headers.h"

int main() {
    lista vListaCircular = NULL;
    fInicializaListaCircular(&vListaCircular);
    char linha[80];
    char opcao;
    int sair = 0, valor;

    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\nDigite um número N para gerar a Lista! ");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                fIncluiElementoTopo(&vListaCircular, valor);
                printf("\n Foram Gerados %d registros na struct!", valor);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nLista Elementos da Lista! ");
                fListarElementosLista(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nDigite um Elemento a Ser Procurada na Lista! ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &valor);
                fPesquisa(valor, vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\n>> Removendo um Elemento do TOPO da Lista << ");
                fExcluiElementoTopo(&vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\n>> Digite um Elemento de N a ser Remevido da Lista << ");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                fPesquisaRemove(valor, vListaCircular);
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
