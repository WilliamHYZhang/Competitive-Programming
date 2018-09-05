#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int log[100];
	ifstream fin("taming.in");
	ofstream fout("taming.out");

	size_t num;
	fin >> num;
	for(size_t i = 0; i < num; ++i) fin >> log[i];
	log[0] = 0;
	size_t seen = 0;
	for(size_t i = 1; i < num; ++i){
		if(log[i] > 0){
			for(int j = i-1, current = log[i]-1; j > seen && current >= 0; --j, --current){
				if(log[j] != -1 && log[j] != current){
					fout << "-1" << endl;
					return 0;
				}
				log[j] = current;
			}
			seen = i-1;
		}
	}

	size_t minBreak = 0, maxBreak = 0;
	for(size_t i = 0; i < num; ++i){
		if(log[i] == 0) {++minBreak; ++maxBreak;};
		if(log[i] == -1) ++maxBreak;
	}
	fout << minBreak << " " << maxBreak << endl;
}