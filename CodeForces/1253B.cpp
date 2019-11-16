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

bool here[1000001];
unordered_set<int> seen;
vector<int> ret;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	int p = 0, e = 0;
	for(int i = 0; i < N; ++i){
		int event;
		cin >> event;
		if(event > 0){
			if(here[event] || !seen.insert(event).s){
				cout << -1 << endl;
				return 0;
			}
			here[event] = true;
			++p; ++e;
		}
		else{
			if(!here[0-event]){
				cout << -1 << endl;
				return 0;
			}
			here[0-event] = false;
			--p; ++e;
			if(p == 0){
				seen.clear();
				ret.pub(e);
				e = 0;
			}
		}
	}

	if(p){
		cout << -1 << endl;
		return 0;
	}
	cout << sz(ret) << endl;
	for(auto &r : ret)
		cout << r << " ";
	cout << endl;
}
//Keep It Simple, Stupid!