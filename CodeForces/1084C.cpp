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

vector<ll> as;

int main(){
	//CF
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> str;
	for(int i = 0; i < sz(str); ++i){
		if(str[i] == 'a'){
			ll tmp = 1;
			while(i < sz(str) && str[++i] != 'b')
				if(str[i] == 'a')
					++tmp;
			as.pub(tmp);
		}
	}

	ll ans = 0;
	for(auto a : as){
		ans += (a + a * ans);
		ans %= MOD;
	}

	cout << ans << endl;
}
/*
Keep It Simple, Stupid!
Caution:
- integer overflow (check num constraints)
- segfault (check array / other ds bounds)
- special / edge cases
Stay organized and think before you type.
*/