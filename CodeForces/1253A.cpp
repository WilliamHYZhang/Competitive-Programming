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

int a[100000], b[100000];

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
		int N;
		cin >> N;
		for(int j = 0; j < N; ++j)
			cin >> a[j];
		for(int j = 0; j < N; ++j)
			cin >> b[j];
		bool push = false, ret = true;
		for(int j = 0; j < N; ++j){
			if(a[j] != b[j]){
				int k = b[j] - a[j];
				if(push || k < 0){
					ret = false;
					break;
				}
				while(j < N && b[j] - a[j] == k)
					++j;
				push = true;
				--j;
			}
		}
		cout << (ret ? "YES" : "NO") << endl;
	}
}
//Keep It Simple, Stupid!