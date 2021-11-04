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
#define MININT -32768

    typedef struct s_cel {
        int elem;
        struct s_cel *esq, *dir, *pai;
    } cel;
    typedef cel * no;


    no fCriaArvore();
    no dir(no p);
    no esq(no p);
    no pai(no p);
    no irmao(no p);
    int adir(no p);
    int aesq(no p);
    int fRetornaElementoMaior(no p);
    void fMontaArvore(no raiz);
    void fVisitaElemento(no p);
    void fImprimePreFixa(no p);
    void fImprimeInFixa(no p);
    void fImprimePosFixa(no p);

    no fCriaArvore() {
        no arvore;
        arvore = (no) malloc(sizeof (cel));
        arvore->esq = NULL;
        arvore->dir = NULL;
        return (arvore);
    }

    void fMontaArvore(no raiz) {
        int valor, op;
        printf("Valor a ser colocado na arvore ...: ");
        scanf("%d", &valor);
        raiz->elem = valor;
        printf("Colocar filho a esquerda de ...: %d (1-sim/0-nao)? ", raiz->elem);
        scanf("%d", &op);
        if (op != 0) {
            raiz->esq = fCriaArvore();
            fMontaArvore(raiz->esq);
        }
        printf("Colocar filho a direita de ...: %d (1-sim/0-nao)? ", raiz->elem);
        scanf("%d", &op);
        if (op != 0) {
            raiz->dir = fCriaArvore();
            fMontaArvore(raiz->dir);
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

    void fVisitaElemento(no p) {
        printf("%d, ", p->elem);
    }

    void fImprimePreFixa(no p) {
        if (p == NULL)
            return;
        fVisitaElemento(p);
        fImprimePreFixa(p->esq);
        fImprimePreFixa(p->dir);
    }

    void fImprimeInFixa(no p) {
        if (p == NULL)
            return;
        fImprimeInFixa(p->esq);
        fVisitaElemento(p);
        fImprimeInFixa(p->dir);
    }

    void fImprimePosFixa(no p) {
        if (p == NULL)
            return;
        fImprimePosFixa(p->esq);
        fImprimePosFixa(p->dir);
        fVisitaElemento(p);
    }

    //    int fRetornaSomaElemento(no raiz) {
    //        int vSoma = 0;
    //        if (raiz == NULL)
    //            return 0;
    //        while (raiz->elem != NULL) {
    //            fVisitaElemento(raiz);
    //            vSoma = vSoma + raiz->elem;
    //        }
    //        return (vSoma);
    //    }

    //Função que retorna a soma dos elementos de uma árvore 
    //passada como parâmetro;

    int fRetornaSomaElemento2(no raiz) {
        if (raiz == NULL) return 0;
        return (raiz->elem + fRetornaSomaElemento2(raiz->esq) + fRetornaSomaElemento2(raiz->dir));

    }
    //
    //    int fRetornaQuantidadeElemento(no raiz) {
    //        int i;
    //        if (raiz == NULL)
    //            return 0;
    //        while (raiz->elem != NULL) {
    //            fVisitaElemento(raiz);
    //            i++;
    //        }
    //        return (i);
    //    }

    //Função que retorna o número de nós de uma árvore binária

    int fRetornaQuantidadeElemento2(no raiz) {
        if (raiz == NULL) return 0;
        return (fRetornaQuantidadeElemento2(raiz->esq) + fRetornaQuantidadeElemento2(raiz->dir) + 1);
    }

    int fRetornaElementoMaior(no p) {
        int x, y;
        if (p == NULL)
            return 0;
        x = fRetornaElementoMaior(p->dir);
        if (x < p->elem)
            x = p->elem;
        y = fRetornaElementoMaior(p->esq);
        if (x < y)
            x = y;
        return (x);
    }

    int fRetornaEnderecoNoElemento(no raiz, int X) {
        int *vReturnEndereco;
      //  no Resul = NULL;
        if (X == raiz->elem)
            return vReturnEndereco = &raiz;
        if (fRetornaEnderecoNoElemento(raiz->esq, X) != NULL)
            return vReturnEndereco = &raiz;
        if (fRetornaEnderecoNoElemento(raiz->dir, X) != NULL)
            return vReturnEndereco = &raiz;
        return vReturnEndereco;
    }

    //Função que retorna a fRetornaAltura de uma árvore binária

    int fRetornaAltura(no raiz) {
        if (raiz == NULL)
            return 0; // fRetornaAltura de árvore vazia é 0
        else {
            int hesq = fRetornaAltura(raiz->esq);
            int hdir = fRetornaAltura(raiz->dir);
            if (hesq < hdir) return hdir + 1;
            else return hesq + 1;
        }
    }

    //Função que retorna o Maior dos elementos de uma árvore  binária

    int fRetornaElementoMaior2(no raiz) {
        int Valor = MININT; //Erro
        if (raiz != NULL) {
            Valor = raiz->elem;
            int MaiorEsq = fRetornaElementoMaior2(raiz->esq);
            if (Valor < MaiorEsq)
                Valor = MaiorEsq;
            int MaiorDir = fRetornaElementoMaior2(raiz->dir);
            if (Valor < MaiorDir)
                Valor = MaiorDir;
        }
        return Valor;
    }

    //Função que recebe uma  árvore e um valor inteiro 
    //- retorna o nó do elemento que possua tal valor inteiro, 
    //caso exista na árvore;

    no fPesquisaElementoArvore(no raiz, int X) {
        no Resul = NULL;
        if (X == raiz->elem)
            return raiz;
        if (Resul = fPesquisaElementoArvore(raiz->esq, X) != NULL)
            return Resul;
        if (Resul = fPesquisaElementoArvore(raiz->dir, X) != NULL)
            return Resul;
        return Resul;
    }

    char ftela() {
        char opcao, linha[80];
        puts("================================================================================");
        puts("                  Programa De Árvore Binária Não Ordenada                       ");
        puts("================================================================================");
        puts("\n\n\tA- Digite os Dados na Árvore "
                "\n\n\tB- Imprime Em Ordem InFixa "
                "\n\n\tC- Imprime Em Ordem PréFixa "
                "\n\n\tD- Imprime Em Ordem PósFixa "
                "\n\n\tE- Retornar a Soma dos Elementos da Árvore "
                "\n\n\tF- Retornar a Quantidade dos Elementos da Árvore "
                "\n\n\tG- Retornar o Maior Elemento da Árvore "
                "\n\n\tH- Retorna o Endereço do nó do Elemento que possua tal valor inteiro "
                "\n\n\tI- Pesquisa Elemento na Árvore  "
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



