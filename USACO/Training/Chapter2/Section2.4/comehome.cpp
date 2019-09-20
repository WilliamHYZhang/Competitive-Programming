/*
ID: billz541
TASK: comehome
LANG: C++11
*/
//This was an obvious Dijkstra, but my first time coding one. Yay me.
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define INF INT_MAX

int main(){
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	int P;
	fin >> P;
	vector<list<pair<int, int>>> graph;
	graph.resize(58);
	for(int i = 0; i < P; ++i){
		char a, b; int w;
		fin >> a >> b >> w;
		graph[a-'A'].pb(mp(b-'A', w));
		graph[b-'A'].pb(mp(a-'A', w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(58, INF);
	pq.push(mp(0, 25));
	dist[25] = 0;

	while(!pq.empty()){
		int i = pq.top().s;
		pq.pop();
		for(auto &j : graph[i]){
			int k = j.f, w = j.s;
			if(dist[k] > dist[i] + w){
				dist[k] = dist[i] + w;
				pq.push(mp(dist[k], k));
			}
		}
	}

	char c; int l = INF;
	for(int i = 0; i < 25; ++i){
		if(dist[i] < l){
			c = 'A' + i;
			l = dist[i]; 
		}
	}

	fout << c << " " << l << endl;
}
//Keep It Simple, Stupid!