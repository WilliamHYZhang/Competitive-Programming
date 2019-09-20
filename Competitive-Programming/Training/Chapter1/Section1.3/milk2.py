'''
ID: billz541
LANG: PYTHON3
TASK: milk2
'''
milkTimes = []
minStart = 1000000
maxEnd = 0
for x in range(1000000):
    milkTimes.append([0,0])
with open('milk2.in', 'r') as fin: 
    n = int(fin.readline())
    for x in range(n):
        start, end = fin.readline().split()
        minStart = min(minStart, int(start))
        maxEnd = max(maxEnd, int(end)-1)
        milkTimes[int(start)][0] += 1
        milkTimes[int(end)][1] += 1
countStart = 0
countEnd = 0
yesMilk = 0
maxYesMilk = 0
noMilk = 0
maxNoMilk = 0
for x in range(minStart, maxEnd+1):
    countStart += milkTimes[x][0]
    countEnd += milkTimes[x][1]
    if countStart > countEnd:
        yesMilk += 1
        maxNoMilk = max(maxNoMilk, noMilk)
        noMilk = 0
    else:
        noMilk += 1
        maxYesMilk = max(maxYesMilk, yesMilk)
        yesMilk = 0
maxYesMilk = max(maxYesMilk, yesMilk)
maxNoMilk = max(maxNoMilk, noMilk)
with open('milk2.out', 'w') as fout:
    fout.write(str(maxYesMilk) + ' ' + str(maxNoMilk) + '\n')
