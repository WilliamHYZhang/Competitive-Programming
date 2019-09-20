/*
ID: billz541
TASK: agrinet
LANG: C++11
*/
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

int main(){
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	int N;
	fin >> N;
	vector<list<pair<int, int>>> graph;
	graph.resize(N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int w;
			fin >> w;
			if(i != j)
				graph[i].pb(mp(j, w));
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N, INF);
	vector<bool> inMST(N, false);
	pq.push(mp(0,0));
	dist[0] = 0;

	while(!pq.empty()){
		int u = pq.top().s;
		pq.pop();
		inMST[u] = true;
		for(auto &i : graph[u]){
			int v = i.f, w = i.s;
			if(!inMST[v] && dist[v] > w){
				dist[v] = w;
				pq.push(mp(dist[v], v));
			}
		}
	}

	int MIN = 0;
	for(int &i : dist)
		MIN += i;
	fout << MIN << endl;
}
//Keep It Simple, Stupid!