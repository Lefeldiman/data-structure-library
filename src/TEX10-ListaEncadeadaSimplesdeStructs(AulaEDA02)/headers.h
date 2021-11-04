/* 
 * File:   headers.h
 * Author: root
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
#define TRUE = 1;
#define FALSE = 0;

    typedef struct s_cel {
        float vMensalidade;
        long long int vMatricula;
        char vNomeCompleto[500][400];
        struct s_cel *prox;
        struct s_cel *ant;
    } cel;
    typedef cel* lista;

    void fInicializaListaCircular(lista *L) {
        *L = NULL;
    }

    int fVerificaListaVazia(lista L) {
        return (L == NULL);
    }

    void fIncluiElementoTopo(lista *L) {
        cel *tmp;
        int i;
        long long int vetMatricula[500];
        float vetMensalidade[500];
        for (i = 1; i <= 500; i++) {
            vetMatricula[i] = rand() % 10000 + 100;
            vetMensalidade[i] = (rand() % (120968 - 341 + 67) + 341) / 500.0;
            tmp = (cel*) malloc(sizeof (cel));
            tmp->vMatricula = vetMatricula[i];
            tmp->vMensalidade = vetMensalidade[i];
            tmp->prox = *L;
            (*L) = tmp;
        }
        sleep(2);
    }

    void fGeraNomeRandonico(lista *L) {
        cel *tmp;
        char Primeiro[5][20] = {"Pedro", "Tiago", "Ana", "Bruno", "Camila"};
        char Meio[5][20] = {"Oliveira", "Antunes", "Ferreira", "Santos", "Cunha"};
        char Sobrenome[5][20] = {"Cardoso", "Silva", "Azevedo", "Monteiro", "Soares"};
        char vetNomeCompleto[500][400];
        char vVazio[2];
        int i, iPrimeiro, iSegundo, iTerceiro;
        long long int vetMatricula[500];
        float vetMensalidade[500];
        vVazio[0] = ' ';

        for (i = 1; i <= 500; i++) {
            vetMatricula[i] = rand() % 10000 + 100;
            vetMensalidade[i] = (rand() % (120968 - 341 + 67) + 341) / 500.0;
            for (iPrimeiro = 0; iPrimeiro < 20; iPrimeiro++) {
                for (iSegundo = 0; iSegundo < 20; iSegundo++) {
                    for (iTerceiro = 0; iTerceiro < 20; iTerceiro++) {
                        strcat(vetNomeCompleto[i], Primeiro[iPrimeiro]);
                        strcat(vetNomeCompleto[i], vVazio);
                        strcat(vetNomeCompleto[i], Meio[iSegundo]);
                        strcat(vetNomeCompleto[i], vVazio);
                        strcat(vetNomeCompleto[i], Sobrenome[iTerceiro]);
                        printf("%s \n", vetNomeCompleto[i]);
                        i++;
                    }
                }
            }
            tmp = (cel*) malloc(sizeof (cel));
            tmp->vMatricula = vetMatricula[i];
            tmp->vMensalidade = vetMensalidade[i];
            //            tmp->vNomeCompleto[0] = vetNomeCompleto[i];
            tmp->prox = *L;
            (*L) = tmp;
        }
        sleep(2);
    }

    void fIncluiElementoPosPesquisar(lista *L, int vMatricula) {
        cel *tmp;
        int i;
        float vetMensalidade[2];
        for (i = 1; i <= 1; i++) {
            vetMensalidade[i] = (rand() % (120968 - 341 + 67) + 341) / 500.0;
            tmp = (cel*) malloc(sizeof (cel));
            tmp->vMatricula = vMatricula;
            tmp->vMensalidade = vetMensalidade[i];
            tmp->prox = *L;
            (*L) = tmp;
        }
        printf("\n\n\t\t\t\t A Matrícula %d Foi Incluída na Lista, Utilize a Opção C do Menu para pesquisá-la!\n", vMatricula);
        sleep(2);
    }

    void fIncluiElementoTopoCircular(lista *p_L, int x) {
        lista tmp2;
        int i;
        int vetMatricula[500];
        for (i = 1; i <= 500; i++) {
            vetMatricula[i] = rand() % 900 + 100;
            printf("Matrícula...: %d\n", vetMatricula[i]);
        }
        if ((*p_L == NULL) || ((*p_L)->vMensalidade > vetMatricula[i])) {
            cel *tmp;
            tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
            tmp->prox = *p_L; /*2- apontando p/ lista*/
            (*p_L) = tmp; /*3-elemento é o novo primeiro*/
            (*p_L)->vMensalidade = vetMatricula[i]; /*armazenar o vMensalidadeor do elemento*/
            (*p_L)->vMatricula = 1;
        } else {
            tmp2 = *p_L;
            while ((tmp2->prox != NULL)&& (tmp2->prox->vMensalidade <= vetMatricula[i])) {
                tmp2 = tmp2->prox; /*operação a fazer sobre cada elemento*/
            }
            if (tmp2->vMensalidade != vetMatricula[i]) {
                cel *tmp;
                tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
                tmp->prox = tmp2->prox; /*2- apontando p/ lista*/
                tmp2->prox = tmp; /*3-elemento é o novo primeiro*/
                tmp->vMensalidade = vetMatricula[i]; /*armazenar o vMensalidadeor do elemento*/
                tmp->vMatricula = 1;
            } else {
                tmp2->vMatricula++;
            }
        }
        sleep(2);
    }

    void fExcluiElementoTopo(lista *L) {
        cel *tmp;
        if (!fVerificaListaVazia(*L)) {
            tmp = *L; /*1-salvar endereço do 1o     */
            (*L) = tmp->prox; /*2-L aponta p/ resto da lista*/
            free(tmp); /*3-liberar a memória         */
        }
        sleep(2);
    }

    void fExcluiElementoPesquisado(int y, lista pLista, lista *L) {
        cel *tmp;
      //  cel ant = NULL;
        int achou = 0;
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vMatricula == y) {
                fprintf(stdout, "A seguinte matrícula foi encontrada!\n");
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Matrícula....: %d\n", pLista->vMatricula);
                fprintf(stdout, "Mensalidade..: %.4f\n", pLista->vMensalidade);
                fprintf(stdout, "------------\n");
                achou++;
            }
        }
                tmp = *L;
                (*L) = tmp->prox;
                free(tmp);
                free(pLista);
        fprintf(stdout, "A Matrícula %d Foi Removida!\n", y);
        if (achou == 0) {
            fprintf(stdout, "Nenhuma Matrícula Encontrada!\n");
            fIncluiElementoPosPesquisar(&pLista, y);
        } else {
            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
            sleep(2);
        }
    }

    //    void fExcluiElementoCauda(lista *L) {
    //        cel *tmp;
    //        if (!fVerificaListaVazia(*L)) {
    //            tmp = *L; /*1-salvar endereço do 1o     */
    //            if (tmp->prox == NULL) //Lista tem só um elemento
    //            {
    //                *L = NULL;
    //                free(tmp);
    //                return;
    //            }
    //            while (tmp->prox->prox != NULL) //Lista com 2 ou mais elementos
    //                tmp = tmp->prox;
    //            free(tmp->prox);
    //            tmp->prox = NULL;
    //        }
    //    }

    void fListarElementosLista(lista pLista) {
        printf("\n\nListagem dos dados da Lista Encadeada :\n");
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Matrícula...: %d\n", pLista->vMatricula);
                fprintf(stdout, "Mensalidade.: %.2f\n", pLista->vMensalidade);
                fprintf(stdout, "------------\n");
                pLista = pLista->prox;
            }
        }
        sleep(2);
    }

    //    void fQuantidadeElementos(lista pLista) {
    //        int i = 0;
    //        if (!fVerificaListaVazia(pLista)) {
    //            while (pLista != NULL) {
    //                pLista = pLista->prox;
    //                i++;
    //            }
    //            printf("A Quantidade de dados da Lista Encadeada é: %d\n", i);
    //            //pLista->vMatricula = i;
    //        }
    //    }

    void fMediaElementos(lista pLista) {
        int i = 0;
        float vSoma = 0;
        float vMedia;
        if (!fVerificaListaVazia(pLista)) {
            while (pLista != NULL) {
                vSoma = vSoma + pLista->vMensalidade;
                pLista = pLista->prox;
                i++;
            }
            vMedia = vSoma / i;
            printf("\n\nA Média das Mensalidades da Lista Encadeada é: %.2f\n", vMedia);
        }
        sleep(2);
    }

    void fPesquisaElemento(int y, lista pLista) {
        int achou = 0;
        //while (pLista != NULL)
        for (; pLista != NULL; pLista = pLista->prox) {
            if (pLista->vMatricula == y) {
                fprintf(stdout, "------------\n");
                fprintf(stdout, "Matrícula....: %d\n", pLista->vMatricula);
                fprintf(stdout, "Mensalidade..: %.4f\n", pLista->vMensalidade);
                fprintf(stdout, "------------\n");
                achou++;
            }
        }
        if (achou == 0) {
            fprintf(stdout, "Nenhuma Matrícula Encontrada!\n");
            fIncluiElementoPosPesquisar(&pLista, y);
        } else {
            fprintf(stdout, "Foram encontrados %d registros.\n", achou);
            sleep(2);
        }
    }

    char ftela() {
        char opcao, linha[80];
        puts(": ================  Programa De Alunos Em Uma Lista Encadeada  ================ :\n");
        puts("\n\n\t\tA- Gerar 500 Alunos Na Lista Encadeada "
                "\n\n\t\tB- Listar Alunos da Lista Encadeada "
                "\n\n\t\tC- Pesquisar Matrícula na Lista Encadeada "
                "\n\n\t\tD- Remover Matrícula da Lista Encadeada "
                "\n\n\t\tE- Gerar A Média das Mensalidades dos Alunos "
                "\n\n\t\tS - Sair"
                "\n\n\n\t\t\tQual a sua Opção: ");
        fgets(linha, sizeof (linha), stdin);
        sscanf(linha, "%c", &opcao);
        return tolower(opcao);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* HEADERS_H */