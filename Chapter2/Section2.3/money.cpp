/*
ID: billz541
TASK: money
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int V, N;
long long mem[10001][25];
int coins[25];

long long compute(int n, int c){
	if(mem[n][c] == -1){
		mem[n][c] = 0;
		for(int i = c; i < V; ++i)
			if(n-coins[i] >= 0)
			  mem[n][c] += compute(n-coins[i], i);
	}
	return mem[n][c];
}

int main(){
	ifstream fin("money.in");
	ofstream fout("money.out");
	
	fin >> V >> N;
	for(int i = 0; i < V; ++i)
		fin >> coins[i];

	fill_n(mem[0], 25, 1);
	fill_n(mem[1], 10000*25, -1);
	
	fout << compute(N, 0) << endl;
}
