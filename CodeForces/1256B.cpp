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
	int arr[100];
	bool ops[100];
	for(int i = 0; i < Q; ++i){
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i){
			cin >> arr[i];
			ops[i] = false;
		}
		for(int i = 0; i < N-1; ++i){
			int best[2] = {arr[i], -1};
			for(int j = i; j < N-1 && !ops[j]; ++j)
				if(arr[j+1] < best[0])
					{best[0] = arr[j+1]; best[1] = j;}
			for(int j = best[1]; j >= i; --j){
				swap(arr[j], arr[j+1]);
				ops[j] = true;
			}
		}
		for(int i = 0; i < N; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
}
//Keep It Simple, Stupid!