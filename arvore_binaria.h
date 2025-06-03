#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo* esq;
    struct Nodo* dir;
};

typedef struct Nodo *No;

No getnode();
No criarArvore(int chave);
No inserir(No raiz, int chave);
No buscar_chave(No raiz, int chave);
No remover(No raiz, int chave);
void pre_ordem(No raiz);
void em_ordem(No raiz);
void pos_ordem(No raiz);
No predecessor(No raiz, No x);
No sucessor(No raiz, No x);
No maximo(No raiz);
No minimo(No raiz);
