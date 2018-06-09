'''
ID: billz541
LANG: PYTHON3
TASK: beads
'''
import sys
with open('beads.in', 'r') as fin:
    n = int(fin.readline().strip())
    beads = fin.readline().strip()
totalAns = []
ans1 = -1
ans2 = -1
for x in range(n):
    temp = beads[-x:] + beads[:-x]
    for y in range(n):
        if temp[y] != 'w':
            check = temp[y]
            break
    for y in range(n):
        if temp[y] == 'w' or temp[y] == check:
            continue
        else:
            ans1 = y
            break
    for y in range(n-1,-1,-1):
        if temp[y] != 'w':
            check = temp[y]
            break
    count = 0
    for y in range(n-1,-1,-1):
        count += 1
        if temp[y] == 'w' or temp[y] == check:
            if y == ans1:
                ans2 = count
                break
            else:
                continue
        else:
            ans2 = count - 1
            break
    if ans1 != -1 and ans2 != -1:
        totalAns.append(ans1+ans2)
maxAns = 0 
for x in range(len(totalAns)):
    if totalAns[x] > maxAns:
        maxAns = totalAns[x]
if ans1 != -1 and ans2 != -1:
    with open('beads.out','w') as fout:
        fout.write(str(maxAns)+'\n')
else:
    with open('beads.out','w') as fout:
        fout.write(str(n)+'\n')
    
