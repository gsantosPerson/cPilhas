#include <stdio.h>
#include <stdlib.h>

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

void imprimir(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return;
    }

    for(int i = p->topo; i >= 0; i--){
        printf("%d ", p->conteudo[i]);
    }
}

int main(){

    int valorEntrada, i, tamEntrada;

    Pilha *p = criar(4);

    empilhar(p, 1);
    empilhar(p, 2);
    empilhar(p, 5);
    empilhar(p, 10);

    Pilha *p2 = criar(5);

    empilhar(p2, 7);
    empilhar(p2, 12);
    empilhar(p2, 15);
    empilhar(p2, 18);
    empilhar(p2, 22);
    /*for(i = 0; i < tamEntrada; i++){
        printf("Valor: ");
        scanf("%d", &valorEntrada);
        empilhar(p, valorEntrada);
    }*/

    //desempilhar(p);
    imprimir(p);
    puts("");
    imprimir(p2);

return 0;
}
