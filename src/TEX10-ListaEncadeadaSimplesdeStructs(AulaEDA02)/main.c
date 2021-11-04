/* 
 * File:   main.c
 * Author: root
 *
 * Created on March 22, 2016, 11:11 PM
 * 
 * Crie todas as operações necessárias (ver TEA 08) para utilização de uma Lista Encadeada Simples (não ordenada), onde os dados a serem armazenados sejam registros (struct) compostos por: 
 * Uma Matrícula (inteiro) e uma Mensalidade(real com duas casas decimais); 
 * 
 * Inserir 500 registros na lista (gerar aleatórios entre 100 e 10000 para as matrículas e aleatórios reais entre 341,67 e 1209,68 para as mensalidades;
 
 * Crie um MENU com todas as opções que julgar necessárias para a utilização da lista. 
 * Obs1. Além das operações básicas (Aula 02 - slides a partir do 52):
 * Criar outras operações que julgue interessantes e implementar as solicitações dos slides 61 e 63, conforme a seguir:
 * 
 * Implemente um algoritmo que receba uma Matrícula como parâmetro e percorra a lista a  sua procura;
 * Se a encontrar retorne TRUE senão inclua no final da lista e retorne  FALSE 
 * (para a inclusão gerar uma Mensalidade aleatória conforme as regras anteriores).
 * 
 * Implemente em C uma rotina que procure uma Matrícula, passada como parâmetro, Numa lista  encadeada e retire da lista todas as structs que possuam a Matrícula, 
 * Retornando o número de instâncias retiradas.
 *   
 * Obs2. Fazer rotina que receba uma lista e escreva na tela somente as matrículas que apareçam mais de uma vez na lista - ao lado da cada matrícula, escrever também a 
 * quantidade de vezes que a mesma aparece na lista.
 * 
 */

#include "headers.h"

int main() {
    lista vListaCircular = NULL;
    fInicializaListaCircular(&vListaCircular);
    char linha[80];
    char opcao;
    int sair = 0, valor, i = 0;

    do {
        opcao = ftela();
        switch (opcao) {
            case 'a':
                system("clear");
                puts("\n\n Inserindo 500 registros na Lista! ");
                fIncluiElementoTopo(&vListaCircular);
                //fGeraNomeRandonico(&vListaCircular);
                puts("\n\n >>Foram Inseridos 500 Registros na Lista!<<");
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'b':
                system("clear");
                puts("\n\n Listando Elementos da Lista! ");
                fListarElementosLista(vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'c':
                system("clear");
                puts("\n\n Digite a Matrícula a Ser Pesquisada na Lista! ");
                fgets(linha, sizeof (linha), stdin);
                sscanf(linha, "%d", &valor);
                fPesquisaElemento(valor, vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'd':
                system("clear");
                puts("\n\n Removendo a Matrícula da Lista!");
                fgets(linha, sizeof (linha), stdin);
                ;
                sscanf(linha, "%d", &valor);
                //fExcluiElementoTopo(&vListaCircular);
                fExcluiElementoPesquisado(valor,vListaCircular,&vListaCircular);
                puts("\n >>Pressione qualquer tecla para voltar<<");
                getchar();
                break;
            case 'e':
                system("clear");
                puts("\n\n Calculando Média Das Mensalidades da Lista!");
                fMediaElementos(vListaCircular);
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