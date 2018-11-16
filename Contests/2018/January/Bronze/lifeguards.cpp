#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin("lifeguards.in");
	size_t num;
	fin >> num;
	vector<pair<size_t, size_t>> shifts;
	size_t times[1001]{0};

	for(size_t i = 0; i < num; ++i){
		size_t start, end;
		fin >> start >> end;
		shifts.push_back(make_pair(start, end));
		for(size_t iter = start; iter <  end; ++iter)
			++times[iter];
	}
	size_t maxTime = 0;
	for(auto const &shift : shifts){
		for(size_t iter = shift.first, end = shift.second; iter < end; ++iter)
			--times[iter];
		size_t tempMaxTime = 0;
		for(auto const &time : times){
			if(time > 0)
				++tempMaxTime;
		}
		if(tempMaxTime > maxTime)
			maxTime = tempMaxTime;
		for(size_t iter = shift.first, end = shift.second; iter < end; ++iter)
			++times[iter];
	}

	ofstream fout("lifeguards.out");
	fout << maxTime << endl;
}
