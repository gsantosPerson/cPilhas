#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    float *conteudo;
    int topo;
    int tam;
}Pilha;

Pilha *criar(int tam){
    Pilha *p = malloc(sizeof(Pilha));
    p->conteudo = malloc(tam * sizeof(float));
    p->topo = -1;
    p->tam = tam;
}

int isFull(Pilha *p){
    return p->topo == p->tam - 1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

int push(Pilha *p, int valor){
    if(isFull(p)){
        printf("\nPilha cheia\n");
        return 0;
    }

    p->conteudo[++p->topo] = valor;
    return 1;
}

int pop(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return 0;
    }

    int valor = p->conteudo[p->topo--];

    return valor;
}

void imprimir(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia");
        return;
    }

    while(!isEmpty(p)){
        printf("%d ", pop(p));
    }
}

void copiar(Pilha *p1, Pilha *p2){
    Pilha *pAux = criar(p1->tam);
    int aux;

    while(!isEmpty(p1)){
        push(pAux, pop(p1));
    }


    while(!isEmpty(pAux)){
        aux = pop(pAux);
        push(p2, aux);
        push(p1, aux);
    }

}

int main(){
    int valor, i, tamanho;

    printf("Tamanho: ");
    scanf("%d", &tamanho);

    Pilha *p = criar(tamanho);

    for(i = 0; i < tamanho; i++){
        printf("Valor: ");
        scanf("%d", &valor);
        push(p, valor);
    }

    Pilha *p2 = criar(tamanho);

    copiar(p,p2);
    printf("\nPrimeira pilha: ");
    imprimir(p);
    printf("\nSegunda pilha: ");
    imprimir(p2);
return 0;
}
