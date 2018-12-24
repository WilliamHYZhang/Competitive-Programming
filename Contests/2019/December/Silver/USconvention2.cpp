#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");

	size_t N;
	fin >> N;

	priority_queue<tuple<size_t, size_t, size_t>> line;
	vector<tuple<size_t, size_t, size_t>> cows;

	for(size_t i = N; i > 0; --i){
		size_t a, t;
		fin >> a >> t;
		cows.push_back(make_tuple(i, a, t));
	}
	
	sort(cows.begin(), cows.end(),
		[](tuple<size_t, size_t, size_t> a, tuple<size_t, size_t, size_t> b)
		{return get<1>(a) < get<1>(b);});
	
	size_t went = 0, maxWait = 0, currentTime = 0, currentIndex = 0;
	while(went < N){
		if(line.empty()){
			line.push(cows[currentIndex]);
			++currentIndex;
			currentTime = get<1>(line.top());
		}
		size_t wait = currentTime > get<1>(line.top()) ? currentTime - get<1>(line.top()) : 0;
		if(wait > maxWait)
			maxWait = wait;
		currentTime += get<2>(line.top());
		line.pop();
		for(; currentIndex < N; ++currentIndex)
			if(get<1>(cows[currentIndex]) <= currentTime)
				line.push(cows[currentIndex]);
			else
				break;
		++went;
	}

	fout << maxWait << endl;
}