from cs50 import get_string

card = 0
lista = []
le = 0
check = False
# Vendo se o que foi fornecido e maior que 0
while not check:
    card = str(input("Number: "))
    
    # Criando uma lista
    for num in card:
        lista.append(int(num))
    le = len(lista)
    if le > 0:
        check = True
    else:
        check = False

sub = 0
lista2 = []
lista3 = []
lista4 = []
soma = 0
soma2 = 0
s: str = ""

# Pegando os numeros apartir do ultimo
for num in range(1, le+1, 2):
    sub = le - num - 1
    
    if sub < 0:
        break
    
    lista2.append(lista[sub])

# Adicionado os numeros multiplicados por dois em outra lista
for num in lista2:
    lista3.append(num * 2)

# Somando todos os digitos da lista2
for num in lista3:
    s = str(num)
    for num1 in s:
        soma += int(num1)

# Pegando os numeos que nao foram multiplicados por 2
for num in range(1, le+1, 2):
    lista4.append(lista[le - num])

lista4.append(soma)
soma2 = sum(lista4)

# Limpando algumas listas para utilizalas de novo

lista3.clear()
lista2.clear()
lista3.append(soma2)

# Separando o resultado

for num in lista3:
    s = str(num)
    for num1 in s:
        lista2.append(num1)

lista2.sort()

# Juntando os digitos para verificar

valor1 = lista[0]
valor2 = lista[1]
valor = (valor1 * 10) + valor2

# Vai verificar de qual empresa e
if lista2[0] == "0":
    if le == 15:
        if valor == 34 or valor == 37:
            print("AMEX")
        else:
            print("INVALID")
    
    elif le == 16:
        if 51 <= valor <= 55:
            print("MASTERCARD")
        elif lista[0] == 4:
            print("VISA")
        else:
            print("INVALID")
        
    elif le == 13:
        if lista[0] == 4:
            print("VISA")
        else:
            print("INVALID")
    
    else:
        print("INVALID")
else:
    print("INVALID")
