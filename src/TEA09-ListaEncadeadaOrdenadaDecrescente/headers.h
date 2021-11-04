/* 
 * File:   headers.h
 * Author: root
 *
 * Created on 29 de Março de 2016, 20:46
 */

#ifndef HEADERS_H
#define	HEADERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stddef.h>
#include <unistd.h>

    typedef struct s_cel {
        long long int vInteiro;
        struct s_cel *prox;
    } cel;
    typedef cel* lista;

    void fInicializaListaCircular(lista *L) {
        *L = NULL;
    }

    int fVerificaListaVazia(lista L) {
        return (L == NULL);
    }

    void fIncluiElementoTopo(lista *L, int x) {
        cel *tmp;
        int i;
        long long int vetInteiro[x];
        for (i = 1; i <= x; i++) {
            vetInteiro[i] = rand() % 50 + 10;
            //vetMensalidade[i] = (rand() % (120968 - 341 + 67) + 341) / 500.0;
            tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
            tmp->vInteiro = vetInteiro[i];
            tmp->prox = *L; /*3- apontando p/ lista*/
            (*L) = tmp; /*4-elemento é o novo primeiro*/
        }
    }

    //    void fIncluiElementoTopoCircular(lista *p_L, int x) {
    //        lista tmp2;
    //        int i;
    //        int vetInteiro[500];
    //        for (i = 1; i <= 500; i++) {
    //            vetInteiro[i] = rand() % 900 + 100;
    //            printf("Matrícula...: %d\n", vetInteiro[i]);
    //        }
    //        if ((*p_L == NULL) || ((*p_L)->vMensalidade > vetInteiro[i])) {
    //            cel *tmp;
    //            tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
    //            tmp->prox = *p_L; /*2- apontando p/ lista*/
    //            (*p_L) = tmp; /*3-elemento é o novo primeiro*/
    //            (*p_L)->vMensalidade = vetInteiro[i]; /*armazenar o vMensalidadeor do elemento*/
    //            (*p_L)->vInteiro = 1;
    //        } else {
    //            tmp2 = *p_L;
    //            while ((tmp2->prox != NULL)&& (tmp2->prox->vMensalidade <= vetInteiro[i])) {
    //                tmp2 = tmp2->prox; /*operação a fazer sobre cada elemento*/
    //            }
    //            if (tmp2->vMensalidade != vetInteiro[i]) {
    //                cel *tmp;
    //                tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
    //                tmp->prox = tmp2->prox; /*2- apontando p/ lista*/
    //                tmp2->prox = tmp; /*3-elemento é o novo primeiro*/
    //                tmp->vMensalidade = vetInteiro[i]; /*armazenar o vMensalidadeor do elemento*/
    //                tmp->vInteiro = 1;
    //            } else {
    //                tmp2->vInteiro++;
    //            }
    //        }
    //    }

    //    void fIncluiElementoCauda(lista *L, int x) {
    //        cel *tmp;
    //        lista aux;
    //        tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
    //        tmp->prox = NULL; /*3- aponta para NULL (último da nova lista)*/
    //        if (fVerificaListaVazia(*L)) /*caso de lista fVerificaListaVazia */
    //            *L = tmp;
    //        else {
    //            aux = *L;
    //            while (aux->prox != NULL)
    //                aux = aux->prox;
    //            aux->prox = tmp;
    //        }
    //    }

    void fExcluiElementoTopo(lista *L) {
        cel *tmp;
        if (!fVerificaListaVazia(*L)) {
            tmp = *L; /*1-salvar endereço do 1o     */
            (*L) = tmp->prox; /*2-L aponta p/ resto da lista*/
            free(tmp); /*3-liberar a memória         */
        }
    }

    void fExcluiElementoCauda(lista *L) {
        cel *tmp;
        if (!fVerificaListaVazia(*L)) {
            tmp = *L; /*1-salvar endereço do 1o     */
            if (tmp->prox == NULL) //Lista tem só um elemento
            {
                *L = NULL;
                free(tmp);
                return;
            }
            while (tmp->prox->prox != NULL) //Lista com 2 ou mais elementos
                tmp = tmp->prox;
            free(tmp->prox);
            tmp->prox = NULL;
        }
    }

    void fListarElementosLista(lista pLista) {
        printf("\n\nListagem dos Elementos da Lista Encadeada\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Dados de N...: %d\n", pLista->vInteiro);
                fprintf(stdout, "------------\n");
                pLista = pLista->prox;
            }
        }
    }

    void fQuantidadeElementos(lista pLista) {
        int i = 0;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                pLista = pLista->prox;
                i++;
            }
            printf("A Quantidade de dados da Lista Encadeada é: %d\n", i);
            //pLista->vInteiro = i;
        }
    }

    void fMediaElementos(lista pLista) {
        int i = 0, vSoma = 0, vMedia;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                vSoma = vSoma + pLista->vInteiro;
                pLista = pLista->prox;
                i++;
            }
            vMedia = vSoma / i;
            printf("A Média dos dados da Lista Encadeada é: %d\n", vMedia);
        }
    }

    void fPesquisa(int y, lista pLista) {
        int achou = 0;
        //while (pLista != NULL)
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vInteiro == y) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Dado....: %d\n", pLista->vInteiro);
                fprintf(stdout, "------------\n");
                achou++;
            }
        }
        if (achou == 0)
            fprintf(stdout, "Nenhum resultado encontrado.\n");
        else
            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
        sleep(5);
    }

    void fPesquisaRemove(int y, lista pLista) {
        int achou = 0;
        //while (pLista != NULL)
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vInteiro == y) {
                free(pLista);
//                fprintf(stdout, "------------\n");
//                fprintf(stdout, "Dado....: %d\n", pLista->vInteiro);
//                fprintf(stdout, "------------\n");
                achou++;
            }
        }
        if (achou == 0)
            fprintf(stdout, "Nenhum resultado encontrado.\n");
        else
            fprintf(stdout, "Foram removidos"
                    " %d registros.\n", achou);
        sleep(1);
    }

    char ftela() {
        char opcao, linha[80];
        puts("Lista Encadeada Simples de N Inteiros");
        puts("\n[A]>> Inserir Uma Quantidade N de Inteiros na Lista \n[B]>> Listar Os Elementos da Lista Encadeada de N \n[C]>> Pesquisar um Elemento na Lista Encadeada de N \n[D]>> Remover um Elemento do TOPO da Lista Encadeada de N \n[E]>> Remover um Elemento da Lista Encadeada de N \n[S]>> Sair");
        fgets(linha, sizeof (linha), stdin);
        sscanf(linha, "%c", &opcao);
        return tolower(opcao);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* HEADERS_H */