/*
ID: billz541
TASK: nocows
LANG: C++11
*/
//this was a big F in the chat
#include <bits/stdc++.h>
using namespace std;

int mem[201][100]; //num(ber of nodes), depth

int recurse(int num, int depth){
	if(mem[num][depth] == -1){
		if(num == 0 || depth == 0)
			if(num == 0 && depth == 0)
				mem[num][depth] = 1;
			else
				mem[num][depth] = 0;
		else{
			int ret = 0;
			for(int i = 0, j = num-2; i < num; i += 2, j -= 2){
				for(int di = i == 0 ? 0 : (int)ceil(log(i+1)/log(2))-1, maxi = min(i/2, depth-1); di <= maxi; ++di){
					for(int dj = j == 0 ? 0 : (int)ceil(log(j+1)/log(2))-1, maxJ = min(j/2, depth-1); dj <= maxJ; ++dj){
						if(di == depth-1 || dj == depth-1){
							int add = recurse(i, di) * recurse(j, dj);
							ret = (ret + add) % 9901;
						}
					}
				}
			}
			mem[num][depth] = ret;
		}
	}
	return mem[num][depth];
}
int main(){
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");

	int N, K;
	fin >> N >> K;

	if(N%2 == 0){
		fout << 0 << endl;
		return 0;
	}
	
	fill_n(*mem, 20000, -1);

	fout << recurse(N-1, K-1) << endl;
}