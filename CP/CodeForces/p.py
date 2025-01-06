import math
inside = input().split(" ")

m = int(inside[0])
eggs = [int(inside[1]), int(inside[2]), int(inside[3])]

def solve(m, paths):
    if m <= 0:
        return paths[0] * eggs[0] + paths[1] * eggs[1] + paths[2] * eggs[2]

    mini = math.inf 
    for enum, i in enumerate([6, 8, 12]):
        paths[enum] += 1
        mini = min(solve(m-i, paths), mini)
        paths[enum] -= 1

    return mini


x= solve(m, [0, 0, 0])
print(x)