#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char valor;
    struct No *prox;
}No;

typedef struct Pilha{
    struct No *topo;
}Pilha;

Pilha *criar(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha *p){
    return p->topo == NULL;
}

int push(Pilha *p, char valor){
    No *tempEmpilhar = malloc(sizeof(No));

    tempEmpilhar->valor = valor;
    tempEmpilhar->prox = p->topo;
    p->topo = tempEmpilhar;
    return 1;
}

int pop(Pilha *p){
    No *tempDesempilhar = p->topo;

    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return 0;
    }

    char valor = tempDesempilhar->valor;
    p->topo = tempDesempilhar->prox;

    return valor;

    free(p);
}

void imprimir(Pilha *p){
    No *tempImprimir = p->topo;
    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return;
    }

    while(tempImprimir != NULL){
        printf("%c ", tempImprimir->valor);
        tempImprimir = tempImprimir->prox;
    }
    printf("\n");

}



int main(){
    Pilha *p = criar();

    char valor, i = 0, tam = 3, vet[tam], j = 1;

    for(i = 0; i < tam; i++){
        printf("Valor: ");
        scanf(" %c", &valor);
        push(p, valor);
    }


    for(i = 1; i < tam; i++){
        j = 1;
        while(j != i){
            printf("* ");
            j++;
        }puts("");
    }

    for(i = 0; i < tam; i++){
        pop(p);
        imprimir(p);
    }




return 0;

}

