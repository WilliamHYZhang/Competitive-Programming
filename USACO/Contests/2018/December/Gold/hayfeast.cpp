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

ll tot[100000];
set<pair<int, int>, greater<pair<int, int>>> sSp;
set<int> seen;

int main(){
	//USACO
	ifstream fin("hayfeast.in");
	fin.sync_with_stdio(false);
	fin.tie(NULL);
	ofstream fout("hayfeast.out");

	int N; ll M;
	fin >> N >> M;
	
	ll tmp = 0;
	for(int i = 0; i < N; ++i){
		int flav, sp;
		fin >> flav >> sp;
		tmp += flav;
		tot[i] = tmp;
		sSp.ins(mp(sp, i));
	}

	int ret = 0;
	seen.insert(-1);
	seen.insert(N-1);
	for(auto &pos : sSp){
		int l = *(--seen.lb(pos.s)), r = *(seen.lb(pos.s));
		if((l == -1 ? tot[r] : tot[r] - tot[l]) >= M)
			ret = pos.f;
		seen.insert(pos.s);
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