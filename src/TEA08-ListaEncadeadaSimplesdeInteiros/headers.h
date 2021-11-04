/* 
 * File:   headers.h
 * Author: siad02
 *
 * Created on 28 de Março de 2016, 14:26
 */

#ifndef HEADERS_H
#define	HEADERS_H

//#ifdef	__cplusplus
//extern "C" {
//#endif

typedef struct s_cel {
    int val;
    struct s_cel *prox;
} cel;
typedef cel* lista;

char tela();
void inicializarLista(lista *L);
int vazia(lista L);
void addElemTopo(lista *L, int x);
void addElemCauda(lista *L, int x);
void delElemTopo(lista *L);
void delElemCauda(lista *L);
void ListarElementos(lista L);    
    
void inicializarLista(lista *L) {
    *L = NULL;
}

int vazia(lista L) {
    return (L == NULL);
}

void addElemTopo(lista *L, int x) {
    cel *tmp;
    tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
    tmp->val = x; /*2-armazenar o valor do elemento*/
    tmp->prox = *L; /*3- apontando p/ lista*/
    (*L) = tmp; /*4-elemento é o novo primeiro*/
}

void addElemCauda(lista *L, int x) {
    cel *tmp;
    lista aux;
    tmp = (cel*) malloc(sizeof (cel)); /*1-criar uma nova cel */
    tmp->val = x; /*2-armazenar o valor do elemento*/
    tmp->prox = NULL; /*3- aponta para NULL (último da nova lista)*/
    if (vazia(*L)) /*caso de lista vazia */
        *L = tmp;
    else {
        aux = *L;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = tmp;
    }
}

void delElemTopo(lista *L) {
    cel *tmp;
    if (!vazia(*L)) {
        tmp = *L; /*1-salvar endereço do 1o     */
        (*L) = tmp->prox; /*2-L aponta p/ resto da lista*/
        free(tmp); /*3-liberar a memória         */
    }
}

void delElemCauda(lista *L) {
    cel *tmp;
    if (!vazia(*L)) {
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

void ListarElementos(lista L) {
    printf("\n\nListagem dos componentes da Lista Encadeada :\n");
    if (!vazia(L)) {
        while (L != NULL) {
            printf("Valor: %d\n", L->val);
            L = L->prox;
        }
    }
}    



//#ifdef	__cplusplus
//}
//#endif

#endif	/* HEADERS_H */

