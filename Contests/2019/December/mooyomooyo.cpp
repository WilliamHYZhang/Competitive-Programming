#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

size_t N, K;
size_t board[1000];

size_t getIndex(size_t row, size_t column){
	return row*10 + column;
}

size_t ff(int row, int column, size_t seen[], size_t color, bool remove){
	size_t index = getIndex(row, column);
	if(row == -1 || column == -1 || row == N || column == 10 || seen[index])
		return 0;
	if(board[index] != color)
		return 0;
	else{
		seen[index] = 1;
		if(remove)
			board[index] = 0;
		return 1 + ff(row+1, column, seen, color, remove) + ff(row-1, column, seen, color, remove)
		+ ff(row, column+1, seen, color, remove) + ff(row, column-1, seen, color, remove);
	}
}
int main(){
	ifstream fin("mooyomooyo.in");
	ofstream fout("mooyomooyo.out");
	fin >> N >> K;
	for(size_t i = 0, index = 0; i < N; ++i){
		string input;
		fin >> input;
		for(size_t j = 0; j < 10; ++j){
			board[index] = static_cast<size_t>(input[j]) - 48;
			++index;
		}
	}

	while(1){
		bool done = true;
		size_t seen[1000] = {0};
		for(size_t i = 0; i < N; ++i){
			for(size_t j = 0; j < 10; ++j){
				if(seen[getIndex(i,j)] || !board[getIndex(i,j)])
					continue;
				if(ff(i, j, seen, board[getIndex(i,j)], false) >= K){
					done = false;
					size_t temp[1000] = {0};
					ff(i, j, temp, board[getIndex(i,j)], true);
				}
			}
		}

		if(done)
			break;
		
		for(size_t i = 0; i < 10; ++i){
			vector<size_t> temp;
			for(int j = N-1; j >= 0; --j)
				if(board[getIndex(j,i)])
					temp.push_back(board[getIndex(j,i)]);
			for(int j = N-1, index = 0; j >= 0; --j){
				if(index < temp.size())
					board[getIndex(j,i)] = temp[index];
				else
					board[getIndex(j,i)] = 0;
				++index;
			}
		}
	}
	for(size_t i = 0, index; i < N; ++i){
		for(size_t j = 0; j < 10; ++j){
			fout << board[getIndex(i,j)];
			++index;
		}
		fout << endl;
	}
}