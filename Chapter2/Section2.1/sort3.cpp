/*
ID: billz541
TASK: sort3
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
//This solution is hella retarded sry
int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	size_t seq[1000][2] = {0};
	size_t N;
	fin >> N;

	size_t oneCount = 0, twoCount = 0, threeCount = 0;

	for(size_t i = 0, num; i < N; ++i){
		fin >> num;
		seq[i][0] = num;
		if(num == 1) ++oneCount;
		if(num == 2) ++twoCount;
		if(num == 3) ++threeCount;
	}

	size_t currentIndex = 0;
	for(; currentIndex < oneCount; ++currentIndex) seq[currentIndex][1] = 1;
	for(; currentIndex < oneCount+twoCount; ++currentIndex) seq[currentIndex][1] = 2;
	for(; currentIndex < oneCount+twoCount+threeCount; ++currentIndex) seq[currentIndex][1] = 3;

	size_t ans = 0, firstAloneA = 0, firstAloneB = 0, firstRepeat = 0;
	bool seen[1000] = {false};
	bool alone = false;
	for(size_t i = 0; i < N; ++i){
		size_t a = seq[i][0], b = seq[i][1], j = i+1;
		if(seen[i]) continue;	
		if(a == b) continue;	
		for(; j <= N; ++j)
			if(seq[j][0] == b && seq[j][1] == a && !seen[j])
				break;
		if(j < N)
			seen[j] = true;
		else{
			cout << "nope" << endl;
			if(!alone){
				firstAloneA = a;
				firstAloneB = b;
				alone = true;
				++firstRepeat;
			}
			else if(firstAloneA == a && firstAloneB == b)
				++firstRepeat;
		}

		++ans;
	}
	ans -= firstRepeat;
	fout << ans << endl;
}
