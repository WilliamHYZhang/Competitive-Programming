#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ins insert
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (size_t)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

int N, K;
vector<pair<int, list<int>>> G;
ll dp[100000][3];

ll sol(int node, int parent, int col){
	if(dp[node][col-1] >= 0)
		return dp[node][col-1];
	if(G[node].f && G[node].f != col)
		return 0;

	dp[node][col-1] = 1;
	for(auto child : G[node].s){
		if(child == parent)
			continue;
		ll tmp = 0;
		for(int i = 1; i <= 3; ++i)
			if(i != col)
				tmp = (tmp + sol(child, node, i)) % MOD;
		dp[node][col-1] = (dp[node][col-1] * tmp) % MOD;
	}

	return dp[node][col-1];
}

int main(){
	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");

	fin >> N >> K;
	G.rsz(N);
	fill_n(*dp, 300000, -1);

	for(int i = 0; i < N-1; ++i){
		int x, y;
		fin >> x >> y;
		--x; --y;
		G[x].s.pub(y);
		G[y].s.pub(x);
	}

	for(int i = 0; i < K; ++i){
		int b, c;
		fin >> b >> c;
		G[--b].f = c;
	}
	
	fout << (sol(0, -1, 1) + sol(0, -1, 2) + sol(0, -1, 3)) % MOD << endl;
}
//Keep It Simple, Stupid!