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

void imprimir(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return;
    }

    for(int i = p->topo; i >= 0; i--){
        printf("%d ", p->conteudo[i]);
    }
}

void pihaA(){
    int valores[] = {1,2,4,5,10}, i;
    Pilha *p = criar(5);

    printf("Sequência A\n");

    for(i = 0; i < 5; i++){
        printf("Valor: ");
        scanf("%d", &valores[i]);
        empilhar(p, valores[i]);
    }

    while(!isEmpty(p)){
        printf("%d ", desempilhar(p));
    }

    free(p);
    free(p->valor);

    }


void pilhaA(){

}
int main(){
    setlocale(LC_ALL, "pt-br");
    pilhaA();


return 0;
}
