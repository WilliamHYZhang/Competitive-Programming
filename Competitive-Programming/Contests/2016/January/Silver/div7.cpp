#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("div7.in");
	ofstream fout("div7.out");

	size_t N;
	fin >> N;

	size_t cows[N];
	for(size_t i = 0; i < N; ++i)
		fin >> cows[i];

	int small[7] = {0, -1, -1, -1, -1, -1, -1};
	int big[7] = {0, -1, -1, -1, -1, -1, -1};

	for(size_t i = 0, currentSum = 0; i < N; ++i){
		currentSum += cows[i];
		size_t mod = currentSum%7;
		if(small[mod] == -1 && mod != 0)
			small[mod] = i+1;
		big[mod] = i+1;
	}

	size_t ans = 0;
	for(size_t i = 0; i < 7; ++i){
		size_t currentAns = 0;
		if(big[i] != -1 && small[i] != -1 && big[i] >= small[i])
			currentAns = big[i] - small[i];
		if(ans < currentAns)
			ans = currentAns;
	}

	fout << ans << endl;
}