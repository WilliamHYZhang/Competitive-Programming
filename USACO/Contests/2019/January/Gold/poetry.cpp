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

ll mpow(ll x, ll y){
	ll ret = 1;
	x = x % MOD;
	while(y > 0){
		if(y & 1)
			ret = (ret*x) % MOD;
		y >>= 1;
		x = (x*x) % MOD;
	}
	return ret;
}

ll syl[5001];
unordered_map<int, vector<int>> sr;
ll memo[5001] = {1};
ll poss[5001];
int lets[26];

int main(){
	//USACO
	ifstream fin("poetry.in");
	fin.sync_with_stdio(false);
	fin.tie(NULL);
	ofstream fout("poetry.out");

	int N, M, K;
	fin >> N >> M >> K;
	for(int i = 0; i < N; ++i){
		int S, C;
		fin >> S >> C;
		syl[i] = S;
		sr[S].pub(C);
	}

	for(int i = 0; i < M; ++i){
		char E;
		fin >> E;
		++lets[E-'A'];
	}

	for(int i = 1; i <= K; ++i){
		for(int j = 0; j < N; ++j){
			if(i - syl[j] >= 0){
				if(i == K){
					poss[sr[syl[j]].back()] += memo[i - syl[j]];
					poss[sr[syl[j]].back()] %= MOD;
					sr[syl[j]].pob();
				}
				else{
					memo[i] += memo[i - syl[j]];
					memo[i] %= MOD;
				}
			}
		}
	}

	ll ret = 1;
	for(auto &l : lets){
		if(l){
			ll tmp = 0;
			for(auto &p : poss){
				if(p){
					tmp += mpow(p, l);
					tmp %= MOD;
				}
			}
			ret *= tmp;
			ret %= MOD;
		}
	}
	
	fout << ret << endl;
}
/*
Keep It Simple, Stupid!
Caution:
- integer overflow (check num constraints)
- segfault (check array / other ds bounds)
- special / edge cases
Stay organized and think before you type.
*/