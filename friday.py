'''
ID: billz541
LANG: PYTHON3
TASK: friday
'''
with open('friday.in') as fin:
    n = int(fin.readline())
days = [0,0,0,0,0,0,0]
start = 2
for x in range(n):
    months = [31,28,31,30,31,30,31,31,30,31,30,31]
    year = 1900 + x
    if year%4 == 0 and year%100 != 0 or year%400 == 0:
        months[1] = 29
    for a in range(12):
        for b in range(1, months[a]+1):
            if b == 13:
                days[start] += 1
            if start != 6:
                start += 1
            else:
                start = 0
with open('friday.out','w') as fout:
    for x in range(6):
        fout.write(str(days[x]) + ' ')
    fout.write(str(days[6]) + '\n')
            
                
            
    
