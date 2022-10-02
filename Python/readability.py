texto = input("Text: ")

# vai calcular quantas palavras tem

palavras = texto.split()
palavrasq = len(palavras)

letras = []
frases = 0

# Vai calcular a quantidade de frases e de letras

for letra in texto:
    frases += letra.count(".")
    frases += letra.count("!")
    frases += letra.count("?")
    
    if "a" <= letra <= "z" or "A" <= letra <= "Z":
        letras.append(letra)

letrasq = len(letras)

# Qualcular

L = letrasq / palavrasq * 100
S = frases / palavrasq * 100

index = 0.0588 * L - 0.296 * S - 15.8
rou = round(index)

# Verifica para qual ano e

if rou < 1:
    print("Before Grade 1")

elif 1 <= rou <= 15:
    print(f"Grade {rou}")
    
else:
    print("Grade 16+")
