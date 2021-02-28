import re
from cs50 import get_int

def main():
    num_card = get_int("Number: ")
    n = str(num_card)
    check(n)

def check(n):
    if not len(n) == 15:
        print("INVALID\n")
    else:
        #sum = 0
        #for i in range(15):
        #    if i == 0 or i%2 == 0:
        #       sum += int(n[i]*2)
        #    else:
        #       sum += int(n[i])

        #result = str(sum * 9)
        #ultima_cifra = result[len(result)-1]

        #if ultima_cifra == n[14]:
        #   check_card(n)
        #else:
        #   print("INVALID")
        check_card(n)

def check_card(n):
    if re.search("^3", n):
       print("AMEX\n", end="")

    elif re.search("^5", n):
       print("MASTERCARD\n", end="")

    elif re.search("^4", n):
       print("VISA\n", end="")
    else:
       print("INVALID")

main()
