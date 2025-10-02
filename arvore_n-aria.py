class Arvore(object):
    def __init__(self, valor):
        self.filho = []
        self.valor = valor


def buscar(chave, raiz):
    if chave == raiz.valor:
        status = True
        return raiz
    else:
        for filho in raiz.filho:
            no = buscar(chave, filho)
            if no:
                return no
    return None


def inserir(valor, raiz):
    no = Arvore(valor)
    raiz.filho.append(no)


def remover(valor, raiz):
    if raiz.filho:
        for filho in raiz.filho:
            if buscar(valor, filho) != None:
                for son in filho.filho:
                    raiz.filho.append(son)
            if valor == filho.valor:
                raiz.filho.remove(filho)


def percorrer(raiz):
    for filho in raiz.filho:
        print(filho.valor)
        percorrer(filho)


def main():
    raiz = int(input("Digite um valor fixo para a raiz: "))
    arvore = Arvore(raiz)

    while True:
       opcao = int(input("Opção: "))
       if opcao == 0:
           break
       elif opcao == 1:
           chave = int(input("Chave: "))
           busca = buscar(chave, arvore)
           if busca:
               valor = int(input("Número: "))
               inserir(valor, busca)
           else:
               print("Chave não encontrada.")
               continue
       elif opcao == 2:
           print(arvore.valor)
           percorrer(arvore)
       elif opcao == 3:
           chave = int(input("Chave: "))
           busca = buscar(chave, arvore)
           if busca:
               valor = int(input("Valor a remover: "))
               if valor == arvore.valor:
                   print("Não pode remover a raiz da árvore.")
               else:
                   remover(valor, busca)
           else:
               print("Chave não encontrada.")
       else:
           print("Opção inválida.")


main()
