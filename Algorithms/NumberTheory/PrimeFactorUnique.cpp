//Algo template for prime factorization (unique): O(sqrt(N))
vector<int> pfs;
int tmp = N;
if(tmp%2 == 0){
	pfs.pb(2);
	while(tmp%2 == 0)
		tmp /= 2;
}
for(int i = 3; i <= sqrt(tmp); i += 2){
	if(tmp%i == 0){
		pfs.pb(i);
		while(tmp%i == 0)
			tmp /= i;
	}
}
if(tmp > 2)
	pfs.pb(tmp);