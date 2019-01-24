#include <bits/stdc++.h>
using namespace std;

size_t N;
char grid[1000000];
size_t perimeter = 0;

size_t getIndex(size_t row, size_t column){
	return row*N + column;
}

size_t ff(int row, int column, bool seen[]){
	size_t index = getIndex(row, column);
	if(row == -1 || column == -1 || row == N || column == N){
		++perimeter;
		return 0;
	}
	if(grid[index] != '#'){
		++perimeter;
		return 0;
	}
	if(seen[index])
		return 0;

	seen[index] = true;
	return 1 + ff(row +1, column, seen) + ff(row -1, column, seen) 
	+ ff(row, column +1, seen) + ff(row, column -1, seen);
}
int main(){
	ifstream fin("perimeter.in");
	ofstream fout("perimeter.out");

	fin >> N;
	for(size_t i = 0; i < N*N; ++i)
		fin >> grid[i];

	size_t best = 0;
	bool seen[1000000] = {false};
	size_t bestArea = 0, bestPerimeter = 0;
	for(size_t i = 0; i < N; ++i){
		for(size_t j = 0; j < N; ++j){
			if(seen[getIndex(i,j)] || grid[getIndex(i,j)] == '.')
				continue;
			perimeter = 0;
			size_t area = ff(i, j, seen);
			if(area > bestArea){
				bestArea = area;
				bestPerimeter = perimeter;
			}
			if(area == bestArea && perimeter < bestPerimeter)
				bestPerimeter = perimeter;
		}
	}

	fout << bestArea << " " << bestPerimeter << endl;
}