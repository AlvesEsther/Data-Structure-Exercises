#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
struct elemento {
    int valor;
    struct elemento* prox;
};

typedef struct elemento No;
typedef struct elemento* Pno;

// Função para inserir um valor no início da lista
void inserirNoInicio(Pno* cabeca, int valor) {
    Pno novoNo = (Pno)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
}

// Função para inserir um valor no final da lista
void inserirNoFinal(Pno* cabeca, int valor) {
    Pno novoNo = (Pno)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        Pno atual = *cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

// Função para imprimir a lista
void imprimirLista(Pno cabeca) {
    while (cabeca != NULL) {
        printf("%d", cabeca->valor);
        if (cabeca->prox != NULL) {
            printf(" ");
        }
        cabeca = cabeca->prox;
    }
    printf("\n");
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        
        Pno cabeca = NULL; // Cria a lista vazia
        
        for (int i = 0; i < N; i++) {
            char op;
            int valor;
            scanf(" %c %d", &op, &valor);
            
            if (op == 'P') {
                inserirNoInicio(&cabeca, valor);
            } else {
                inserirNoFinal(&cabeca, valor);
            }
        }
        
        imprimirLista(cabeca);
        
        // Libera a memória da lista
        Pno atual = cabeca;
        while (atual != NULL) {
            Pno temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    
    return 0;
}