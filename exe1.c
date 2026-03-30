#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Pilha{
    int *conteudo;
    int topo;
    int tamanho;
}Pilha;

Pilha *criar(int tamanhoEntrada){
    Pilha *p = malloc(sizeof(Pilha));
    p->conteudo = malloc(tamanhoEntrada * sizeof(int));
    p->topo = -1;
    p->tamanho = tamanhoEntrada;
    return p;
}

int isFull(Pilha *p){
    return p->topo == p->tamanho - 1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

int empilhar(Pilha *p, int valor){
    if(isFull(p)){
        printf("\nPilha cheia\n");
        return 0;
    }

    p->conteudo[++p->topo] = valor;

    return 1;
}

int desempilhar(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return 0;
    }

    int valor = p->conteudo[p->topo--];

    return valor;
}


void mostrar(int a[], char *nomePilha){
    Pilha *p = criar(5);

    printf("\n%s: ", nomePilha);

    for(int i = 0; i < 5; i++){
        empilhar(p, a[i]);
    }

    for(int i = p->topo; i >= 0; i--){
        printf("%d ", desempilhar(p));
    }

    free(p);
    free(p->conteudo);

    }

int main(){
    setlocale(LC_ALL, "pt-br");

    int a[] = {1,2,4,5,10};
    mostrar(a, "Pilha A");

    int b[] = {7, 12, 15, 18, 22};
    mostrar(b, "Pilha B");


return 0;
}
