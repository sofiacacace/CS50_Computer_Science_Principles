from cs50 import get_int

def main():
    h = get_height()
    print_pyramid(h)

def get_height():
    while True:
       n = get_int("Height: ")
       print("The height should be a positive integer between 1 and 8")
       if n>0 and n<9 and n%1 == 0:
           break
    return n

def print_pyramid(h):
    for i in range(h):
        l = i + 1
        s = h - i - 1
        print(" "*s + "#"*l, end="  ")
        print("#"*l, end="")
        print()

main()
