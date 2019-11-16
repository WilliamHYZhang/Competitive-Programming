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

int a[200000];
vector<vector<ll>> shft;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i)
		cin >> a[i];

	sort(a, a+N);

	shft.rsz(M);
	for(int i = 0; i < M; ++i){
		ll j = i, tmp = 0;
		while(j < N){
			tmp += a[j];
			shft[i].pub(tmp);
			j += M;
		}
	}

	for(ll cur = 0, ret = 0;; ++cur){ //nasty for loop
		for(auto &pos : shft){
			if(sz(pos) > cur){
				ret += pos[cur];
				cout << ret << " ";
			}
			else{
				cout << endl; 
				return 0; //nasty return 0 statement
			}
		}
	}
}
//Keep It Simple, Stupid!