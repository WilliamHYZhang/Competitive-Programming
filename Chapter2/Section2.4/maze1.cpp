/*
ID: billz541
TASK: maze1
LANG: C++11
*/
//♫ Hey, how you doing? Well I'm doing just fine / I lied I'm dying inside ♫
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int main(){
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	bool maze[100][38][4];
	fill_n(**maze, 38*100*4, true);
	int steps[100][38];
	fill_n(*steps, 38*100, 38*100 /*max number of steps*/);
	int exit1[2] = {-1}, exit2[2];
	int W, H, y, x, dir; fin >> W >> H;
	fin.ignore();

	for(int i = 0; i < 2*H+1; ++i){
		string row;
		getline(fin, row);
		for(int j = 0; j < 2*W+1; ++j){
			if(row[j] == '-'){
				y = i/2; x = (j-1)/2;
				if(y-1 >= 0)
					maze[y-1][x][2] = false;	
				if(y < H)
					maze[y][x][0] = false;
			}
			if(row[j] == '|'){
				y = (i-1)/2; x = j/2;
				if(x-1 >= 0)
					maze[y][x-1][1] = false;
				if(x < W)
					maze[y][x][3] = false;
			}

			if(row[j] == ' '){
				if(i == 0)
					{y = i/2; x = (j-1)/2; dir = 0;}
				else if(i == 2*H)
					{y = i/2-1; x = (j-1)/2; dir = 2;}
				else if(j == 0)
					{y = (i-1)/2; x = j/2; dir = 3;}
				else if(j == 2*W)
					{y = (i-1)/2; x = j/2-1; dir = 1;}
				else
					continue;

				if(exit1[0] == -1)
					{exit1[0] = y; exit1[1] = x;}
				else
					{exit2[0] = y; exit2[1] = x;}
				maze[y][x][dir] = false;
			}
		}
	}

	queue<pair<pair<int,int>, int>> q; 
	//first two are x & y coords, last is step count. spoiler: don't recommend this :( 
	//DON'T USE C-STYLE ARRAY or else feel the wrath of pointers
	q.push(mp(mp(exit1[0], exit1[1]), 1));

	for(int i = 0; i < 2; ++i){
		while(q.size() != 0){
			auto cur = q.front();
			q.pop();
			if(steps[cur.f.f][cur.f.s] > cur.s){
				steps[cur.f.f][cur.f.s] = cur.s;
				++cur.s;
				if(maze[cur.f.f][cur.f.s][0])
					{--cur.f.f; q.push(cur); ++cur.f.f;}
				if(maze[cur.f.f][cur.f.s][1])
					{++cur.f.s; q.push(cur); --cur.f.s;}
				if(maze[cur.f.f][cur.f.s][2])
					{++cur.f.f; q.push(cur); --cur.f.f;}
				if(maze[cur.f.f][cur.f.s][3])
					{--cur.f.s; q.push(cur); ++cur.f.s;}
			}
		}
		q.push(mp(mp(exit2[0], exit2[1]), 1));
	}

	int MAX = 0;
	for(int i = 0; i < H; ++i)
		for(int j = 0; j < W; ++j)
			MAX = max(steps[i][j], MAX);
	
	fout << MAX << endl;
}
//Keep It Simple, Stupid!