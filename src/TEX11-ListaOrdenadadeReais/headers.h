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
        float vFloat;
        int cont;
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
            tmp = (cel*) malloc(sizeof (cel)); 
            tmp->vFloat = vetInteiro[i];
            tmp->prox = *L; 
            (*L) = tmp; 
        }
        sleep(1);
    }

    void fIncluiElementoTopoCircular(lista *p_L, int x) {
        lista tmp2;
        int i;
        float vetNumReais[x];
        for (i = 1; i <= x; i++) {
            //vetNumReais[i] = rand() % 900 + 100;
            vetNumReais[i] = (rand() % (120968 - 341 + 67) + 341) / 500.0;
            //printf("Iteiro Real...: %d\n", vetNumReais[i]);
            if ((*p_L == NULL) || ((*p_L)->vFloat > vetNumReais[i])) {
                cel *tmp;
                tmp = (cel*) malloc(sizeof (cel)); 
                tmp->prox = *p_L; 
                (*p_L) = tmp; 
                (*p_L)->vFloat = vetNumReais[i]; 
                (*p_L)->cont = 1;
            } else {
                tmp2 = *p_L;
                while ((tmp2->prox != NULL)&& (tmp2->prox->vFloat <= vetNumReais[i])) {
                    tmp2 = tmp2->prox; 
                }
                if (tmp2->vFloat != vetNumReais[i]) {
                    cel *tmp;
                    tmp = (cel*) malloc(sizeof (cel)); 
                    tmp->prox = tmp2->prox; 
                    tmp2->prox = tmp; 
                    tmp->vFloat = vetNumReais[i]; 
                    tmp->cont = 1;
                } else {
                    tmp2->vFloat++;
                }
            }
        }
        sleep(1);
    }

    void fExcluiElementoTopo(lista *L) {
        cel *tmp;
        if (!fVerificaListaVazia(*L)) {
            tmp = *L; 
            (*L) = tmp->prox;
            free(tmp);
        }
        sleep(1);
    }

    void fListarElementosLista(lista pLista) {
        printf("\n\nListagem dos Elementos da Lista Encadeada\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Dados de N...: %.2f\n", pLista->vFloat);
                fprintf(stdout, "------------\n");
                pLista = pLista->prox;
            }
        }
        sleep(1);
    }
    
    void fPesquisa(float y, lista pLista) {
        int achou = 0;
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vFloat == y) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Dado....: %.2f\n", pLista->vFloat);
                fprintf(stdout, "------------\n");
                achou++;
            }
        }
        if (achou == 0)
            fprintf(stdout, "Nenhum resultado encontrado.\n");
        else
            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
        sleep(1);
    }

    void fPesquisaRemove(float y, lista pLista) {
        int achou = 0;//70.2399979
        //while (pLista != NULL)
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vFloat == y) {
                free(pLista);
                //                fprintf(stdout, "------------\n");
                //                fprintf(stdout, "Dado....: %d\n", pLista->vFloat);
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
        puts("================================================================================");
        puts("                 Programa De Alunos Utilizando Listas Encadeadas                 ");
        puts("================================================================================");
        puts("\n\n\tA- Digite Uma Quantidade N para Gerar a Lista Encadeada de N "
                "\n\n\tB- Listar Os Elementos da Lista Encadeada de N "
                "\n\n\tC- Pesquisar um Elemento na Lista Encadeada de N "
                "\n\n\tD- Remover um Elemento do TOPO da Lista Encadeada de N "
                "\n\n\tE- Remover um Elemento da Lista Encadeada de N "
                "\n\n\tS- Sair"
             "\n\n================================================================================"
                "\n\nQual a sua Opção: ");
        fgets(linha, sizeof (linha), stdin);
        sscanf(linha, "%c", &opcao);
        return tolower(opcao);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* HEADERS_H */