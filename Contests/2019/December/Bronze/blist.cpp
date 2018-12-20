#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ifstream fin("blist.in");
	ofstream fout("blist.out");
	size_t N;
	fin >> N;
	size_t cows[N][3];
	for(size_t i = 0; i < N; ++i)
		fin >> cows[i][0] >> cows[i][1] >> cows[i][2];

	size_t total = 0, avaliable = 0;

	for(size_t i = 1; i <= 1000; ++i){
		for(size_t j = 0; j < N; ++j){
			if(cows[j][0] == i){
				if(avaliable >= cows[j][2]){
					avaliable -= cows[j][2];
				}
				else{
					total += cows[j][2] - avaliable;
					avaliable = 0;
				}
			}
			if(cows[j][1] == i){
				avaliable += cows[j][2];
			}
		}
	}
	fout << total << endl;
}