#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int INF = INT_MAX;
const int MOD = 1000000007;

int main(){
	int N;
	cin >> N;
	int g[1000][1000];

	for(int i = 0, n = 0; i < N/2; ++i){
		for(int j = 0; j < N/2; ++j, ++n)
			g[i][j] = n*4;
		for(int j = N/2; j < N; ++j)
			g[i][j] = g[i][j-(N/2)] + 1;
	}
	for(int i = N/2; i < N; ++i){
		for(int j = 0; j < N/2; ++j)
			g[i][j] = g[i-(N/2)][j] + 2;
		for(int j = N/2; j < N; ++j)
			g[i][j] = g[i-(N/2)][j-(N/2)] + 3;
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << g[i][j] << " ";
		cout << endl;
	}
}
//Keep It Simple, Stupid!