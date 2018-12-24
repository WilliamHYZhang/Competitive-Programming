#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");

	size_t N, Q;
	fin >> N >> Q;
	size_t hay[N];

	for(size_t i = 0; i < N; ++i)
		fin >> hay[i];

	sort(hay, hay+N);

	for(size_t i = 0; i < Q; ++i){
		size_t start, stop;
		fin >> start >> stop;
		auto itStart = lower_bound(hay, hay+N, start), itStop = upper_bound(hay, hay+N, stop)-1;
		fout << itStop - itStart + 1 << endl;
	}
}