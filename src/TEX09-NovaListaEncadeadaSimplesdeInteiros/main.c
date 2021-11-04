/* 
 * File:   main.c
 * Author: root
 *
 * Created on March 22, 2016, 11:08 PM
 * 
 *   Criar uma Lista Encadeada Simples de Inteiros. Para tal, implementar as seguintes operações:            
 * - Inicializar Lista;            
 * - Inserir no TOPO (início) da Lista;            
 * - Inserir na CAUDA (final) da Lista;            
 * - Retirar elemento do TOPO (início) da Lista;            
 * - Retirar elemento da CAUDA (final) da Lista;            
 * - Listar elementos da Lista;            
 * - Lista vazia (V ou F);
 * - Retornar a quantidade de elementos da lista;
 * - Retornar a Média Aritmética dos elementos da lista;
 * - Retirar da lista um elemento qualquer, passado como parâmetro;
 * - Retornar um nova lista, ordenada crescente.
 * - Gerar duas novas listas com base nos elementos de uma lista encadeada, 
 *   uma só com os números pares e outra só com os números ímpares.
 *   Criar programa com MENU para testar as operações de inserção, retiradas, retornos, geração de outras listas 
 *   e listagem dos elementos.
 * 
 */

#include "headers.h"

int main() {
    lista vListaCircular = NULL;
    fInicializaListaCircular(&vListaCircular);
    char linha[80];
    char opcao;
    char vOpcao = 's';
    int sair = 0, valor;

    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                do {
                    puts("\n\nInforme o valor a ser ADICIONADO na Lista e [0] para sair: ");
                    fgets(linha, sizeof (linha), stdin);
                    sscanf(linha, "%d", &valor);
                    //fIncluiElementoTopo(&vListaCircular, valor);
                    fIncluiElementoTopoCircular(&vListaCircular, valor);
                    fflush(stdin);
                } while (valor != 0);
                break;
            case 'b':
                system("clear");
                puts("\n\nInforme o valor a ser ADICIONADO na Cauda da Lista: ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &valor);
                fIncluiElementoCauda(&vListaCircular, valor);
                puts("\n >>Dado Inserido na CAUDA com Sucesso!!!<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\n>> Removendo o valor do TOPO da Lista << ");
                fExcluiElementoTopo(&vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\n>> Removendo o valor da CAUDA da Lista << ");
                fExcluiElementoCauda(&vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\nListando Dados da Lista ");
                fListarElementosLista(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'f':
                system("clear");
                fQuantidadeElementos(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'g':
                system("clear");
                fMediaElementos(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'h':
                system("clear");
                puts("\n\n>> Digite o Dado a ser Retirado << ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &valor);
//                fPesquisaRemoveElemento(valor, vListaCircular);
                getchar();
                break;
            case 'i':
                system("clear");
                puts("\n\nListando os Dados da Lista Em Ordem Crescente ");
                fListarElementosListaEmOrdemCrescente(vListaCircular);
                //fListarElementosListaEmOrdemDescrescente(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'j':
                system("clear");
                puts("\n\n >> Gerando listas, Uma Ímpar e Outra Par ");
                puts("\n Lista Par");
                fGeraListaPar(vListaCircular);
                puts("\n Lista Impar");
                fGeraListaImpar(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 's':
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