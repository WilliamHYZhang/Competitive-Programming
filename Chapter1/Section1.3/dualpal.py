'''
ID: billz541
LANG: PYTHON3
TASK: dualpal
'''
with open('dualpal.in', 'r') as fin:
    nums = (fin.readline()).split()
    n = int(nums[0])
    s = int(nums[1])
def convertBase(base, numInBase10):
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
        ans = ans + addToAns
        numInBase10 = numInBase10%currentPos
        currentPos = currentPos/base
    return ans
def isPal(s):
    return s == s[::-1]
with open('dualpal.out', 'w') as fout:
    totalPalCount = 0
    x = 0
    while totalPalCount < n:
        palCount = 0
        x += 1
        for y in range(2, 11):
            testNum = str(convertBase(y, s+x))
            if isPal(testNum):
                palCount += 1
        if palCount >= 2:
            fout.write(str(s+x)+'\n')
            totalPalCount += 1
