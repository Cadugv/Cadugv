#include <stdio.h>
#include <stdlib.h>


#define MAX 10 // máximo de elementos presentes na pilha


typedef struct Pilha
{
    char item;
    struct Pilha *prox;


}Pilha;


void inicializarPilha(Pilha *topo)
{
    (*topo).prox = NULL;
}


int vazia(Pilha *topo)
{
    return ((*topo).prox == NULL);
}


int cheia(Pilha *topo)
{
    int count =0;


    Pilha *aux = NULL;
    aux = (*topo).prox;


    while(aux != NULL)
    {
        aux = (*aux).prox;
        count++;
    }
   
    return count == MAX;
}


void push(Pilha *topo, Pilha *novo, char valor)
{
    if(cheia(topo))
    {
        printf("A pilha está cheia! Não é possível inserir elementos.\n");
    }else
    {
        (*novo).item = valor;
        (*novo).prox = (*topo).prox;
        (*topo).prox = novo;


        printf("O elemento %c foi inserido na pilha.\n", valor);
    }
}


int pop(Pilha *topo)
{
    if(vazia(topo)){
        printf("A pilha está vazia! Não é possível remover elementos.\n");
        return -1;
    }
    else{
        Pilha *aux = NULL;
        aux = (*topo).prox;


        int valorRetirado = (*aux).item;
        printf("Elemento %c foi removido da pilha.\n", valorRetirado);


        (*topo).prox = (*aux).prox;


        return valorRetirado;
    }


}


void imprimePilha(Pilha *topo)
{
    Pilha *aux = NULL;
    aux = (*topo).prox;


    if(vazia(topo)){
        printf("A pilha está vazia!\n");
    }        


    while(aux != NULL)
    {
        printf("O elemento %c está no endereço %p que aponta para %p.\n",(*aux).item, aux, (*aux).prox);
        aux = (*aux).prox;
    }


}


int main()
{
    Pilha topo;
    char valor[MAX];


    printf("Digite uma sequencia de parênteses: ");
    scanf("%s", valor);




    inicializarPilha(&topo);


    imprimePilha(&topo);


    for(int i=0; valor[i]!='\0';i++){
        if(valor[i]=='('){
            Pilha *novo = (Pilha*)malloc(sizeof(topo));
            push(&topo, novo, valor[i]);
        }
        else if(valor[i]==')'){
            if(vazia(&topo)){
                printf("não balanceada\n");
                return 0;
            }else{
                pop(&topo);
            }
        }
    }


    if(vazia(&topo)){
        printf("balanceada\n");
    }else{
        printf("não balanceada\n");
    }
    return 0;
}


