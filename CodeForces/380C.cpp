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

const int MAXM = 1000000;
int segx[4*MAXM], segl[4*MAXM], segr[4*MAXM];
string seq;

void build(int id = 1, int l = 0, int r = sz(seq)-1){
	if(l == r){
		segx[id] = 0;
		segl[id] = seq[l] == '(';
		segr[id] = seq[r] == ')';
		return;
	}
	int mid = (l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	int tmp = min(segl[2*id], segr[2*id+1]);
	segx[id] = segx[2*id] + segx[2*id+1] + tmp;
	segl[id] = segl[2*id] + segl[2*id+1] - tmp;
	segr[id] = segr[2*id] + segr[2*id+1] - tmp;
}

pair<int, pair<int, int>> query(int L, int R, int id = 1, int l = 0, int r = sz(seq)-1){
	if(l > R || r < L)
		return mp(0, mp(0, 0));
	if(l >= L && r <= R)
		return mp(segx[id], mp(segl[id], segr[id]));
	int mid = (l+r)/2;
	auto a = query(L, R, 2*id, l, mid), b = query(L, R, 2*id+1, mid+1, r);
 	int tmp = min(a.s.f, b.s.s);
	int rX = a.f + b.f + tmp;
	int rL = a.s.f + b.s.f - tmp;
	int rR = a.s.s + b.s.s - tmp;
	return mp(rX, mp(rL, rR));
}

int main(){
	cin >> seq;
	build();
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i){
		int L, R;
		cin >> L >> R;
		cout << 2 * query(L-1, R-1).f << endl;
	}
}
//Keep It Simple, Stupid!
