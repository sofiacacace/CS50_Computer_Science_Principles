import re
from cs50 import get_string

text = get_string("Text: ")
w = 1
s = 0
l = 0

for i in range(len(text)):
   if re.search("\s", text[i]):
       w +=1
   if re.search("[!|.|?]", text[i]):
       s +=1
   if re.search("[a-zA-Z]", text[i]):
       l +=1

S = s/w*100
L = l/w*100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index<1:
    print("Before Grade 1")
elif index>16:
    print("Grade 16+")
else:
    print("Grade ", index)
