/* 
 * File:   main.c
 * Author: root
 *
 * Created on March 29, 2016, 20:35 PM
 * 
 * Faça um programa que cria uma lista encadeada simples de números reais, ordenada de modo crescente. 
 * Construir e usar rotinas para:       
 * - criação da lista;       
 * - inserir elemento na lista;       
 * - retirar um elemento (real, passado como parâmetro), caso exista na lista;    
 * - listar todos os elementos da lista.
 * Crie um menu com as opções para Criar, Inserir Elemento, Retirar Elemento e Listar todos os Elementos da Lista. 
 * 
 */

#include "headers.h"

int main() {
    lista vListaCircular = NULL;
    fInicializaListaCircular(&vListaCircular);
    char linha[80];
    char opcao;
    int sair = 0, valor;
    float vFloat;

    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\nDigite um número N para gerar a Lista! ");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                fIncluiElementoTopoCircular(&vListaCircular, valor);
                printf("\n Foram Gerados %d registros na struct!", valor);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\nLista Elementos da Lista! ");
                fListarElementosLista(vListaCircular);
                //                lst_imprime_rec(vListaCircular);
                //                ordenarPeloCodigo(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\nDigite um Elemento a Ser Pesquisado na Lista! ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%f", &vFloat);
                fPesquisa(vFloat, vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\n>> Removendo um Elemento do TOPO da Lista << ");
                fExcluiElementoTopo(&vListaCircular);
                puts("\n >>Elemento Removido do TOPO com Sucesso!<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\n>> Digite um Elemento de N a ser Remevido da Lista << ");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &vFloat);
                fPesquisaRemove(vFloat, vListaCircular);
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
