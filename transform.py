'''
ID: billz541
LANG: PYTHON3
TASK: transform
'''
global before
global after
before = []
after = []
with open('transform.in', 'r') as fin:
    n = int(fin.readline())
    def getInput(before_after):
        for x in range(n):
            temp = []
            line = fin.readline()
            for y in range(n):
                temp.append(line[y])
            before_after.append(temp)
    getInput(before)
    getInput(after)
def ninetydeg(before):
    arr= []
    for x in range(n):
        temp = []
        for y in range(n-1,-1,-1):
            temp.append(before[y][x])
        arr.append(temp)
    return arr
def oneeightydeg(before):
    return ninetydeg(ninetydeg(before))
def twoseventydeg(before):
    return ninetydeg(ninetydeg(ninetydeg(before)))
def reflection():
    arr = []
    for x in range(n-1,-1,-1):
        arr.append(before[x])
    return arr
def combo():
    arr = []
    arr.append(ninetydeg(reflection()))
    arr.append(oneeightydeg(reflection()))
    arr.append(twoseventydeg(reflection()))
    return arr
with open('transform.out', 'w') as fout:
    if after == ninetydeg(before):
        fout.write('1'+'\n')
    elif after == oneeightydeg(before):
        fout.write('2'+'\n')
    elif after == twoseventydeg(before):
        fout.write('3'+'\n')
    elif after == reflection():
        fout.write('4'+'\n')   
    elif combo()[0] == after or combo()[1] == after or combo()[2] == after:
        fout.write('5'+'\n')
    elif before == after:
        fout.write('6'+'\n')
    else:
        fout.write('7'+'\n')
    
    
