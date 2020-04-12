T = int(input())
for test_case in range(1, T+1):
	N = int(input())
	a = []
	b = []
	maxA = ''
	maxB = ''
	for i in range(N):
		ai, bi = input().split('*')
		if(len(ai) > len(maxA)):
			maxA = ai
		if(len(bi) > len(maxB)):
			maxB = bi
		a.append(ai)
		b.append(bi)

	works = True;
	for i in range(100):
		curA = ''
		curB = ''
		for p in a:
			if curA == '' and len(p) > i:
				curA = p[i]
			elif len(p) > i and p[i] != curA:
				works = False
				break
		for p in b:
			if curB == '' and len(p) > i:
				curB = p[-i-1]
			elif len(p) > i and p[-i-1] != curB:
				works = False
				break

	ans = maxA + maxB if works else '*'
	print('Case #'+str(test_case)+':', ans)