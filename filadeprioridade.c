#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    struct No* proximo;
};


struct FilaPrioridade {
    struct No* frente;
    struct No* fim;
};


struct FilaPrioridade* criarFila() {
    struct FilaPrioridade* novaFila = (struct FilaPrioridade*)malloc(sizeof(struct FilaPrioridade));
    novaFila->frente = novaFila->fim = NULL;
    return novaFila;
}


void enfileirar(struct FilaPrioridade* fila, int elemento) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = elemento;
    novoNo->proximo = NULL;

    
    if (fila->fim == NULL) {
        fila->frente = fila->fim = novoNo;
        return;
    }

    
    fila->fim->proximo = novoNo;
    fila->fim = novoNo;
}


int desenfileirar(struct FilaPrioridade* fila) {
    if (fila->frente == NULL) {
        return -1; 
    }

    struct No* atual = fila->frente;
    struct No* anterior = NULL;
    struct No* noMax = atual;
    int valorMax = atual->valor;

    
    while (atual->proximo != NULL) {
        if (atual->proximo->valor > valorMax) {
            valorMax = atual->proximo->valor;
            noMax = atual->proximo;
            anterior = atual;
        }
        atual = atual->proximo;
    }

    
    if (noMax == fila->frente) {
        fila->frente = fila->frente->proximo;
    } else {
        anterior->proximo = noMax->proximo;
    }

    
    if (noMax == fila->fim) {
        fila->fim = anterior;
    }

    int valorRemovido = noMax->valor;
    free(noMax);
    return valorRemovido;
}


void imprimirFila(struct FilaPrioridade* fila) {
    struct No* atual = fila->frente;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    struct FilaPrioridade* fila = criarFila();

    char operacao;
    int elemento;

    while (1) {
        scanf(" %c", &operacao);
        if (operacao == '-') {
            break;
        }

        if (operacao == 'E') {
            scanf("%d", &elemento);
            enfileirar(fila, elemento);
        } else if (operacao == 'D') {
            int removido = desenfileirar(fila);
            if (removido != -1) {
                printf("%d\n", removido);
            }
        }
        imprimirFila(fila);
    }

    return 0;
}
