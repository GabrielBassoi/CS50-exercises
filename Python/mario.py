from cs50 import get_int

# Verifica se esta entre ou igual a 1 e 8 se nao pede de volta
height = 0
while not 1 <= height <= 8:
    height = get_int("Height: ")

for num1 in range(1, height+1):
    # print("-" * (height - 1 - num1), "#" * num1, " " * 2, "#" * num1)
    print(" " * (height - num1), end="")
    print("#" * num1, end="")
    print("  ", end="")
    print("#" * num1, end="")
    print(end="\n")