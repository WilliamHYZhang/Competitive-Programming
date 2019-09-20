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
	ifstream fin("teamwork.in");
	ofstream fout("teamwork.out");

	int N, K;
	fin >> N >> K;
	int cow[10000];
	for(int i = 0; i < N; ++i)
		fin >> cow[i];

	int dp[10000] = {cow[0]};
	for(int i = 1; i < N; ++i){
		for(int j = i, mJ = cow[i], a = 1; j >= max(0, i-K+1); --j, ++a){
			mJ = max(mJ, cow[j]);
			dp[i] = max(dp[i], (j-1 < 0 ? 0 : dp[j-1]) + mJ * a);
		}
	}

	fout << dp[N-1] << endl;
}
//Keep It Simple, Stupid!