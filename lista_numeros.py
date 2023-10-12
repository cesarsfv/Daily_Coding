# Dada uma lista de números e um número k, retorne se quaisquer dois números da lista somam k. 
 #   Por exemplo, dados [10, 15, 3, 7] e k de 17, retorne True, pois 10 + 7 é 17. 


def encontra_soma(lista, k):
    # Cria um conjunto para armazenar os números vistos até agora.
    numeros_vistos = set()

    for numero in lista:
        # Calcula o valor complementar necessário para somar a k.
        complementar = k - numero

        # Se o complementar já foi visto, retorna True, pois encontramos um par.
        if complementar in numeros_vistos:
            return True

        # Adiciona o número atual ao conjunto de números vistos.
        numeros_vistos.add(numero)

    # Se nenhum par de números soma a k, retorna False.
    return False

# Exemplo de uso:
lista = [10, 15, 3, 7]
k = 17
resultado = encontra_soma(lista, k)
print(resultado)  # Isso mostra True, pois 10 + 7 é igual a 17.
