import cs50
import csv

from sys import argv   #para obtener los argumentos del comando en línea

if not len(argv) == 2:
   print("Please enter the following command-line arguments: program.py file.csv")
   exit(1)

db = cs50.SQL(f"sqlite:///students.db")

#db.execute("CREATE TABLE students (id INTEGER, first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255), house VARCHAR(10), birth INTEGER)") #creo en la base de datos students.db

id = 0

with open(argv[-1], "r") as dates:

     reader = csv.DictReader(dates)

     for row in reader:

        names = row["name"].split()

        if len(names) == 2:
            first = names[0]
            middle = None
            last = names[1]

        else:
            first = names[0]
            middle = names[1]
            last = names[2]

        db.execute("INSERT INTO students (id, first, middle, last, house, birth) VALUES(?,?,?,?,?,?)", id, first, middle, last, row["house"], row["birth"])

        id = id + 1
