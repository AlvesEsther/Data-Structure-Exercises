#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGOES 26

struct Pilha {
    char elementos[MAX_VAGOES];
    int topo;
};

void inicializarPilha(struct Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(struct Pilha *p) {
    return (p->topo == -1);
}

int pilhaCheia(struct Pilha *p) {
    return (p->topo == MAX_VAGOES - 1);
}

void push(struct Pilha *p, char elemento) {
    if (!pilhaCheia(p)) {
        p->elementos[++(p->topo)] = elemento;
    }
}

char pop(struct Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->elementos[(p->topo)--];
    }
    return '\0';  // Retorna caractere nulo se a pilha estiver vazia
}

int main() {
    struct Pilha lado_esquerdo, lado_direito;
    inicializarPilha(&lado_esquerdo);
    inicializarPilha(&lado_direito);

    int num_vagoes;
    scanf("%d", &num_vagoes);

    char sequencia_vagoes[MAX_VAGOES];
    scanf("%s", sequencia_vagoes);

    char operacoes[MAX_VAGOES];
    scanf("%s", operacoes);

    int i;
    for (i = 0; i < num_vagoes; i++) {
        push(&lado_esquerdo, sequencia_vagoes[i]);
    }

    for (i = 0; operacoes[i] != '\0'; i++) {
        if (operacoes[i] == 'E') {
            char vagao;
            scanf(" %c", &vagao);  // Espaço antes de %c para consumir a quebra de linha anterior
            push(&lado_esquerdo, vagao);
        } else if (operacoes[i] == 'D') {
            char vagao = pop(&lado_esquerdo);
            if (vagao != '\0') {
                push(&lado_direito, vagao);
            } else {
                printf("Erro\n");
                break;
            }
        }
    }

    if (operacoes[i] == '\0') {
        while (!pilhaVazia(&lado_direito)) {
            printf("%c ", pop(&lado_direito));
        }
        printf("\n");
    }

    return 0;
}
