/*
ID: billz541
TASK: concom
LANG: C++11
*/
//When you work on a problem for so long, solve it, and seconds later end up forgetting how it worked ¯\_(ツ)_/¯
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("concom.in");
	ofstream fout("concom.out");

	int own[101][101] = {0};
	set<int> coms;
	queue<int> q;
	int N;
	fin >> N;
	for(int i = 0, a, b, p; i < N; ++i){
		fin >> a >> b >> p;
		own[a][b] = p;
		coms.insert(a); 
		coms.insert(b);
	}

	for(auto &i : coms){
		for(auto &j : coms)
			if(own[i][j] > 50)
				q.push(j);
		while(q.size() != 0){
			int c = q.front();
			q.pop();
			for(auto &j : coms){
				if(own[c][j] > 0 && own[i][j] <= 50){
					own[i][j] += own[c][j];
					if(own[i][j] > 50)
						q.push(j);
				}
			}
		}
		for(auto &j : coms){
			if(i == j)
				continue;
			if(own[i][j] > 50)
				fout << i << " " << j << endl;
		}
	}
}
