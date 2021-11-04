/* 
 * File:   headers.h
 * Author: root
 *
 * Created on May 3, 2016, 9:51 PM
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
#include <assert.h>
    //#include <conio.h>

#define INT_MAX 0x7FFFFFFF
#define bool int
#define TRUE 1
#define FALSE 0
#define MAX_PILHA 5
#define SEMVALOR INT_MAX

    typedef struct s_cel {
        int elem;
        struct s_cel *esq, *dir, *pai;
    } cel;
    typedef cel * no;


    no cria_arv();
    no dir(no p);
    no esq(no p);
    no pai(no p);
    no irmao(no p);
    int adir(no p);
    int aesq(no p);
    int maior(no p);
    void monta_arv(no raiz);
    void visita(no p);
    void prefixa(no p);
    void infixa(no p);
    void posfixa(no p);

    no cria_arv() {
        no arvore;
        arvore = (no) malloc(sizeof (cel));
        arvore->esq = NULL;
        arvore->dir = NULL;
        return (arvore);
    }

    void monta_arv(no raiz) {
        int valor, op;
        printf("Valor a ser colocado na arvore ...: ");
        scanf("%d", &valor);
        raiz->elem = valor;
        printf("Colocar filho a esquerda de ...: %d (1-sim/0-nao)? ", raiz->elem);
        scanf("%d", &op);
        if (op != 0) {
            raiz->esq = cria_arv();
            monta_arv(raiz->esq);
        }
        printf("Colocar filho a direita de ...: %d (1-sim/0-nao)? ", raiz->elem);
        scanf("%d", &op);
        if (op != 0) {
            raiz->dir = cria_arv();
            monta_arv(raiz->dir);
        }
    }

    no dir(no p) {
        if (p)
            return p->dir;
        return NULL;
    }

    no esq(no p) {
        if (p)
            return p->esq;
        return NULL;
    }

    no pai(no p) {
        if (p)
            return p->pai;
        return NULL;
    }

    int adir(no p) {
        if ((esq(pai(p))) == p)
            return 1;
        return 0;
    }

    int aesq(no p) {
        if ((dir(pai(p))) == p)
            return 1;
        return 0;
    }

    no irmao(no p) {
        if (aesq(p))
            return dir(pai(p));
        return esq(pai(p));
    }

    void visita(no p) {
        printf("%d, ", p->elem);
    }

    void prefixa(no p) {
        if (p == NULL)
            return;
        visita(p);
        prefixa(p->esq);
        prefixa(p->dir);
    }

    void infixa(no p) {
        if (p == NULL)
            return;
        infixa(p->esq);
        visita(p);
        infixa(p->dir);
    }

    void posfixa(no p) {
        if (p == NULL)
            return;
        posfixa(p->esq);
        posfixa(p->dir);
        visita(p);
    }

    int maior(no p) {
        int x, y;
        if (p == NULL)
            return 0;
        x = maior(p->dir);
        if (x < p->elem)
            x = p->elem;
        y = maior(p->esq);
        if (x < y)
            x = y;
        return (x);
    }

    char ftela() {
        char opcao, linha[80];
        puts("================================================================================");
        puts("|                 Programa De Árvore Binária Não Ordenada                       |");
        puts("================================================================================");
        puts("\n\n\tA- Digite os Dados na Árvore "
                "\n\n\tB- Imprime Em Ordem InFixa "
                "\n\n\tC- Imprime Em Ordem PréFixa "
                "\n\n\tD- Imprime Em Ordem PósFixa"
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



