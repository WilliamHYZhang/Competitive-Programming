//Algo template for Prim (MST given graph as adj list): O(E*logV)

int N; //number of vertices
vector<list<pair<int, int>>> graph;
graph.rsz(N);

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(N, INF);
//vector<int> parent(N, -1); include if want to print MST
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
			//parent[v] = u; include if want to print MST
		}
	}
}

int MIN = 0;
for(int &i : dist)
	MIN += i;