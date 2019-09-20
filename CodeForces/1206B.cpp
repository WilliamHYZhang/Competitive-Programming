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
#define MOD 1000000007

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	int N;
	cin >> N;
	long long int a[100000];
	for(int i = 0; i < N; ++i)
		cin >> a[i];

	long long int dp[100000][2];
	dp[0][0] = abs(-1 - a[0]);
	dp[0][1] = abs(1 - a[0]);

	for(int i = 1; i < N; ++i){
		dp[i][0] = min(dp[i-1][0] + abs(1 - a[i]), dp[i-1][1] + abs(-1 - a[i]));
		dp[i][1] = min(dp[i-1][0] + abs(-1 - a[i]), dp[i-1][1] + abs(1 - a[i]));
	}

	cout << dp[N-1][1] << endl;
}
//Keep It Simple, Stupid!