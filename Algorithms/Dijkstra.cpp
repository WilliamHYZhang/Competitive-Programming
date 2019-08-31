//Algo template for Dijkstra (shortest path given source vertex and graph as adj list)

int N; //number of vertices
vector<list<pair<int, int>>> graph;
graph.rsz(N);

//Take in input

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(N, INF);
pq.push(mp(0, /*source vertex*/));
dist[/*source vertex*/] = 0;

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