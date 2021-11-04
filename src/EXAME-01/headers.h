/* 
 * File:   headers.h
 * Author: siad02
 *
 * Created on 28 de Março de 2016, 14:26
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
        int val, vContador, soma;
        struct s_cel *prox;
    } cel;
    typedef cel* lista;

    typedef cel* listaImpar;
    typedef cel* listaPar;

    void fInicializaListaCircular(lista *L) {
        *L = NULL;
    }

    int fVerificaListaVazia(lista L) {
        return (L == NULL);
    }

    void fIncluiElementoTopo(lista *L, int x) {
        cel *tmp;
        tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
        tmp->val = x; /*2-armazenar o valor do elemento*/
        tmp->prox = *L; /*3- apontando p/ lista*/
        (*L) = tmp; /*4-elemento é o novo primeiro*/
    }

    void fIncluiElementoTopoCircular(lista *p_L, int x) {
        lista tmp2;
        if ((*p_L == NULL) || ((*p_L)->val > x)) {
            cel *tmp;
            tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
            tmp->prox = *p_L; /*2- apontando p/ lista*/
            (*p_L) = tmp; /*3-elemento é o novo primeiro*/
            (*p_L)->val = x; /*armazenar o valor do elemento*/
            (*p_L)->vContador = 1;
        } else {
            tmp2 = *p_L;
            while ((tmp2->prox != NULL)&& (tmp2->prox->val <= x)) {
                tmp2 = tmp2->prox; /*operação a fazer sobre cada elemento*/
            }
            if (tmp2->val != x) {
                cel *tmp;
                tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
                tmp->prox = tmp2->prox; /*2- apontando p/ lista*/
                tmp2->prox = tmp; /*3-elemento é o novo primeiro*/
                tmp->val = x; /*armazenar o valor do elemento*/
                tmp->vContador = 1;
            } else {
                tmp2->vContador++;
            }
        }
    }

    void fIncluiElementoCauda(lista *L, int x) {
        cel *tmp;
        lista aux;
        tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
        tmp->val = x; /*2-armazenar o valor do elemento*/
        tmp->prox = NULL; /*3- aponta para NULL (último da nova lista)*/
        if (fVerificaListaVazia(*L)) /*caso de lista fVerificaListaVazia */
            *L = tmp;
        else {
            aux = *L;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = tmp;
        }
    }

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
        printf("\n\nListagem dos dados da Lista Encadeada :\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                printf("Dados...: %d\n", pLista->val);
                pLista = pLista->prox;
            }
        }
    }

    void fListarElementosListaEmOrdemCrescente(lista pLista) {
        printf("\n\nListagem dos dados da Lista Encadeada Crescente :\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                printf("Dados Em Ordem Crescente.....: %d\n", pLista->val);
                pLista = pLista->prox;
            }
        }
    }

    void fListarElementosListaEmOrdemDescrescente(lista pLista) {
        printf("\n\nListagem dos dados da Lista Encadeada Decrescente :\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                printf("Dados Em Ordem Decrescente...: %d\n", pLista->val);
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
            //pLista->vContador = i;
        }
    }

    void fMediaElementos(lista pLista) {
        int i = 0, vSoma = 0, vMedia;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                vSoma = vSoma + pLista->val;
                pLista = pLista->prox;
                i++;
            }
            vMedia = vSoma / i;
            printf("A Média dos dados da Lista Encadeada é: %d\n", vMedia);
        }
    }

    void fPesquisaRemove(int y, lista pLista) {
        int achou = 0;
        //fprintf(stdout, "Dados:\n\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL)
                if (y = pLista->val) {
                    fprintf(stdout, "------------\n");
                    fprintf(stdout, "Elemento: %d\n", pLista->val);
                    fprintf(stdout, "------------\n");
                    achou++;
                    pLista = pLista->prox;
                }
        }
        if (achou == 0)
            fprintf(stdout, "Nenhum resultado encontrado.\n");
        else
            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
        sleep(2);
    }

    //    void fPesquisaRemoveElemento(int y, lista pLista) {
    //        cel *tmp;
    //        int achou = 0;
    //        //fprintf(stdout, "Dados:\n\n");
    //        if (!fVerificaListaVazia(*pLista)) {
    //            tmp = *pLista; /*1-salvar endereço do 1o     */
    //            (*pLista) = tmp->prox; /*2-L aponta p/ resto da lista*/
    //            free(tmp); /*3-liberar a memória         */
    //        }
    //        if (achou == 0)
    //            fprintf(stdout, "Nenhum resultado encontrado.\n");
    //        else
    //            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
    //        sleep(2);
    //    }

    void fGeraListaImpar(lista pLista) {
        int divisorImpar = 2;
        int vResto;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                vResto = (pLista->val % divisorImpar);
                if (vResto != 0) {
                    printf("Lista Impar...: %d\n", pLista->val);
                }
                pLista = pLista->prox;
            }
        }
    }

    void fGeraListaPar(lista pLista) {
        int divisorPar = 2;
        int vResto;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                vResto = (pLista->val % divisorPar);
                if (vResto == 0) {
                    printf("Lista Par.....: %d\n", pLista->val);
                }
                pLista = pLista->prox;
            }
        }
    }

    char ftela() {
        char opcao, linha[80];
        puts(": ================ Programa De Uma Lista Encadeada Simples de Inteiros ================ :\n");
        puts("\n\n\t\tA- Inserir Dado no Topo da Lista Encadeada "
             "\n\n\t\tB- Inserir Dado na Cauda da Lista Encadeada "
             "\n\n\t\tC- Remover Dado do Topo da Lista Encadeada, "
             "\n\n\t\tD- Remover Dado da Cauda da Lista Encadeada "
             "\n\n\t\tE- Listar Dados da Lista Encadeada "
             "\n\n\t\tF- Retornar a Quantidade de Dados da Lista "
             "\n\n\t\tG- Retornar a Média Aritmética dos Dados da Lista "
             "\n\n\t\tH- Retirar da Lista um Dado Qualquer "
             "\n\n\t\tI- Retornar um nova lista, Ordenada Crescente "
             "\n\n\t\tJ- Gerar Duas Novas Listas, Uma Ímpar e Outra Par  "
             "\n\n\t\tS- Sair"
             "\n\n\n\t\t\tQual a sua Opção: "   );
        fgets(linha, sizeof (linha), stdin);
        sscanf(linha, "\t%c", &opcao);
        return tolower(opcao);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* HEADERS_H */
