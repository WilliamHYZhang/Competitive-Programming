//Algo template for prime factorization: O(sqrt(N))
vector<int> pfs;
int tmp = N;
if(tmp%2 == 0){
	while(tmp%2 == 0)
		{pfs.pb(2); tmp /= 2;}
}
for(int i = 3; i <= sqrt(tmp); i += 2){
	if(tmp%i == 0){
		while(tmp%i == 0)
			{pfs.pb(i); tmp /= i;}
	}
}
if(tmp > 2)
	pfs.pb(tmp);