#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

size_t N, M, C;

size_t binSearch(size_t cows[], size_t start, size_t end){
	//cout << start << " " << end << endl;

	if(start == end)
		return start;

	size_t maxDiff = start + (end-start)/2;

	size_t busNum = 1, cowNum = 0, firstCow = cows[0];
	for(size_t i = 0; i < N; ++i){
		if((cows[i] - firstCow) <= maxDiff && cowNum+1 <= C)
			++cowNum;
		else{
			if(++busNum > M)
				break;
			cowNum = 1;
			firstCow = cows[i];
		}
	}

	if(busNum > M)
		return binSearch(cows, maxDiff+1, end);

	return binSearch(cows, start, maxDiff);
}
int main(){
	ifstream fin("convention.in");
	ofstream fout("convention.out");

	fin >> N >> M >> C;
	size_t cows[N];
	for(size_t i = 0; i < N; ++i)
		fin >> cows[i];
	sort(cows, cows+N);
	fout << binSearch(cows, 0, 1000000000) << endl;
}