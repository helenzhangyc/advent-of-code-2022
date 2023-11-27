# It's way easier to do this in python so I did this day in python lol
import ast 
from functools import cmp_to_key

def compareNumber(l1, l2):
    if l1 < l2:
        return -1
    elif l1 == l2:
        return 0
    else:
        return 1

def isRightOrder(l1, l2):
    # both values are integers
    if isinstance(l1, int) and isinstance(l2, int):
        return compareNumber(l1, l2)
    elif isinstance(l1, int) and isinstance(l2, list):
        l1 = [l1]
    elif isinstance(l2, int) and isinstance(l1, list):
        l2 = [l2]

    for a, b in zip(l1, l2):
        result = isRightOrder(a, b)
        if result != 0:
            return result
    return compareNumber(len(l1), len(l2))
    
    

with open('input.txt') as f:
    lines = f.readlines()
    length = len(lines)
    combine = []
    for i in range(0, length, 3):
        l1 = ast.literal_eval(lines[i])
        l2 = ast.literal_eval(lines[i + 1])
        combine.append(l1)
        combine.append(l2)
    combine.append([[2]])
    combine.append([[6]])
    combine = sorted(combine, key=cmp_to_key(isRightOrder))
    print((combine.index([[2]]) + 1) * (combine.index([[6]]) + 1))


    f.close()