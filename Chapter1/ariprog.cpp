/*
ID: billz541
TASK: ariprog
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	size_t N, M;
	fin >> N >> M;
	unordered_set<size_t> setProg;
	set<pair<size_t, size_t>> ans;
	for(size_t i = 0; i <= M; ++i) for(size_t j = i; j <= M; ++j) setProg.insert((i*i)+(j*j));
	vector<size_t> prog(setProg.size());
	copy(setProg.begin(), setProg.end(), prog.begin());
	sort(prog.begin(), prog.end());
	vector<size_t> diffs;
	size_t maximum = prog.back();

	for(size_t i = 1; i < prog.size(); ++i) diffs.push_back(prog[i]-prog[i-1]);
	for(size_t start = 0; start < prog.size()-N+1; ++start){
		size_t currentDiff = 0;
		for(size_t end = start; end < prog.size()-N+1; ++end){	
			currentDiff += diffs[end];
			if(currentDiff*(N-1)+prog[start] > maximum) break;
			bool exists = true;
			for(size_t i = prog[start]; i <= prog[start] + ((N-1)*currentDiff); i += currentDiff)
				if(setProg.find(i) == setProg.end()) {exists = false; break;};
			if(exists) ans.insert(make_pair(currentDiff, prog[start]));
			
		}
	}
	for(auto &elem : ans) fout << elem.second << " " << elem.first << endl;
	if(ans.size() == 0) fout << "NONE" << endl;
	
}