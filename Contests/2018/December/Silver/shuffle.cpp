#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");

	size_t N;
	fin >> N;
	unordered_map<size_t, size_t> shuffle;
	for(size_t i = 1, j; i <= N; ++i){fin >> j; shuffle[i] = j;};
	unordered_set<size_t> seen;
	size_t ans = 0;
	for(size_t i = 1; i <= N; ++i){
		if(seen.find(i) != seen.end()) continue; 
		else{
			bool saw = false;
			unordered_set<size_t> tempSeen;
			size_t current = i;
			while(tempSeen.find(current) == tempSeen.end()){
				if(seen.find(current) != seen.end()){saw = true; break;};
				seen.insert(current);
				tempSeen.insert(current);
				current = shuffle[current];
			}
			tempSeen.clear();
			if(saw) continue;
			while(tempSeen.find(current) == tempSeen.end()){
				tempSeen.insert(current);
				current = shuffle[current];
				++ans;
			}
		}
	}
	fout << ans << endl;
}
