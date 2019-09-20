'''
ID: billz541
LANG: PYTHON3
TASK: gift1
'''
names = []
gifts = []
with open('gift1.in', 'r') as f:
    np = int(f.readline())
    for x in range(np):
        names.append([f.readline(), 0])
    for x in range(np):
        temp = []
        temp.append(f.readline())
        amount, ng = (f.readline().split())
        temp.append(int(amount))
        temp.append(int(ng))
        for y in range(temp[2]):
            temp.append(f.readline())
        gifts.append(temp)
for x in range(np):
    temp = []
    if gifts[x][2] != 0:
        remainder = gifts[x][1] % gifts[x][2]
        spent = gifts[x][1] - remainder
        split = int(spent / gifts[x][2])
    else:
        remainder = 0
        spent = 0
        split = 0
    for y in range(3, len(gifts[x])):
        temp.append(gifts[x][y])
    for y in range(np):
        if names[y][0] == gifts[x][0]:
            names[y][1] -= spent
        if names[y][0] in temp:
            names[y][1] += split
with open('gift1.out', 'w') as out:
    for x in range(np):
        out.write(str(names[x][0].rstrip()) + ' ')
        out.write(str(names[x][1]) + '\n')

    
