#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da pilha para armazenar os caracteres
typedef struct Pilha {
    char item;
    struct Pilha *prox;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha **topo) {
    *topo = NULL;  // Inicializa a pilha como vazia
}

// Função para verificar se a pilha está vazia
int vazia(Pilha *topo) {
    return topo == NULL;
}

// Função para empurrar (push) um caractere na pilha
void push(Pilha **topo, char valor) {
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));  // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novo->item = valor;   // Armazena o caractere
    novo->prox = *topo;   // O novo nó aponta para o nó anterior (topo atual)
    *topo = novo;         // O topo agora é o novo nó
}

// Função para remover (pop) um caractere da pilha
char pop(Pilha **topo) {
    if (vazia(*topo)) {
        printf("A pilha está vazia!\n");
        return '\0';  // Retorna um caractere nulo se a pilha estiver vazia
    } else {
        Pilha *aux = *topo;         // Nó temporário para liberar a memória depois
        char valorRetirado = aux->item;
        *topo = aux->prox;          // O topo agora é o próximo nó
        free(aux);                  // Libera a memória do nó removido
        return valorRetirado;       // Retorna o caractere removido
    }
}

// Função que inverte uma string utilizando a pilha
void inverterString(char str[]) {
    Pilha *topo;
    inicializarPilha(&topo);  // Inicializa a pilha

    // Passo 1: Empurrar todos os caracteres da string na pilha
    for (int i = 0; i < strlen(str); i++) {
        push(&topo, str[i]);
    }

    // Passo 2: Retirar os caracteres da pilha (pop) e reconstruir a string invertida
    int i = 0;
    while (!vazia(topo)) {
        str[i++] = pop(&topo);
    }
}

// Função principal
int main() {
    char str[100];  // Buffer para armazenar a string fornecida pelo usuário

    printf("Digite uma string: ");
    scanf("%s", str);  // Lê a string do usuário

    inverterString(str);  // Chama a função para inverter a string

    printf("String invertida: %s\n", str);  // Exibe a string invertida

    return 0;
}
