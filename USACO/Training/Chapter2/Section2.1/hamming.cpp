/*
ID: billz541
TASK: hamming
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> codes;
vector<string> binAns;
size_t N, B, D;

void createCodes(string current){
	if(current.size() == B){
		codes.push_back(current);
		return;
	}
	createCodes(current+'0');
	createCodes(current+'1');
}

bool isHam(string a, string b){
	size_t ans = 0;
	for(size_t i = 0; i < a.size(); ++i)
		if(a[i] != b[i])
			++ans;
	return ans >= D;
}

int main(){
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	fin >> N >> B >> D;
	createCodes("");
	binAns.push_back(codes[0]);
	for(size_t i = 0; i < codes.size(); ++i){
		bool add = true;
		for(size_t j = 0; j < binAns.size(); ++j){
			if(!isHam(codes[i], binAns[j])){
				add = false;
				break;
			}
		}
		if(add)
			binAns.push_back(codes[i]);
		if(binAns.size() == N)
			break;
	}

	for(size_t i = 0; i < N; ++i){
		auto ans = stoull(binAns[i], 0, 2);
		fout << ans;
		if((((i+1)%10 == 0) && i != 0) || i == N-1)
			fout << endl;
		else
			fout << " ";
	}
}