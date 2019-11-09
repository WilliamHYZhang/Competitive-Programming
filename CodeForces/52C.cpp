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

const int MAXN = 200000;
int N;
ll a[MAXN];
ll seg[4*MAXN];
ll lazy[4*MAXN] = {0};

void build(int id = 1, int l = 0, int r = N-1){
	if(l == r){
		seg[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	seg[id] = min(seg[2*id], seg[2*id+1]);
}

void shift(int id, int l, int r){
	if(lazy[id]){
		seg[id] += lazy[id];
		if(l != r){
			lazy[2*id] += lazy[id];
			lazy[2*id+1] += lazy[id];
		}
	}
	lazy[id] = 0;
}

void upd(int L, int R, int d, int id = 1, int l = 0, int r = N-1){
	shift(id, l, r);
	if(l > R || r < L)
		return;
	if(l >= L && r <= R){
		lazy[id] += d;
		shift(id, l, r);
		return;
	}
	int mid = (l+r)/2;
	upd(L, R, d, 2*id, l, mid);
	upd(L, R, d, 2*id+1, mid+1, r);
	seg[id] = min(seg[2*id], seg[2*id+1]);
}

ll query(int L, int R, int id = 1, int l = 0, int r = N-1){
	shift(id, l, r);
	if(l > R || r < L)
		return INF;
	if(l >= L && r <= R)
		return seg[id];
	int mid = (l+r)/2;
	return min(query(L, R, 2*id, l, mid), query(L, R, 2*id+1, mid+1, r));
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	build();
	int M;
	cin >> M;
	cin.ignore();
	for(int i = 0; i < M; ++i){
		int l, r, v = 1000001; //init v out of bounds
		string line;
		getline(cin, line);
		istringstream iss(line);
		iss >> l >> r >> v;
		if(v != 1000001){
			if(l > r){
				upd(l, N-1, v);
				upd(0, r, v);
			}
			else
				upd(l, r, v);
		}
		else{
			if(l > r)
				cout << min(query(l, N-1), query(0, r)) << endl;
			else
				cout << query(l, r) << endl;
		}
	}
}
//Keep It Simple, Stupid!