#include <iostream>
#include <fstream>
using namespace std;

int main(){
	//cout << "starting" << endl;
	ifstream fin("outofplace.in");
	size_t posSize;
	fin >> posSize;
	size_t positions[posSize];
	for(size_t i = 0; i < posSize; ++i)
		fin >> positions[i];

	size_t bessieIndex;
	if(positions[0] > positions[1]) 
		bessieIndex = 0;
	else if(positions[posSize-1] < positions[posSize-2]) 
		bessieIndex = posSize-1;
	else{
		for(size_t i = 1; i < posSize-1; ++i){
			if((positions[i-1] < positions[i] && positions[i] > positions[i+1]) && positions[i-1] <= positions[i+1] || (positions[i-1] > positions[i] && positions[i] < positions[i+1] && positions[i-1] <= positions[i+1])){
				bessieIndex = i;
				break;
			}
		}
	}
	size_t bessie = positions[bessieIndex];

	//cout << "bessie and bessie index found" << endl;
	//cout << "bessie is " << bessie << endl;

	size_t end = 0;
	for(size_t i = 0; i < posSize; ++i){
		if(bessie < positions[i]){
			if(i < bessieIndex)
				end = i;
			else{
				for(size_t j = i-1; j > 0; --j){
					if(positions[j] != bessie){
						end = j;
						break;
					}
				}
			}
		}
		if(end != 0) break;
	}
	
	//cout << "end found" << endl;
	//cout << "end is" << end << endl;

	size_t swaps;
	if(bessieIndex < end){
		swaps = end - bessieIndex;
		for(size_t i = bessieIndex+1; i < end; ++i)
			if(positions[i] == positions[i+1]) --swaps;
	}
	else{
		swaps = bessieIndex - end;
		for(size_t i = bessieIndex-1; i > end; --i)
			if(positions[i] == positions[i-1]) --swaps;
	}

	//cout << "answer found" << endl;
	ofstream fout("outofplace.out");
	fout << swaps << endl;
	//cout << swaps << endl;
}
