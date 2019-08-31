//Algo template for FloydWarshall (all pairs shortest path given graph as adj matrix)

int N; //Number of verticies
int matrix[N][N]; // INF if not connected, otherwise weight of connection

//Take in input

int dist[N][N];
for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		dist[i][j] = matrix[i][j];

for(int k = 0; k < N; ++k)
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(dist[i][k] != INF &&
				dist[k][j] != INF &&
				dist[i][k] + dist[k][j] < dist[i][j])
				dist[i][j] = dist[i][k] + dist[k][j];