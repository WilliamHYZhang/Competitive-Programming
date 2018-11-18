#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<size_t, size_t>>> connections;
size_t ans = 0;

void relevance(size_t index, size_t previousIndex, size_t const K){
	for(auto const connection : connections[index]){
		if(connection.first == previousIndex || connection.second < K)
			continue;
		++ans;
		relevance(connection.first, index, K);
	}
}
int main(){
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	size_t N, Q; 
	fin >> N >> Q;
	connections.resize(N);
	for(size_t i = 0; i < N-1; ++i){
		size_t a, b, rel;
		fin >> a >> b >> rel;
		connections[a-1].push_back(make_pair(b-1, rel));
		connections[b-1].push_back(make_pair(a-1, rel));
	}
	for(size_t i = 0; i < Q; ++i){
		size_t rel, a;
		fin >> rel >> a;
		ans = 0;
		relevance(a-1, 5000, rel);
		fout << ans << endl;
	}
}