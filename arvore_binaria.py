class Arvore(object):
    def __init__(self, valor):
        self.esquerda = None
        self.direita = None
        self.valor = valor
        

def buscar(chave, pai, raiz, status):
    if raiz == None:
        status = False
        return None
    elif chave == raiz.valor:
        status = True
        return raiz, pai
    elif chave < raiz.valor:
        if raiz.esquerda != None:
            pai = raiz
            return buscar(chave, pai, raiz.esquerda, status)
        else:
            status = False
            return raiz
    else:
        if raiz.direita != None:
            pai = raiz
            return buscar(chave, pai, raiz.direita, status)
        else:
            status = False
            return raiz


def inserir(chave, raiz):
    if chave < raiz.valor:
        raiz.esquerda = Arvore(chave)
    else:
        raiz.direita = Arvore(chave)

   
def remover(chave, pai, raiz):
    if raiz != None and pai == None:
        raiz == None
    else:
        if raiz.esquerda == None and raiz.direita == None:
            if chave < pai.valor:
                pai.esquerda = None
            else:
                pai.direita = None
        elif raiz.esquerda != None and raiz.direita == None:
            pai.esquerda = raiz.esquerda
        elif raiz.esquerda == None and raiz.direita != None:
            pai.direita = raiz.direita  
        elif raiz.esquerda != None and raiz.direita != None:
            if chave < pai.valor:
                no = raiz.esquerda
                pai.esquerda = raiz.direita
                pai.esquerda.esquerda = no
            else:
                no = raiz.direita
                pai.direita = raiz.esquerda
                pai.direita.direita = no
            
        
def percorrer(raiz):
    if raiz:
        percorrer(raiz.esquerda)
        print(raiz.valor)
        percorrer(raiz.direita)
            

def main():
    raiz = int(input("Digite um numero fixo para a raiz: "))
    arvore = Arvore(raiz)
    pai = None
    status = False
    
    while True:
        opcao = int(input("Digite uma opção: "))
        if opcao == 1:
            chave = int(input("Digite o número a inserir: "))
            busca = buscar(chave, pai, arvore, status)
            inserir(chave, busca)
        elif opcao == 2:
            percorrer(arvore)
        elif opcao == 3:
            chave = int(input("Digite o número a remover: "))
            if chave == arvore.valor:
                print("Não é permitido remover a raiz.")
            else:
                try:
                    busca_no, busca_pai = buscar(chave, pai, arvore, status)
                    remover(chave, busca_pai, busca_no)
                except:
                    print("Chave não encontrada.")
                finally:
                    continue
        else:
            print("Opção inválida.")
            
            
main()
