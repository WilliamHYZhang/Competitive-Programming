/*
ID: billz541
TASK: barn1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

vector<size_t> stallNums;

tuple<size_t, size_t, size_t> biggestSpace(size_t a, size_t b){
	size_t tempEndA = 0, endA = 0, startB = 0, maximumSpace = 0, space = 0;
	for(size_t i = a; i <= b; ++i){
		if(find(stallNums.begin(), stallNums.end(), i) == stallNums.end()){
			space += 1;
			if(space == 1)
				tempEndA = i-1;
		}
		else{
			if(space > maximumSpace){
				startB = i;
				endA = tempEndA;
				maximumSpace = space;
			}
			space = 0;
		}
	}
	return make_tuple(endA, startB, maximumSpace);
}

int main(){
	ifstream in("barn1.in");
	size_t maxBoards, numOfStalls, numOfCows;
	in >> maxBoards >> numOfStalls >> numOfCows;
	size_t stallNum;
	for(size_t i = 0; i < numOfCows; ++i){
		in >> stallNum;
		stallNums.push_back(stallNum);
	}
	sort(stallNums.begin(), stallNums.end());
	vector<pair<size_t, size_t>> boards;
	boards.push_back(make_pair(stallNums[0], stallNums[stallNums.size()-1]));
	for(size_t numOfBoards = 1; numOfBoards < maxBoards; ++numOfBoards){
		auto currentMax = make_tuple(0,0,0);
		auto removeBoard = make_pair(0,0);
		size_t index = 0, tempIndex = 0;
		for(auto const &board : boards){
			auto temp = biggestSpace(board.first, board.second);
			if(get<2>(temp) > get<2>(currentMax)){
				currentMax = temp;
				removeBoard = board;
				index = tempIndex;

			}
			tempIndex += 1;
		}
		if(get<2>(currentMax) == 0)
			break;
		boards.erase(boards.begin()+index);
		boards.push_back(make_pair(removeBoard.first, get<0>(currentMax)));
		boards.push_back(make_pair(get<1>(currentMax), removeBoard.second));
	}

	ofstream out("barn1.out");
	size_t covered = 0;
	for(auto const &board : boards)
		covered += board.second-board.first+1;
	out << covered << endl;;
}