class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""

    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior


class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""

    inicio = None

    def mostrarOrdemReversaTarsis(self):
        ultimo = self.inicio

    while ultimo.prox != None:
        ultimo = ultimo.prox

    while ultimo != self.inicio:
        print(ultimo.valor)
        ultimo = ultimo.ant

    # se é o primeiro elemento
    if ultimo.ant is None:
        print(ultimo.valor)


def mostrarOrdemReversa2(self):
    ultimo = self.inicio

    while ultimo.prox != None:
        ultimo = ultimo.prox

    while ultimo != None:
        print(ultimo.valor)
        ultimo = ultimo.ant


def inserirOrdenado(self, novo: No):
    atual = self.inicio

    if self.inicio is None:
        self.inicio = novo

    else:
        # verifico primeiro se atual prox não é none, e só então checo seu valor
        while (atual.prox and atual.prox.valor < novo.valor):
            atual = atual.prox

        novo.prox = atual.prox
        novo.ant = atual
        if atual.prox is not None:
            atual.prox.ant = novo
        atual.prox = novo


def inserirInicio(self, novo: No):
    if self.inicio == None:
        self.inicio = novo
    else:
        novo.prox = self.inicio
        self.inicio.ant = novo
        self.inicio = novo


def inserirFim(self, novo: No):
    if self.inicio == None:
        self.inicio = novo
    else:
        ultimo = self.inicio
        while ultimo.prox != None:
            ultimo = ultimo.prox

        ultimo.prox = novo
        novo.ant = ultimo


def buscar(self, valor) -> No:
    alvo = self.inicio
    while alvo != None and alvo.valor != valor:
        alvo = alvo.prox
    return alvo


def removerAlvo(self, alvo: No):
    anterior = alvo.ant
    proximo = alvo.prox

    if anterior != None:
        anterior.prox = alvo.prox

    if proximo != None:
        proximo.ant = alvo.ant

    if alvo == self.inicio:
        self.inicio = alvo.prox


def removerInicio(self) -> No:
    alvo = self.inicio

    # se lista nao ta vazia
    if self.inicio:
        self.inicio = self.inicio.prox
        # se lista está vazia apos remoção -- tinha apenas 1 elemento
        if self.inicio:
            self.inicio.ant = None

    alvo.prox = None
    alvo.ant = None
    return alvo


def mostrar(self):
    atual = self.inicio
    while atual != None:
        print(atual.valor, end=' ')
        atual = atual.prox


# inicializa uma lista vazia
lista_1 = Lista()

# Adiciona alguns nós
novo = No(10)
lista_1.inserirInicio(novo)

novo = No(13)
lista_1.inserirInicio(novo)

novo = No(20)
lista_1.inserirFim(novo)

lista_1.mostrar()

# removendo e mostrando estado da lista

alvo = lista_1.buscar(20)
if alvo:
    lista_1.removerAlvo(alvo)
lista_1.mostrar()

removido = lista_1.removerInicio()
if removido:
    print('Valor removido foi: ', removido.valor)

print('Lista: ', end='')
lista_1.mostrar()