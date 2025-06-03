#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    No raiz = NULL;

    // Inserir
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Pre-ordem: ");
    pre_ordem(raiz);

    printf("\nEm ordem: ");
    em_ordem(raiz);

    printf("\nPos-ordem: ");
    pos_ordem(raiz);

    // Buscar chave
    int chave = 40;
    No encontrado = buscar_chave(raiz, chave);
    if(encontrado)
        printf("Chave %d encontrada!\n", chave);
    else
        printf("Chave %d nao encontrada!\n", chave);

    // Predecessor
    No pred = predecessor(raiz, encontrado);
    if(pred)
        printf("Predecessor de %d: %d\n", chave, pred->info);
    else
        printf("Nao ha predecessor para %d\n", chave);

    // Sucessor
    No suc = sucessor(raiz, encontrado);
    if(suc)
        printf("Sucessor de %d: %d\n", chave, suc->info);
    else
        printf("Nao ha sucessor para %d\n", chave);

    // Máximo e mínimo
    No min = minimo(raiz);
    No max = maximo(raiz);
    printf("Minimo: %d\n", min->info);
    printf("Maximo: %d\n", max->info);

    // Remover
    raiz = remover(raiz, 20); // remove folha
    raiz = remover(raiz, 30); // remove nó com um filho
    raiz = remover(raiz, 50); // remove nó com dois filhos
    
    printf("Em ordem apos remocoes: ");
    em_ordem(raiz);
    return 0;
}
