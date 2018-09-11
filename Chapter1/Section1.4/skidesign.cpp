/*
ID: billz541
TASK: skidesign
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	size_t N;
	fin >> N;
	size_t heights[N];
	for(size_t i = 0; i < N; ++i) fin >> heights[i];
	sort(heights, heights+N);
	size_t MIN = heights[0], MAX = heights[N-1];
	if((MAX - MIN) <= 17) {fout << 0 << endl; return 0;};
	size_t bestPrice = numeric_limits<size_t>::max();
	for(size_t bottom = MIN, top = MIN + 17; top <= MAX; ++bottom, ++top){
		size_t price = 0;
		for(size_t i = 0; heights[i] < bottom; ++i) price += pow((bottom - heights[i]),2);
		for(size_t i = N-1; heights[i] > top; --i) price += pow((heights[i] - top),2);
		if(price < bestPrice) bestPrice = price;
	}
	fout << bestPrice << endl;
}