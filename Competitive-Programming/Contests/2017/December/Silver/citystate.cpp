#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");

	size_t N;
	fin >> N;

	unordered_map<string, multiset<string>> pairs;
	vector<pair<string, string>> locations;

	for(size_t i = 0; i < N; ++i){
		string city, state;
		fin >> city >> state;
		city = city.assign(city, 0, 2);
		if(city != state)
			pairs[state].insert(city);
		locations.push_back(make_pair(city, state));
	}

	size_t ans = 0;

	for(auto const location : locations){
		ans += pairs[location.first].count(location.second);
	}

	fout << ans/2 << endl;
}