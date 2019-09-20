#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");

	size_t L, N, rF, rB;
	fin >> L >> N >> rF >> rB;

	vector<pair<size_t, size_t>> stops;
	for(size_t i = 0; i < N; ++i){
		size_t pos, val;
		fin >> pos >> val;
		stops.push_back(make_pair(val, pos));
	}

	sort(stops.begin(), stops.end(), 
		[](const pair<size_t, size_t> &a, const pair<size_t, size_t> &b)
		{return(a.first > b.first || (a.first == b.first && a.second < b.second));});

	size_t ans = 0, lastPos = 0;
	for(const auto stop : stops){
		size_t val = stop.first, pos = stop.second;
		if(pos < lastPos)
			continue;
		ans += (pos - lastPos) * (rF - rB) * val;
		lastPos = pos;
	}

	fout << ans << endl;
}
