#include <fstream>
#include <map>
using namespace std;

int main(){
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	size_t N, M, K;
	fin >> N >> M >> K;
	size_t order[N];
	for(size_t i = 0; i < N; ++i) order[i] = 0;
	bool in = false;
	size_t social[M];
	map<size_t, size_t> position;
	for(size_t i = 0; i < M; ++i){
		fin >> social[i];
		if(social[i] == 1) in = true;
	}
	for(size_t i = 0, cow, pos; i < K; ++i){
		fin >> cow >> pos;
		if(cow == 1){fout << pos << endl; return 0;};
		position[cow] = pos-1;
		order[pos-1] = cow;
	}
	if(!in){
		for(size_t i = M-1, j = N-1; i-- > 0;){		
			if(position.find(social[i]) != position.end()){
				j = position[social[i]];
				continue;
			}
			while(order[j]) --j;
			order[j] = social[i];
		}
		for(size_t i = 0; i < N; ++i)
			if(!order[i]) {fout << i+1 << endl; return 0;};
	}
	else{
		for(size_t i = 0, j = 0; i < M; ++i){
			if(position.find(social[i]) != position.end()){
				j = position[social[i]];
				continue;
			}
			while(order[j]) ++j;
			if(social[i] == 1) {fout << j+1 << endl; return 0;};
			order[j] = social[i];
		}
	}
}