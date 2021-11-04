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
#define bool int
#define TRUE 1
#define FALSE 0
#define MAX_PILHA 4
#define MAXINT 0xFFFFFFF
#define SEMVALOR MAXINT /* erro p/ pop e top*/
    
    typedef struct cel {
        int dados[MAXINT];
        int elem;
        struct cel *prox;
    } *lista;

    typedef struct {
        lista inicio, final;
    } fila;

    typedef struct s_cel {
        int dados[MAXINT];
        int elem;
        struct s_cel *prox;
    } cel;
    typedef cel* pilha;
    
    int pop(pilha *P);
    int fVerificaPilhaVazia(pilha p);

    void fIniciaPilha(pilha *p) {
        *p = NULL;
    }

    void push(pilha *p, int x) {
        pilha tmp;
        tmp = (pilha) malloc(sizeof (cel));
        tmp->prox = *p;
        *p = tmp;
        (*p)->elem = x;
    }

    //    int pop(pilha *P) {
    //        if (!fVerificaPilhaVazia(*P)) {
    //            P->elem--;
    //            return (P->dados[P->elem]);
    //        } else
    //            return (SEMVALOR);
    //    }

    //    int pop(pilha *p) {
    //        pilha tmp;
    //        int ret;
    //        if (! fVerificaPilhaVazia(*p)) {
    //            ret = (*p)->elem;
    //            tmp = *p;
    //            *p = (*p)->prox;
    //            free(tmp);
    //            return ret;
    //        } else return (MAXINT);
    //    }

    int pop(pilha *P) {
        pilha tmp;
        int ret;
        if (!// <editor-fold defaultstate="collapsed" desc="comment">
                fVerificaPilhaVazia// </editor-fold>
                (*P)) {
            ret = (*P)->elem;
            tmp = *P;
            *P = (*P)->prox;
            free(tmp);
            return ret;
        } else return (SEMVALOR);
    }

    int top(pilha p) {
        if (!fVerificaPilhaVazia(p))
            return (p->elem);
        else return (MAXINT);
    }

    int fVerificaPilhaVazia(pilha p) {
        return (p == NULL);
    }

    int fVerificaPilhaCheia(pilha p) {
        return (0);
    }

    void fInvertePilha(pilha *p) {
        pilha tmp;
        fIniciaPilha(&tmp);
        while (!fVerificaPilhaVazia(*p))
            push(&tmp, pop(p));
        *tmp;
    }

    void fPreenchePilha(pilha p, pilha p2) {
        pilha tmp, tmp2;
        fIniciaPilha(&tmp);
        tmp2 = p;
        while (!fVerificaPilhaVazia(p))
            push(&tmp, pop(&p));
        while (!fVerificaPilhaVazia(tmp))
            push(&p2, pop(&tmp));
        p = tmp2;
    }

    void fListarElementosPilha(pilha *P) {
        printf("\n\nListagem dos Elementos da Pilha\n");
        pilha tmp;
        int x;
        fIniciaPilha(&tmp);
        while (!fVerificaPilhaVazia(*P)) {
            x = pop(P);
            //printf("%d\n",x);
            fprintf(stdout, "------------\n");
            fprintf(stdout, "Dados de N...: %d\n", x);
            fprintf(stdout, "------------\n");
            push(&tmp, x);
        }
        while (!fVerificaPilhaVazia(tmp)) {
            push(P, pop(&tmp));
        }
    }

    //    void fConcatenaPilha(pilha *p1, pilha p2) {
    //        pilha tmp;
    //        fIniciaPilha(&tmp);
    //        while (!fVerificaPilhaVazia(*p1))
    //            push(&tmp, pop(p1));
    //        while (!fVerificaPilhaVazia(tmp)) {
    //            push(p2, top(tmp));
    //            push(p1, pop(&tmp));
    //        }
    //    }

    int popn(pilha *p, int n, int *res) {
        int cont = 0;
        while (!fVerificaPilhaVazia(*p)) {
            res[cont] = pop(p);
            cont++;
        }
        return cont;
    }

    //Operações Relacionadas à Fila

//    void fIniciaFila(fila *F) {
//        F->inicio = NULL;
//        F->final = NULL;
//    }
//
//    int fVerificaFilaCheia(fila F) {
//        return (0);
//    }
//
//    int fVerificaFilaVazia(fila F) {
//        return (F.inicio == NULL);
//    }
//
//    void enqueue(fila *F, int x) {
//        lista tmp;
//        tmp = (lista) malloc(sizeof (struct cel));
//        tmp->prox = NULL;
//        tmp->elem = x;
//        if (fVerificaFilaVazia(*F)) { /* inicio==final==NULL */
//            F->inicio = tmp;
//            F->final = tmp;
//        } else {
//            F->final->prox = tmp;
//            F->final = tmp;
//        }
//    }
//
//    int dequeue(fila *F) {
//        lista tmp;
//        int retorno;
//        if (fVerificaFilaVazia(*F))
//            retorno = SEMVALOR;
//        else {
//            tmp = F->inicio->prox;
//            retorno = F->inicio->elem;
//            free(F->inicio);
//            F->inicio = tmp;
//            if (F->inicio == NULL)
//                F->final = NULL;
//            return (retorno);
//        }
//    }
//
//    void fListarElementosFila(fila *F) {
//        lista tmp = F->inicio;
//        while (tmp != NULL) {
//            printf("\n%d", tmp->elem);
//            tmp = tmp->prox;
//        }
//    }
//
//    void fListarElementosFila2(fila *MF) {
//        int x;
//        while (!fVerificaFilaVazia(*MF)) {
//            x = dequeue(MF);
//            printf("\n%d", x);
//
//            enqueue(MF, x);
//        }
//    }
//
//    void fListarElementosFila3(fila *MF) {
//        int x;
//        enqueue(MF, MAXINT - 1);
//        do {
//            x = dequeue(MF);
//            if (x != MAXINT - 1)
//                printf("\n%d", x);
//            enqueue(MF, x);
//        } while (x != MAXINT - 1);
//    }

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