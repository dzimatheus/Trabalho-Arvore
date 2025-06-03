#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

No getnode() {
    No p;
    p=(No)malloc(sizeof(struct Nodo));
    return p;
}

No criarArvore(int chave){
    No raiz;
    raiz = getnode();
    raiz->info = chave;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

No inserir(No raiz, int chave){
    if(raiz == NULL)
        raiz = criarArvore(chave);
    else{
        if(chave <= raiz->info)
            raiz->esq = inserir(raiz->esq, chave);
        else
            raiz->dir = inserir(raiz->dir, chave);
    }
    return raiz;
}

No buscar_chave(No raiz, int chave){
    while(raiz != NULL && chave != raiz->info){
        if(chave < raiz->info)
            raiz = raiz->esq;
        else 
            raiz = raiz->dir;
    }
    return raiz;
}

No remover(No raiz, int chave){
    if(raiz == NULL)
        return NULL;
    if(chave < raiz->info)
        raiz->esq = remover(raiz->esq, chave);
    else
        if(chave > raiz->info)
            raiz->dir = remover(raiz->dir, chave);
        else{ //Nó folha
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                return NULL;
            }else // Um filho à direita
                if(raiz->esq == NULL){
                    No aux = raiz->dir;
                    free(raiz);
                    return aux;
                }
                else // Um filho à esquerda
                    if(raiz->dir == NULL){
                        No aux = raiz->esq;
                        free(raiz);
                        return aux;
                    }
                    else{
                        No aux = raiz->dir;
                        while(aux->esq != NULL)
                            aux = aux->esq;
                        raiz->info = aux->info;
                        raiz->dir = remover(raiz->dir, aux->info);
                    }
        }
    return raiz;
}

void pre_ordem(No raiz){
    if(raiz != NULL){
        printf(" %d ", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(No raiz){
    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf(" %d ", raiz->info);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(No raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf(" %d ", raiz->info);
    }
}

No predecessor(No raiz, No x){
    if(x == NULL)
        return NULL;
    // existe filho à esquerda
    if(x->esq != NULL){
        No aux = x->esq;
        while(aux->dir != NULL)
            aux = aux->dir;
        return aux;
    }
    //não existe filho à esquerda
    No pred = NULL;
    while(raiz != NULL){
        if(x->info > raiz->info){
            pred = raiz;
            raiz= raiz->dir;
        } else
            if(x->info < raiz->info)
                raiz = raiz->esq;
            else 
                break;
    }
    return pred;
}

No sucessor(No raiz, No x){
    if(x == NULL)
        return NULL;
    //existe filho à direita
    if(x->dir != NULL){
        No aux = x->dir;
        while(aux->esq != NULL)
            aux = aux->esq;
        return aux;
    }
    //não existe filho à direita
    No suc = NULL;
    while(raiz != NULL){
        if(x->info < raiz->info){
            suc = raiz;
            raiz = raiz->esq;
        }else  
            if(x->info > raiz->info)
                raiz = raiz->dir;
            else 
                break;
    }
    return suc;
}

No maximo(No raiz){
    while(raiz->dir != NULL){
        raiz = raiz->dir;
    }
    return raiz;
}

No minimo(No raiz){
    while(raiz->esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;
}
