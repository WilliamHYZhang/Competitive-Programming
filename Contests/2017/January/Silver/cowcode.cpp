#include <bits/stdc++.h>
using namespace std;
string initial;
size_t N;

char findChar(size_t i, size_t j){
	if(i <= initial.size())
		return initial[i-1];
	size_t nextI = i-j-1;
	if(nextI != 0){
		for(; j > nextI; j /= 2);
		findChar(nextI, j);
	}
	else
		findChar(j, j/2);
}

int main(){
	ifstream fin("cowcode.in");
	ofstream fout("cowcode.out");
	fin >> initial >> N;
	size_t j = initial.size();
	for(; j < N; j *= 2);
	j /= 2;
	fout << findChar(N, j) << endl;
}