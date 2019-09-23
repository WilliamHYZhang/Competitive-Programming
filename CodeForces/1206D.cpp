//This was pretty darn hard. Happy I solved it at last :)
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int INF = INT_MAX;
const int MOD = 1000000007;

int main(){
	int N;
	cin >> N;
	ll a[100000];
	for(int i = 0; i < N; ++i)
		cin >> a[i];

	vector<vector<ll>> b;
	b.rsz(60);
	for(int i = 0; i < 60; ++i)
		for(int j = 0; j < N; ++j)
			if(a[j] & (1LL << i))
				b[i].pb(j);
			
	for(auto &i : b)
		if(sz(i) >= 3)
			{cout << 3 << endl; return 0;};

	vector<list<int>> g;
	g.rsz(N);
	for(auto &i : b){
		if(sz(i) == 2){
			g[i[0]].pb(i[1]);
			g[i[1]].pb(i[0]);
		}
	}

	int MIN = INF;
	queue<pair<int, int>> q; //num, min dist
	vector<bool> seen;
	seen.rsz(N);
	for(int i = 0; i < N; ++i){
		for(auto &j : g[i]){
			for(auto &k : g[i])
				if(k != j)
					q.push(mp(k, 1));
			while(!q.empty()){
				auto c = q.front();
				q.pop();
				if(!seen[c.f]){
					if(c.f == j){
						MIN = min(MIN, c.s+1);
						break;
					}
					if(c.f != j && c.f != i){
						seen[c.f] = true;
						for(auto &k : g[c.f])
							if(!seen[k])
								q.push(mp(k, c.s+1));
					}
				}
			}
			q = queue<pair<int, int>>();
			fill(all(seen), false);
		}
	}

	cout << (MIN == INF ? -1 : MIN) << endl;
}
//Keep It Simple, Stupid!