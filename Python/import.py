from sys import argv, exit
from cs50 import SQL
import csv

db = SQL("sqlite:///students.db")

# Verifica se a 2 argumentos na linha de comandos
if len(argv) != 2:
    print("Usage: python import.py file.csv")
    exit(1)

with open(argv[1]) as arq:
    r = csv.DictReader(arq)
    for line in r:
        house = line["house"]
        birth = line["birth"]

        lista = line["name"].split()
        
        # primeiro, segundo e ultimo nome
        name1 = None
        name2 = None
        name3 = None
    
        # Verifica qual o tamanho do nome
        if len(lista) == 2:
            name1 = lista[0]
            name2 = None
            name3 = lista[1]
        else:
            name1 = lista[0]
            name2 = lista[1]
            name3 = lista[2]
        # executa em SQL
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name1, name2, name3, house, birth)