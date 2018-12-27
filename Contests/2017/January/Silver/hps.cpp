#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("hps.in");
	ofstream fout("hps.out");

	size_t N;
	fin >> N;
	char moves[N];

	for(size_t i = 0; i < N; ++i)
		fin >> moves[i];

	char plays[3] = {'H', 'P', 'S'};
	size_t ans = 0;

	for(size_t i = 0; i < 3; ++i){
		for(size_t j = 0; j < 3; ++j){
			char play1 = plays[i], play2 = plays[j];
			size_t maxPlay = 0;
			for(size_t k = 0; k < N; ++k)
				if(play1 == moves[k])
					++maxPlay;
			for(size_t k = N-1; k > 1; --k){
				if(play1 == moves[k])
					--maxPlay;
				if(play2 == moves[k])
					++maxPlay;
				if(maxPlay > ans)
					ans = maxPlay;
			}
		}
	}

	fout << ans << endl;
}