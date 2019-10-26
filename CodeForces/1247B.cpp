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

int ep[200001];
int cnt[1000001];

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
		int N, K, D;
		cin >> N >> K >> D;
		for(int j = 0; j < N; ++j)
			cin >> ep[j];
		fill_n(cnt, K+1, 0);
		int ans = 0;
		for(int j = 0; j < D; ++j){
			if(!cnt[ep[j]]) ++ans;
			++cnt[ep[j]];
		}
		int tmp = ans;
		for(int j = 0; j < N-D; ++j){
			--cnt[ep[j]];
			if(!cnt[ep[j]]) --tmp;
			if(!cnt[ep[j+D]]) ++tmp;
			++cnt[ep[j+D]];
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
}
//Keep It Simple, Stupid!