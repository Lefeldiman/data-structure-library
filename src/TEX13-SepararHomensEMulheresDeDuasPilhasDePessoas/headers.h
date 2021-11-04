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
#include <assert.h>
    //#include <conio.h>

#define INT_MAX 0x7FFFFFFF
#define bool int
#define TRUE 1
#define FALSE 0
#define MAX_PILHA 5
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
    typedef cel* pilha;

    void fIniciaPilha(pilha *p);
    void fListarElementosPilha(pilha pPilha);
    void fSepararRegistrosGeneroMasculino(pilha pPilha);
    void fSepararRegistrosGeneroFeminino(pilha pPilha);
    void fPesquisaElementoPilha(int y, pilha pPilha);
    void push(pilha *p, int vIdentidade, char vGenero, char vNome[50]);
    void fInvertePilha(pilha *p);
    void fPreenchePilha(pilha p, pilha p2);
    void fConcatenaPilha(pilha *p1, pilha p2);
    int fVerificaPilhaVazia(pilha p);
    int fVerificaPilhaCheia(pilha p);
    int pop(pilha *P, int vIdentidade);
    int top(pilha P);
    

    void fIniciaPilha(pilha *p) {
        *p = NULL;
    }

    int fVerificaPilhaVazia(pilha p) {
        return (p == NULL);
    }

    int fVerificaListaVazia(pilha L) {
        return (L == NULL);
    }

    int fVerificaPilhaCheia(pilha p) {
        return (0);
    }

    void push(pilha *p, int vIdentidade, char vGenero, char vNome[50]) {
        pilha tmp;
        int vTotalCaracteres, i;
        tmp = (pilha) malloc(sizeof (cel));
        tmp->prox = *p;
        *p = tmp;
        (*p)->esse.vIdentidade = vIdentidade;
        (*p)->esse.vGenero = vGenero;
        vTotalCaracteres = strlen(vNome);
        for (i = 0; i <= vTotalCaracteres; i++) {
            (*p)->esse.vNome[i] = vNome[i];
        }
    }

    int pop(pilha *P, int vIdentidade) {
        pilha tmp;
        int ret;
        if (!fVerificaPilhaVazia(*P)) {
            ret = (*P)->esse.vIdentidade;
            if (ret == vIdentidade) {
                tmp = *P;
                *P = (*P)->prox;
                free(tmp);
                return ret;
            }
            return vIdentidade;
        }
        else return INT_MAX;
    }

    int top(pilha P) {
        if (!fVerificaPilhaVazia(P))
            return (P->esse.vIdentidade);
        else return SEMVALOR;
    }

    void fListarElementosPilha(pilha pPilha) {
        printf("\n\nListagem das Pessoas na Pilha\n");
        if (!fVerificaListaVazia(pPilha)) {
            while (pPilha != NULL) {
                fprintf(stdout, "\n|--------------------------------------|\n");
                fprintf(stdout, "| Identidade...: %d               \n", pPilha->esse.vIdentidade);
                fprintf(stdout, "| Gênero.......: %c                     |\n", pPilha->esse.vGenero);
                fprintf(stdout, "| Nome.........: %s                      \n", pPilha->esse.vNome);
                fprintf(stdout, "|--------------------------------------|\n");
                pPilha = pPilha->prox;
            }
        }
        sleep(1);
    }
    
    void fSepararRegistrosGeneroFeminino(pilha pPilha) {
        if (!fVerificaListaVazia(pPilha)) {
            while (pPilha != NULL) {
                if(pPilha->esse.vGenero == 'F'){
                fprintf(stdout, "\n|--------------------------------------|\n");
                fprintf(stdout, "| Identidade...: %d               \n", pPilha->esse.vIdentidade);
                fprintf(stdout, "| Gênero.......: %c                     |\n", pPilha->esse.vGenero);
                fprintf(stdout, "| Nome.........: %s                      \n", pPilha->esse.vNome);
                fprintf(stdout, "|--------------------------------------|\n");
                }//else
//                    fprintf(stdout, "Não Existem Pessoas do Gênero Feminio!\n");
                pPilha = pPilha->prox;
            }
        }
    }
    
    void fSepararRegistrosGeneroMasculino(pilha pPilha) {
        if (!fVerificaListaVazia(pPilha)) {
            while (pPilha != NULL) {
                if(pPilha->esse.vGenero == 'M'){
                fprintf(stdout, "\n|--------------------------------------|\n");
                fprintf(stdout, "| Identidade...: %d               \n", pPilha->esse.vIdentidade);
                fprintf(stdout, "| Gênero.......: %c                     |\n", pPilha->esse.vGenero);
                fprintf(stdout, "| Nome.........: %s                      \n", pPilha->esse.vNome);
                fprintf(stdout, "|--------------------------------------|\n");
                }//else
//                    fprintf(stdout, "Não Existem Pessoas do Gênero Masculino!\n");
                pPilha = pPilha->prox;
            }
        }
    }
        
     char ftela() {
        char opcao, linha[80];
        puts("================================================================================");
        puts("|                 Programa De Pessoas Utilizando Pilha - Separa Gêneros         |");
        puts("================================================================================");
        puts("\n\n\tA- Inserir Um Registro De Tipo Pessoa Na 1 Pilha "
                "\n\n\tB- Inserir Um Registro De Tipo Pessoa Na 2 Pilha "
                "\n\n\tC- Listar As Pessoas da Pilha "
                "\n\n\tD- Separar Gêneros das Pilhas 1 e 2 "
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