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

int G[100000][2], col[100000];
ll cost[100000][3], dp[100000][3][3];

int addG(int a, int b){
	if(G[a][1] == -1){
		if(G[a][0] == -1)
			G[a][0] = b;
		else
			G[a][1] = b;
		return 0;
	}
	return -1;
}

int main(){
	int N;
	cin >> N;
	
	for(int i = 0; i < N; ++i)
		cin >> cost[i][0];
	for(int i = 0; i < N; ++i)
		cin >> cost[i][1];
	for(int i = 0; i < N; ++i)
		cin >> cost[i][2];

	fill_n(*G, N*2, -1);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		if(addG(u, v) || addG(v, u))
			{cout << -1 << endl; return 0;}
	}

	int cur = 0, p1, p2;
	while(G[cur][1] != -1)
		++cur;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			dp[cur][i][j] = cost[cur][i];
	p2 = -1;
	p1 = cur;
	for(int i = 0; i < N-1; ++i){
		cur = G[cur][0] != p2 ? G[cur][0] : G[cur][1];
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				if(j == k)
					continue;
				int tmp = 0;
				for(; tmp == j || tmp == k; ++tmp);
				dp[cur][j][k] = cost[cur][j] + dp[p1][k][tmp];
			}
		}
		p2 = p1;
		p1 = cur;
	}
	
	ll ans = INF;
	int ij[2];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(i == j)
				continue;
			if(dp[cur][i][j] < ans){
				ans = dp[cur][i][j];
				ij[0] = i;
				ij[1] = j;		
			}
		}
	}
	
	p2 = cur;
	col[cur] = ij[0];
	cur = G[cur][0] != -1 ? G[cur][0] : G[cur][1];
	p1 = cur;
	col[cur] = ij[1];
	for(int i = 0; i < N-2; ++i){
		cur = G[cur][0] != p2 ? G[cur][0] : G[cur][1];
		int tmp = 0;
		for(; tmp == col[p1] || tmp == col[p2]; ++tmp);
		col[cur] = tmp;
		p2 = p1;
		p1 = cur;
	}

	cout << ans << endl;
	for(int i = 0; i < N; ++i)
		cout << col[i]+1 << " ";
	cout << endl;
}
//Keep It Simple, Stupid!