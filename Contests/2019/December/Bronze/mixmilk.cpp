#include <iostream>
#include <fstream>
using namespace std;

void pour(size_t buckets[3][2], size_t start, size_t end){
	if((buckets[start][0]+buckets[end][0]) > buckets[end][1]){
		buckets[start][0] = buckets[start][0]+buckets[end][0]-buckets[end][1];
		buckets[end][0] = buckets[end][1];
	}
	else{
		buckets[end][0] = buckets[start][0]+buckets[end][0];
		buckets[start][0] = 0;
	}
}
int main(){
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");
	size_t buckets[3][2];
	fin >> buckets[0][1] >> buckets[0][0];
	fin >> buckets[1][1] >> buckets[1][0];
	fin >> buckets[2][1] >> buckets[2][0];

	size_t start = 0, end = 1;
	for(size_t i = 0; i < 100; ++i){
		pour(buckets, start, end);
		start == 2 ? start = 0 : ++start;
		end == 2 ? end = 0 : ++end;
	}
	fout << buckets[0][0] << endl << buckets[1][0] << endl << buckets[2][0] << endl;
}
