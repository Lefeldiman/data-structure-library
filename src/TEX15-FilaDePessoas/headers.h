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

#define INT_MAX 0x7FFFFFFF
#define bool int
#define TRUE 1
#define FALSE 0
#define MAX_PILHA 100
#define SEMVALOR INT_MAX

    typedef struct {
        int vIdentidade;
        char vGenero;
        char vNome[50];
    } pessoa;

    typedef struct s_cel {
        pessoa esse;
        struct s_cel *prox;
    } cel;
    typedef cel* lista;

    typedef struct {
        cel *inicio, *final;
    } fila;

    void fIniciaFila(fila *F) {
        F->inicio = NULL;
        F->final = NULL;
    }

    int fVerificaFilaCheia(fila F) {
        return (0);
    }

    int fVerificaFilaVazia(fila F) {
        return (F.inicio == NULL);
    }

    void enqueue(fila *F, int x) {
        lista tmp;
        tmp = (lista) malloc(sizeof (struct cel));
        tmp->prox = NULL;
        tmp->esse.vIdentidade = x;
        if (fVerificaFilaVazia(*F)) {
            F->inicio = tmp;
            F->final = tmp;
        } else {
            F->final->prox = tmp;
            F->final = tmp;
        }
    }

    int dequeue(fila *F) {
        lista tmp;
        int retorno;
        if (fVerificaFilaVazia(*F))
            retorno = SEMVALOR;
        else {
            tmp = F->inicio->prox;
            retorno = F->inicio->esse.vIdentidade;
            free(F->inicio);
            F->inicio = tmp;
            if (F->inicio == NULL)
                F->final = NULL;
            return (retorno);
        }
    }

    void fListarElementosFila(fila *F) {
        lista tmp = F->inicio;
        while (tmp != NULL) {
            printf("\n%d", tmp->esse.vIdentidade);
            tmp = tmp->prox;
        }
    }
    
    void fGeraFilaOrdemGenero(fila *F) {
        lista tmp = F->inicio;
        while (tmp != NULL) {
            printf("\n%d", tmp->esse.vIdentidade);
            tmp = tmp->prox;
        }
    }
    
    void fGeraFilaOrdemGenero(fila pFila) {
        lista pFila;
        if (!fVerificaFilaVazia(pFila)) {
            while (pFila != NULL) {
                if(pFila->esse.vGenero == 'F'){
                fprintf(stdout, "\n|--------------------------------------|\n");
                fprintf(stdout, "| Identidade...: %d               \n", pFila->esse.vIdentidade);
                fprintf(stdout, "| Gênero.......: %c                     |\n", pFila->esse.vGenero);
                fprintf(stdout, "| Nome.........: %s                      \n", pFila->esse.vNome);
                fprintf(stdout, "|--------------------------------------|\n");
                }
                pFila = pFila->prox;
            }
        }
    }

    char ftela() {
        char opcao, linha[80];
        puts("================================================================================");
        puts("|                 Programa De Pessoas Utilizando Fila                          |");
        puts("================================================================================");
        puts("\n\n\tA- Inserir Um Registro De Tipo Pessoa Na Fila "
                "\n\n\tB- Listar As Pessoas da Fila "
                "\n\n\tC- Gerar Mulheres Primeiro Depois Homens na Fila "
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