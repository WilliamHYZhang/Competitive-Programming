"""
ID: billz541
LANG: PYTHON3
TASK: ride
"""
inputnum = []
fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
with fin:
    for count, line in enumerate(fin):
        inputnum.append(line)
ar1 = str(inputnum[0])
ar2 = str(inputnum[1])
def convert(ar):
    output = []
    for character in ar:
        num = ord(character) - 64
        output.append(num)
    return output
def solve(ar):
    total = ar[0]
    for x in range(1,len(ar)):
        total = total * ar[x]
    return total%47
ar1 = solve(convert(ar1))
ar2 = solve(convert(ar2))
if ar1 == ar2:
    fout.write("GO" + "\n")
else:
    fout.write("STAY" + "\n")
fout.close()
