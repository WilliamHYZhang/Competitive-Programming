#include <bits/stdc++.h>
using namespace std;

size_t N, K;

size_t binSearch(size_t hay[], size_t start, size_t end){
	if(start == end)
		return start;

	size_t R = start + (end-start)/2;

	size_t currentStart = hay[0], cowNum = 1;
	for(size_t i = 0; i < N; ++i){
		if((hay[i] - currentStart) > R*2){
			currentStart = hay[i];
			++cowNum;
		}
	}
	if(cowNum > K)
		return binSearch(hay, R+1, end);
	return binSearch(hay, start, R);
}
int main(){
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	fin >> N >> K;
	size_t hay[N];

	for(size_t i = 0; i < N; ++i)
		fin >> hay[i];

	sort(hay, hay+N);
	fout << binSearch(hay, 0, 1000000000) << endl;
}