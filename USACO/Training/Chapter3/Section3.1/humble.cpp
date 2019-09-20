/*
ID: billz541
TASK: humble
LANG: C++11
*/
//Let's get it boiiiiissss super elegant, love it!
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
	ifstream fin("humble.in");
	ofstream fout("humble.out");

	int K, N;
	fin >> K >> N;
	int s[100], humble[100001] = {1};
	for(int i = 0, p; i < K; ++i)
		{fin >> p; s[i] = p;}

	for(int i = 1; i <= N; ++i){
		humble[i] = INF;
		for(int j = 0; j < K; ++j){
			int n = (humble[i-1]+1)%s[j] == 0 ? (humble[i-1]+1)/s[j] : (humble[i-1]+1)/s[j] + 1;
			humble[i] = min(humble[i], *lb(humble, humble+i, n)*s[j]);
		}
	}

	fout << humble[N] << endl;
}
//Keep It Simple, Stupid!