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
	int N, M, D;
	cin >> N >> M >> D;
	int platform[1000];
	int space = N;
	for(int i = 0; i < M; ++i){
		cin >> platform[i];
		space -= platform[i];
	}
	int dSpace = space/(M+1) * (M+1) == space ? space/(M+1) : space/(M+1) + 1;
	if(dSpace >= D)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(int i = 0; i < M; ++i){
			for(int j = 0; j < dSpace && space; ++j, --space)
				cout << 0 << " ";
			for(int j = 0; j < platform[i]; ++j)
				cout << i+1 << " ";
		}
		if(space)
			for(int j = 0; j < space; ++j)
				cout << 0 << " ";
		cout << endl;
	}
}
//Keep It Simple, Stupid!