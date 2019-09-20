#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<size_t, size_t>> boots;
vector<size_t> path;
size_t best;
bool seen[250][250] = {0};

void search(size_t bI, size_t pI){ //bI = boot index, pI = path index
	if(seen[bI][pI])
		return;
	seen[bI][pI] = true;
	auto maxD = boots[bI].first; //max depth
	auto maxL = boots[bI].second; //max length
	for(size_t i = pI+1; i <= pI+maxL; ++i){
		if(i == path.size()-1){
			if(best > bI)
				best = bI;
			return;
		}
		if(path[i] <= maxD){
			for(size_t j = bI; j < boots.size(); ++j){
				if(path[i] <= boots[j].first){
					search(j, i);
				}
			}
		}
	}
	
}
int main(){
	ifstream fin("snowboots.in");
	ofstream fout("snowboots.out");
	size_t N, B;
	fin >> N >> B;

	best = B;

	for(size_t i = 0, d; i < N; ++i){
		fin >> d;
		path.push_back(d);
	}
	for(size_t i = 0, d, l; i < B; ++i){
		fin >> d >> l;
		boots.push_back(make_pair(d,l));
	}

	for(size_t i = 0; i < boots.size(); ++i){
		search(i, 0);
	}

	fout << best << endl;
}