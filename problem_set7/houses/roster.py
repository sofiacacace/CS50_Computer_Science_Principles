import cs50
import csv

from sys import argv   #para obtener los argumentos del comando en línea

if not len(argv) == 2:
   print("Please enter the following command-line arguments: roster.py [HOUSE´S NAME]")
   exit(1)

db = cs50.SQL(f"sqlite:///students.db")

cur_house = argv[1]

row_to_print = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", cur_house)

for row in row_to_print:
    if row["middle"] == None:
       print(row["first"], row["last"],',', row["birth"])
    else:
       print(row["first"], row["middle"], row["last"],',', row["birth"])

