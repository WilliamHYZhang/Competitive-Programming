/*
ID: billz541
TASK: castle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//could make this shorter... but eh lmao first real IOI problem let's get it bois

size_t M, N; // column size (width) and row size (height)
size_t floorplan[2500][4]; // 2d array of each module with 4 1s or 0s denoting if exists a wall S,E,N,W
size_t seen[2500] = {0}; //array of 0 or 1, not seen or seen module when finding room size
size_t maxRow, maxColumn, maxDir /* 1 if N, 0 if E */ , maxSize = 0;

size_t getIndex(size_t row, size_t column){
	return row*M + column; //returns index in floorplan for row and column, avoids using map
}

size_t findRoomSize(int row, int column, size_t seen[]){
	size_t index = getIndex(row, column);
	if(row == -1 || column == -1 || row == N || column == M) return 0;
	else if(seen[index]) return 0;
	seen[index] = 1;
	size_t west = floorplan[index][3] ? 0 : findRoomSize(row, column-1, seen);
	size_t north = floorplan[index][2] ? 0 : findRoomSize(row-1, column, seen);
	size_t east = floorplan[index][1] ? 0 : findRoomSize(row, column+1, seen);
	size_t south = floorplan[index][0] ? 0 : findRoomSize(row+1, column, seen);
	return 1 + west + north + east + south;
}

size_t updateMax(size_t size, size_t row, size_t column, size_t dir){
	bool update = false;
	if(size > maxSize) update = true;
	else if(size == maxSize){
		if(column < maxColumn) update = true;
		else if(column == maxColumn)
			if(row > maxRow) update = true;
	}

	if(update){
		maxRow = row;
		maxColumn = column;
		maxDir = dir;
		maxSize = size;
	}
}
int main(){
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> M >> N;
	for(size_t i = 0, dn; i < M*N; ++i){
		fin >> dn;
		for(size_t j = 0, wn = 8; j < 4; ++j){
			if(dn >= wn){
				floorplan[i][j] = 1;
				dn -= wn;
			}
			else floorplan[i][j] = 0;
			wn /= 2;
		}
	}

	vector<size_t> rooms;
	size_t singleMax;
	for(size_t i = 0; i < N; ++i){
		for(size_t j = 0; j < M; ++j){
			if(seen[getIndex(i ,j)]) continue;
			size_t size = findRoomSize(i, j, seen);
			rooms.push_back(size);
			if(size > singleMax) singleMax = size;
		}
	}

	for(size_t i = 0; i < N; ++i){
		for(size_t j = 0; j < M; ++j){
			size_t index = getIndex(i ,j);	
			if(!floorplan[index][2] && !floorplan[index][1]) continue;
			if(floorplan[index][2]){
				size_t tempSeen1[2500] = {0};
				floorplan[index][2] = 0;
				updateMax(findRoomSize(i, j, tempSeen1), i, j, 1);
				floorplan[index][2] = 1;
			}
			if(floorplan[index][1]){
				size_t tempSeen2[2500] = {0};
				floorplan[index][1] = 0;
				updateMax(findRoomSize(i, j, tempSeen2), i, j, 0);
				floorplan[index][1] = 1;
			}
		}
	} 

	char NE = maxDir ? 'N' : 'E';
	fout << rooms.size() << endl << singleMax << endl << maxSize << endl << maxRow+1 << " " << maxColumn+1 << " " << NE << endl;
}