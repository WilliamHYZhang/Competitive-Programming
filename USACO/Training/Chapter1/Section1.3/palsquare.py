'''
ID: billz541
LANG: PYTHON3
TASK: palsquare
'''
with open('palsquare.in', 'r') as fin:
    base = int(fin.readline())
def convertBase(base, numInBase10):
    numToLetter = {10 : 'A', 11 : 'B', 12 : 'C', 13 : 'D', 14 : 'E',
                   15 : 'F', 16 : 'G', 17 : 'H', 18 : 'I', 19 : 'J'}
    if base == 10:
        return numInBase10
    highestPos = 1
    while highestPos <= numInBase10:
        highestPos = highestPos * base
    highestPos = highestPos / base
    ans = ''
    currentPos = highestPos
    while currentPos >= 1:
        addToAns = str(int(numInBase10 / currentPos))
        if int(addToAns) > 9:
            addToAns = numToLetter[int(addToAns)]
        ans = ans + addToAns
        numInBase10 = numInBase10%currentPos
        currentPos = currentPos/base
    return ans
with open('palsquare.out', 'w') as fout:
    for x in range(1, 301):
        num = str(convertBase(base, x**2))
        if num == num[::-1]:
            ans = str(convertBase(base, x)) + ' ' + num + '\n'
            fout.write(ans)
        
