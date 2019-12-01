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

vector<list<pair<int, ll>>> graph;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<pair<ll, deque<int>>> dist;

ll cows[10000]; 
ll red[10000];

int main(){
	//USACO
	ifstream fin("shortcut.in");
	fin.sync_with_stdio(false);
	fin.tie(NULL);
	ofstream fout("shortcut.out");

	int N, M, T;
	fin >> N >> M >> T;

	graph.rsz(N);
	deque<int> dq;
	dist.rsz(N, mp(INF, dq));

	for(int i = 0; i < N; ++i)
		fin >> cows[i];

	for(int i = 0; i < M; ++i){
		int a, b; ll t;
		fin >> a >> b >> t;
		--a; --b;
		graph[a].pub(mp(b, t));
		graph[b].pub(mp(a, t));

	}

	pq.push(mp(0, 0));
	dist[0] = mp(0, dq);

	while(!pq.empty()){
		ll u = pq.top().s;
		pq.pop();
		for(auto &i : graph[u]){
			int v = i.f; ll w = i.s;
			if(dist[v].f == dist[u].f + w){
				bool rep = sz(dist[v].s) > sz(dist[u].s);
				dist[u].s.puf(u);
				for(int i = 0, m = min(sz(dist[v].s), sz(dist[u].s)); i < m; ++i){
					if(dist[v].s[i] > dist[u].s[i]){
						rep = true;
						break;
					}
					if(dist[v].s[i] < dist[u].s[i]){
						rep = false;
						break;
					}
				}
				if(rep)
					dist[v].s = dist[u].s;
				dist[u].s.pof();
			}
			if(dist[v].f > dist[u].f + w){
				dist[v].f = dist[u].f + w;
				dist[v].s = dist[u].s;
				dist[v].s.puf(u);
				pq.push(mp(dist[v].f, v));
			}
		}
	}

	for(int i = 1; i < N; ++i){
		red[i] += cows[i] * (dist[i].f - T);
		for(auto c : dist[i].s){
			red[c] += cows[i] * (dist[c].f - T);
		}
	}

	ll ans = 0;
	for(auto r : red)
		ans = max(ans, r);
	fout << ans << endl;
	
}
/*
Keep It Simple, Stupid!
Caution:
- integer overflow (check num constraints)
- segfault (check array / other ds bounds)
- special / edge cases
Stay organized and think before you type.
*/