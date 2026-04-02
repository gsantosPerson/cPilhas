#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    char *conteudo;
    int topo;
    int tam;
}Pilha;

Pilha *criar(int tam){
    Pilha *p = malloc(sizeof(Pilha));
    p->conteudo = malloc(tam * sizeof(char));
    p->topo = -1;
    p->tam = tam;

    return p;
}

int isFull(Pilha *p){
    return p->topo == p->tam - 1;
}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

int push(Pilha *p, char valor){
    if(isFull(p)){
        printf("\nPilha cheia\n");
        return 0;
    }

    p->conteudo[++p->topo] = valor;

    return 1;
}

char pop(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return '0';
    }

    char valor = p->conteudo[p->topo--];



    return valor;

}

void imprimir(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return;
    }

    for(int i = p->topo; i >= 0; i--){
        printf("%c ", p->conteudo[i]);
    }

}

void comparar(Pilha *p1, Pilha *p2){

    if(p1->topo != p2->topo){
        printf("\nPilhas com tamanhos diferentes\n");
        return;
    }

    while(!isEmpty(p1)){
        if(pop(p1) != pop(p2)){
            printf("\nPihas com valores     diferentes\n");
            return;
        }
    }

    printf("\nPilhas iguais");

    free(p1->conteudo);
    free(p1);
    free(p2->conteudo);
    free(p2);
}

int main(){
    char valor;
    int i, tam;

    printf("Tamanho: ");
    scanf("%d", &tam);

    Pilha *p1 = criar(tam);


    printf("\nPrimeira pilha\n");
    for(i = 0; i < tam; i++){
        printf("Valor: ");
        scanf(" %c", &valor);
        push(p1, valor);
    }

    printf("\nTamanho 2: ");
    scanf("%d", &tam);

    Pilha *p2 = criar(tam);

    printf("\nSegunda pilha\n");
    for(i = 0; i < tam; i++){
        printf("Valor: ");
        scanf(" %c", &valor);
        push(p2, valor);
    }

    printf("\nPrimera pilha: ");
    imprimir(p1);

    printf("\nSegunda pilha: ");
    imprimir(p2);

    comparar(p1, p2);
    return 0;
}
