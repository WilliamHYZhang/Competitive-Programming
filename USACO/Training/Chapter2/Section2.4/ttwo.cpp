/*
ID: billz541
TASK: ttwo
LANG: C++11
*/
//I used 160,000 sized bool array w/ while true loop and breaks, compared to 160,000 iteration for loop in the analysis. 
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	int F[3], C[3]; //first 2 are x,y coords, last is dirs index
	int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // NESW
	bool obs[10][10] = {false}; //obstacles
	bool seen[10][10][10][10][4][4] = {false}; //first two are F coords, middle two are C coords, last two are F dir and C dir
	
	for(int i = 0; i < 10; ++i){
		string row; fin >> row;
		for(int j = 0; j < 10; ++j){
			if(row[j] == '*')
				obs[i][j] = true;
			else if(row[j] == 'C') 
				{C[0] = i; C[1] = j; C[2] = 0;}
			else if(row[j] == 'F')
				{F[0] = i; F[1] = j; F[2] = 0;}
		}
	}

	int ans = 0;
	while(true){
		if(seen[F[0]][F[1]][C[0]][C[1]][F[2]][C[2]])
			{fout << 0 << endl; break;}
		if(F[0] == C[0] && F[1] == C[1])
			{fout << ans << endl; break;}
		seen[F[0]][F[1]][C[0]][C[1]][F[2]][C[2]] = true;

		if((F[0] + dirs[F[2]][0] < 0 || F[0] + dirs[F[2]][0] > 9 || F[1] + dirs[F[2]][1] < 0 || F[1] + dirs[F[2]][1] > 9) || obs[F[0] + dirs[F[2]][0]][F[1] + dirs[F[2]][1]])
			F[2] = F[2] == 3 ? 0 : ++F[2];
		else
			{F[0] += dirs[F[2]][0]; F[1] += dirs[F[2]][1];}

		if((C[0] + dirs[C[2]][0] < 0 || C[1] + dirs[C[2]][1] < 0 || C[0] + dirs[C[2]][0] > 9 || C[1] + dirs[C[2]][1] > 9) || obs[C[0] + dirs[C[2]][0]][C[1] + dirs[C[2]][1]])
			C[2] = C[2] == 3 ? 0 : ++C[2];
		else
			{C[0] += dirs[C[2]][0]; C[1] += dirs[C[2]][1];}

		++ans;
	}
}
