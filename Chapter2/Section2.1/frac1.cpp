/*
ID: billz541
TASK: frac1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	size_t N;
	fin >> N;

	unordered_set<double> used;
	vector<pair<size_t, size_t>> ans;

	for(size_t d = 1; d <= N; ++d){
		for(size_t n = 0; n <= d; ++n){
			double frac = static_cast<double>(n)/d;
			if(used.find(frac) == used.end()){
				used.insert(frac);
				ans.push_back(make_pair(n, d));
			}
		}
	}

	sort(ans.begin(), ans.end(),
		[](pair<size_t, size_t> a, pair<size_t, size_t> b)
		{return static_cast<double>(a.first)/a.second < static_cast<double>(b.first)/b.second;});

	for(auto frac : ans) fout << frac.first << "/" << frac.second << endl;
}