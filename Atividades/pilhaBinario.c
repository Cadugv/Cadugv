#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // máximo de elementos presentes na pilha

// Estrutura da Pilha
typedef struct Pilha {
    int item;
    struct Pilha *prox;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha **topo) {
    *topo = NULL;  // Inicializa a pilha como vazia (NULL)
}

// Verifica se a pilha está vazia
int vazia(Pilha *topo) {
    return (topo == NULL);
}

// Verifica se a pilha está cheia
// Aqui estamos contando os elementos da pilha para determinar se ela está cheia
int cheia(Pilha *topo) {
    int count = 0;
    Pilha *aux = topo;

    while (aux != NULL) {
        aux = aux->prox;
        count++;
    }

    return count == MAX;
}

// Função para empurrar um elemento na pilha
void push(Pilha **topo, int valor) {
    if (cheia(*topo)) {
        printf("A pilha está cheia! Não é possível inserir elementos.\n");
    } else {
        Pilha *novo = (Pilha *)malloc(sizeof(Pilha));  // Aloca memória para o novo nó
        if (novo == NULL) {
            printf("Erro de alocação de memória!\n");
            return;
        }
        novo->item = valor;
        novo->prox = *topo;
        *topo = novo;  // Atualiza o topo para o novo nó

        printf("O elemento %d foi inserido na pilha.\n", valor);
    }
}

// Função para remover um elemento da pilha
int pop(Pilha **topo) {
    if (vazia(*topo)) {
        printf("A pilha está vazia! Não é possível remover elementos.\n");
        return -1;
    } else {
        Pilha *aux = *topo;
        int valorRetirado = aux->item;

        *topo = aux->prox;  // Atualiza o topo para o próximo elemento
        free(aux);  // Libera a memória do nó removido

        printf("Elemento %d foi removido da pilha.\n", valorRetirado);
        return valorRetirado;
    }
}

// Função para imprimir a pilha
void imprimePilha(Pilha *topo) {
    Pilha *aux = topo;

    if (vazia(topo)) {
        printf("A pilha está vazia!\n");
    }

    while (aux != NULL) {
        printf("O elemento %d está no endereço %p que aponta para %p.\n", aux->item, aux, aux->prox);
        aux = aux->prox;
    }
}

// Função que converte um número decimal para binário usando a pilha
void decimalParaBinario(int numero) {
    Pilha *topo;
    inicializarPilha(&topo);  // Inicializa a pilha como vazia

    while (numero > 0) {
        int resto = numero % 2;  // Calcula o resto (0 ou 1)
        push(&topo, resto);      // Empurra o resto para a pilha
        numero /= 2;             // Divide o número por 2
    }

    printf("Saída: ");
    while (!vazia(topo)) {
        printf("%d\n", pop(&topo));  // Remove os elementos da pilha e imprime
    }
    printf("\n");
}

// Função principal
int main() {
    int num;

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    decimalParaBinario(num);

    return 0;
}
