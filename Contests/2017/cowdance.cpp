#include <bits/stdc++.h>
using namespace std;

size_t N, maxT;

bool works(size_t cows[], size_t k){
	multiset<size_t> times;

	for(size_t i = 0; i < k; ++i)
		times.insert(cows[i]);
	
	for(size_t i = k; i < N; ++i){
		auto replace = *times.begin();
		times.erase(times.begin());
		times.insert(replace + cows[i]);
	}

	return *--times.end() <= maxT;
}
size_t binSearch(size_t cows[], size_t start, size_t end){
	if(start == end)
		return start;
	if(start+1 == end){
		if(works(cows, start))
			return start;
		return end;
	}

	size_t minK = start + (end-start)/2;
	if(works(cows, minK))
		return binSearch(cows, start, minK);
	return binSearch(cows, minK+1, end);
}

int main(){
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");

	fin >> N >> maxT;
	size_t cows[N];

	for(size_t i = 0; i < N; ++i)
		fin >> cows[i];
	
	fout << binSearch(cows, 1, N) << endl;
}