'''
ID: billz541
LANG: PYTHON3
TASK: namenum
'''
keypadMap = {'2': ['A', 'B', 'C'], '3': ['D', 'E', 'F'],
             '4': ['G', 'H', 'I'], '5': ['J', 'K', 'L'],
             '6': ['M', 'N', 'O'], '7': ['P', 'R', 'S'],
             '8': ['T', 'U', 'V'], '9': ['W', 'X', 'Y']}
with open('namenum.in', 'r') as fin:
    num = fin.readline()
    num = num.strip()
with open('dict.txt', 'r') as fin1:
    realNames = fin1.readlines()
possibleNames = []
validNames = []
for digit in num:
    possibleNames.append(keypadMap[digit])
for name in realNames:
    name = name.strip()
    if len(name) != len(possibleNames):
        continue
    indexCount = 0
    validName = True
    for char in name:
        if char not in possibleNames[indexCount]:
            validName = False
            break
        indexCount += 1
    if validName:
        validNames.append(name)
with open('namenum.out', 'w') as fout:
    if len(validNames) != 0:
        for name in validNames:
            fout.write(name + '\n')
    else:
        fout.write('NONE\n')
