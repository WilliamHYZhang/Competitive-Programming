#include <bits/stdc++.h>
using namespace std;

vector<size_t> canRelayTo[200] = {};

void relay(bool seen[], size_t cowIndex, size_t &num){
	for(auto const cow : canRelayTo[cowIndex]){
		if(!seen[cow]){
			++num;
			seen[cow] = true;
			relay(seen, cow, num);
		}
	}
}

double distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

int main(){
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");

	size_t N;
	fin >> N;
	size_t cows[N][3];

	for(size_t i = 0; i < N; ++i)
		fin >> cows[i][0] >> cows[i][1] >> cows[i][2];
	
	for(size_t i = 0; i < N; ++i)
		for(size_t j = 0; j < N; ++j)
			if(distance(cows[i][0], cows[i][1], cows[j][0], cows[j][1]) <= cows[i][2])
				canRelayTo[i].push_back(j);
		
	size_t ans = 0;
	for(size_t i = 0; i < N; ++i){
		bool seen[200] = {false};
		size_t num = 0;
		relay(seen, i, num);
		if(ans < num)
			ans = num;
	}

	fout << ans << endl;
}