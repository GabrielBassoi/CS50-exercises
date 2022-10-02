from sys import argv, exit
from cs50 import SQL

# Conexao com SQL
db = SQL("sqlite:///students.db")

# Verifica de ha 2 argumentos na linha de comando
if len(argv) != 2:
    print("Usage: python roster.py housename")
    exit(1)

# Executa codigo em SQL
r = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])
for ro in r:
    first, middle, last, birth = ro["first"], ro["middle"], ro["last"], ro["birth"]
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")