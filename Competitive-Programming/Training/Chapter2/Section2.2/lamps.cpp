
/*
ID: billz541
TASK: lamps
LANG: C++11
*/
//BABY I'M BACK ON THE GRIND BOIS LET'S GET IT 6 MONTH BREAK ENDS TODAY
#include <bits/stdc++.h>
using namespace std;
void button(int a[100], bool all, bool even, bool odd, bool k){
	for(int i = 0; i < 100; ++i){
		if(all){
			a[i] = !a[i];
		}
		if(even)
			if((i+1)%2 == 0)
				a[i] = !a[i];
		if(odd)
			if((i+1)%2 == 1)
				a[i] = !a[i];
		if(k)
			if(i%3 == 0)
				a[i] = !a[i];
	}
}
int main(){
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");

	int N, C;
	fin >> N >> C;

	vector<int> on;
	vector<int> off;
	int lamp;
	fin >> lamp;
	while(lamp != -1){
		on.push_back(lamp);
		fin >> lamp;
	}
	fin >> lamp;
	while(lamp != -1){
		off.push_back(lamp);
		fin >> lamp;
	}

	int possibles[8][100];
	for(auto &possible : possibles)
		for(auto &state : possible)
			state = 1;

	button(possibles[0], true, false, false, false);
	button(possibles[1], false, true, false, true);
	button(possibles[2], false, false, true, false);
	button(possibles[3], false, false, false, true);
	button(possibles[4], true, false, false, true);
	button(possibles[5], false, true, false, false);
	button(possibles[6], false, false, true, true);

	bool isPossible = false;

	for(int i = 0; i < 8; ++i){
		if((C == 1 && (i == 1 || i == 4 || i == 6)) || (C == 0 && i != 7))
			continue;
		auto possible = possibles[i];
		bool print = true;
		for(auto &j : on)
			if(!possible[j-1])
				print = false;
		for(auto &j : off)
			if(possible[j-1])
				print = false;	
		if(print){
			isPossible = true;
			for(int i = 0; i < N; ++i)
				fout << possible[i];
			fout << endl;
		}
	}
	if(!isPossible)
		fout << "IMPOSSIBLE" << endl;
}