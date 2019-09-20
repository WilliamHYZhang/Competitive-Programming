#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("mountains.in");
	ofstream fout("mountains.out");

	int N;
	fin >> N;
	vector<pair<int, int>> peaks;
	for(int i = 0, x, y; i < N; ++i){
		fin >> x >> y;
		peaks.push_back(make_pair(x, y));
	}

	sort(peaks.begin(), peaks.end(),
		[](pair<int, int> a, pair<int, int> b){return a.second > b.second;});

	vector<pair<int, int>> seens;
	size_t ans = 0;
	for(auto peak : peaks){
		bool add = true;
		for(auto seen : seens){
			if(abs(peak.first - seen.first) <= (seen.second - peak.second)){
				add = false;
			}
		}
		if(add){
			++ans;
			seens.push_back(peak);
		}
		
	}

	fout << ans << endl;
}
