/*
ID: billz541
TASK: stamps
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
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	int K, N; fin >> K >> N;
	int vals[50];
	for(int i = 0; i < N; ++i)
		fin >> vals[i];

	int dp[2000001], M = 1;
	dp[0] = 0;

	for(; dp[M-1] <= K; ++M){
		dp[M] = INF;
		for(int i = 0; i < N; ++i)
			if(M - vals[i] >= 0)
				dp[M] = min(dp[M], dp[M-vals[i]] + 1);
	}

	fout << M-2 << endl;
}
//Keep It Simple, Stupid!