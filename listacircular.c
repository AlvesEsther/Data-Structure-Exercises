#include <stdio.h>
#include <stdlib.h>

struct Jogador {
    int numero;
    struct Jogador* proximo;
};

struct Jogador* criarJogador(int numero) {
    struct Jogador* novoAmigo = (struct Jogador*)malloc(sizeof(struct Jogador));
    novoAmigo->numero = numero;
    novoAmigo->proximo = NULL;
    return novoAmigo;
}

int procurandoVencedor(int N, int K) {
    // Criando lista circular
    struct Jogador* inicio = criarJogador(1);
    struct Jogador* atual = inicio;

    for (int i = 2; i <= N; i++) {
        atual->proximo = criarJogador(i);
        atual = atual->proximo;
    }
    atual->proximo = inicio;

    // Eliminação até que reste um
    while (N > 1) {
        for (int i = 1; i < K; i++) {
            atual = atual->proximo;
        }

        // Remove o jogador atual
        struct Jogador* eliminado = atual->proximo;
        atual->proximo = eliminado->proximo;
        free(eliminado);

        N--;
    }

    int vencedor = atual->numero;

    // Libera a memória do último amigo que resta
    free(atual);

    return vencedor;
}

int main() {
    int T; // Número de casos pra testar
    scanf("%d", &T);

    int resultados[T]; // Array para armazenar os resultados

    for (int caso = 0; caso < T; caso++) {
        int N, K;
        scanf("%d %d", &N, &K);
        resultados[caso] = procurandoVencedor(N, K);
    }

    // Imprime todos os resultados em uma única linha
    for (int caso = 0; caso < T; caso++) {
        printf("%d", resultados[caso]);
        if (caso < T - 1) {
            printf(" ");
        }
    }

    return 0;
}

