#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

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

vector<list<int>> g;
vector<bool> v;

int dfs(int &i){
	if(v[i])
		return 0;
	v[i] = true;
	int ret = 1;
	for(auto &j : g[i])
		ret += dfs(j);
	return ret;
}
int main(){
	int N, K;
	cin >> N >> K;
	g.rsz(N+1);
	v.rsz(N+1);
	for(int i = 0; i < K; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	int ans = K;
	for(int i = 1; i <= N; ++i){
		if(!v[i] && sz(g[i])){
			ans -= dfs(i)-1;
		}
	}

	cout << ans << endl;
}
//Keep It Simple, Stupid!