from itertools import permutations
import math 

m = input()
stri = input()

count = 0
for i in permutations(stri):
    k = int("".join(i))
    l = int(math.sqrt(k))
    if  l * l == k:
        count += 1

print(count)