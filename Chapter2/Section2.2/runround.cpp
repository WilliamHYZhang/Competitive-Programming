/*
ID: billz541
TASK: runround
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool isRunround(string num){
	bool seen[10] = {false};
	for(size_t i = 0; i < num.size(); ++i){
		if(seen[static_cast<size_t>(num[i])-48])
			return false;
		seen[static_cast<size_t>(num[i])-48] = true;
	}
	bool touched[num.size()] = {false};
	for(size_t i = 0, index = 0; i < num.size(); ++i){
		size_t dig = static_cast<size_t>(num[index])-48;
		index = (index + dig)%num.size();
		touched[index] = true;
	}
	for(size_t i = 0; i < num.size(); ++i)
		if(!touched[i])
			return false;
	return true;
}
int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	size_t N;
	fin >> N;
	
	while(true){
		if(isRunround(to_string(++N))){
			fout << N << endl;
			return 0;
		}
	}
}