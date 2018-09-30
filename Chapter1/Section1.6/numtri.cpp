/*
ID: billz541
TASK: numtri
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

size_t N;
vector<size_t> tree;
vector<size_t> seen;

size_t getIndex(size_t row, size_t column){
	return (row * (1 + row)) / 2 + column;
}

size_t findPath(size_t row, size_t column){
	if(seen[getIndex(row, column)] == -1){
		if(row == N-1)
			seen[getIndex(row, column)] = tree[getIndex(row, column)];
		else
			seen[getIndex(row, column)] = tree[getIndex(row, column)] + max(findPath(row+1, column), findPath(row+1, column+1));
	}
	return seen[getIndex(row, column)];
}

int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	fin >> N;
	size_t num = (N*(1+N))/2;
	for(size_t i = 0, input; i < num; ++i){
		fin >> input;
		tree.push_back(input);
		seen.push_back(-1);
	}
	fout << findPath(0,0) << endl;
}
