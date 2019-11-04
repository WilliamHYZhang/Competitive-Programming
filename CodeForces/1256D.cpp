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

int main(){
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
		ll N, K;
		cin >> N >> K;
		string str;
		cin >> str;
		ll remain = K, cur = 0;
		for(int j = 0; j < N && remain; ++j){
			if(str[j] == '0'){
				if(remain >= (j - cur))
					{swap(str[j], str[cur]); remain -= (j - cur); ++cur;}
				else
					{swap(str[j], str[j - remain]); remain = 0;}
			}
		}
		cout << str << endl;
	}
}
//Keep It Simple, Stupid!