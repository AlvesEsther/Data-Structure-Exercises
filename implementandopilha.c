#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do nó
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Função para criar um novo nó
No* novoNo(int dado) {
    No* no = (No*) malloc(sizeof(No));
    no->dado = dado;
    no->proximo = NULL;
    return no;
}

// Função para empilhar um elemento na pilha
void empilhar(No** topo, int dado) {
    No* no = novoNo(dado);
    no->proximo = *topo;
    *topo = no;
}

// Função para desempilhar um elemento da pilha
int desempilhar(No** topo) {
    No* temp = *topo;
    *topo = (*topo)->proximo;
    int desempilhado = temp->dado;
    free(temp);
    
    return desempilhado;
}

int main() {
    No* topo = NULL;

    int N;
    scanf("%d", &N);

    while(N--) {
        char instrucao[10];
        scanf("%s", instrucao);

        if(strcmp(instrucao, "BIPUSH") == 0) {
            int K;
            scanf("%d", &K);
            empilhar(&topo, K);
        } else if(strcmp(instrucao, "IADD") == 0) {
            int val1 = desempilhar(&topo);
            int val2 = desempilhar(&topo);
            empilhar(&topo, val1 + val2);
        } else if(strcmp(instrucao, "ISUB") == 0) {
            int val1 = desempilhar(&topo);
            int val2 = desempilhar(&topo);
            empilhar(&topo, val1 - val2);
        } else if(strcmp(instrucao, "IMUL") == 0) {
            int val1 = desempilhar(&topo);
            int val2 = desempilhar(&topo);
            empilhar(&topo, val1 * val2);
        }
    }

    printf("%d\n", desempilhar(&topo));

    return 0;
}
