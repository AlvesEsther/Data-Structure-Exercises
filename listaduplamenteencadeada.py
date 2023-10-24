class No:
    def __init__(self, dado):
        self.dado = dado  # O dado que o nó armazena
        self.proximo = None  # Referência para o próximo nó
        self.anterior = None  # Referência para o nó anterior

class ListaDuplamenteEncadeada:
    def __init__(self):
        self.inicio = None  # Inicialmente, a lista está vazia, então o início e o fim são None
        self.fim = None

    def adicionar_no(self, dado):
        novo_no = No(dado)
        if self.inicio is None:
            self.inicio = novo_no  # Se a lista está vazia, o novo nó se torna o início e o fim
            self.fim = novo_no
        else:
            novo_no.anterior = self.fim  # O novo nó aponta para o nó anterior como o antigo nó final
            self.fim.proximo = novo_no  # O nó antigo final aponta para o novo nó
            self.fim = novo_no  # O novo nó agora se torna o novo nó final

    def imprimir_lista(self):
        no_atual = self.inicio
        while no_atual is not None:
            print(no_atual.dado, end=' ')  # Imprime o dado do nó atual
            no_atual = no_atual.proximo  # Move para o próximo nó

def soma_cruzada(lista1, lista2):
    lista_resultante = ListaDuplamenteEncadeada()
    no_atual1 = lista1.inicio
    no_atual2 = lista2.fim
    while no_atual1 is not None and no_atual2 is not None:
        lista_resultante.adicionar_no(no_atual1.dado + no_atual2.dado)  # Adiciona a soma na lista resultante
        no_atual1 = no_atual1.proximo  # Move para o próximo nó da primeira lista
        no_atual2 = no_atual2.anterior  # Move para o nó anterior da segunda lista
    lista_resultante.imprimir_lista()  # Imprime a lista resultante

# Exemplo de uso:
lista1 = ListaDuplamenteEncadeada()
lista2 = ListaDuplamenteEncadeada()
n = int(input("Digite o tamanho das sequências: "))
print("Digite os valores da primeira sequência :")
valores = input().split()
for i in range(n):
    lista1.adicionar_no(int(valores[i]))
print("Digite os valores da segunda sequência :")
valores = input().split()
for i in range(n):
    lista2.adicionar_no(int(valores[i]))
soma_cruzada(lista1, lista2)  # Realiza a soma cruzada e imprime o resultado
