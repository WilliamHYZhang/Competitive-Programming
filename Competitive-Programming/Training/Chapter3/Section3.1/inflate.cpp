/*
ID: billz541
TASK: inflate
LANG: C++11
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define INF INT_MAX

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");

	int M, N;
	fin >> M >> N;
	int cats[10000][2]; //categories
	int MAX[10001] = {0};
	for(int i = 0; i < N; ++i){
		int p, m;
		fin >> p >> m;
		cats[i][0] = p;
		cats[i][1] = m;
	}

	for(int i = 0; i <= M; ++i)
		for(int j = 0; j < N; ++j)
			if(i - cats[j][1] >= 0)
				MAX[i] = max(MAX[i], MAX[i-cats[j][1]] + cats[j][0]);
	

	fout << MAX[M] << endl;
}
//Keep It Simple, Stupid!