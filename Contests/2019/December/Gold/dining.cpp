//My first gold, holy jeebus this is really hard.
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define INF INT_MAX

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	ifstream fin("dining.in");
	ofstream fout("dining.out");

	int N, M, K;
	fin >> N >> M >> K;

	vector<list<pair<int, int>>> graph;
	graph.rsz(N+1);

	for(int i = 0; i < M; ++i){
		int a, b, t;
		fin >> a >> b >> t;
		--a; --b;
		graph[a].pb(mp(b, t));
		graph[b].pb(mp(a, t));
	}

	vector<pair<int, int>> hay;

	for(int i = 0; i < K; ++i){
		int p, y;
		fin >> p >> y;
		--p;
		hay.pb(mp(p, y));
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N, INF);
	pq.push(mp(0, N-1));
	dist[N-1] = 0;

	while(!pq.empty()){
		int u = pq.top().s;
		pq.pop();
		for(auto &i : graph[u]){
			int v = i.f, w = i.s;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}

	for(auto &i : hay)
		graph[N].pb(mp(i.f, dist[i.f]-i.s));
	
	vector<int> haydist(N+1, INF);
	pq.push(mp(0, N));
	haydist[N] = 0;

	while(!pq.empty()){
		int u = pq.top().s;
		pq.pop();
		for(auto &i : graph[u]){
			int v = i.f, w = i.s;
			if(haydist[v] > haydist[u] + w){
				haydist[v] = haydist[u] + w;
				pq.push(mp(haydist[v], v));
			}
		}
	}
	
	for(int i = 0; i < N-1; ++i){
		if(dist[i] >= haydist[i])
			fout << 1 << endl;
		else
			fout << 0 << endl;
	}
	
}
//Keep It Simple, Stupid!