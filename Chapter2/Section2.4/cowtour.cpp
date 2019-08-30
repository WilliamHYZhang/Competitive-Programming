/*
ID: billz541
TASK: cowtour
LANG: C++11
*/
//Very happy I solved this today, even if it took me forever. Had that aha! moment when I got the idea for line 104 :)
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

vector<vector<int>> fields;
int pastures[150][3]; //first two are x,y coords, last is 0/1 marker
double matrix[150][150];
double dist[150][150];
int N;

void DFS(vector<int> &field, int i){
	field.pb(i);
	pastures[i][2] = 1;
	for(int j = 0; j < N; ++j)
		if(!pastures[j][2] && matrix[i][j] != INT_MAX && matrix[i][j])
			DFS(field, j);
}


double FW(vector<int> &field){
	for(int i = 0; i < field.size(); ++i)
		for(int j = 0; j < field.size(); ++j)
			dist[field[i]][field[j]] = matrix[field[i]][field[j]];
	
	for(int k = 0; k < field.size(); ++k)
		for(int i = 0; i < field.size(); ++i)
			for(int j = 0; j < field.size(); ++j)
				if(dist[field[i]][field[k]] != INT_MAX &&
					dist[field[k]][field[j]] != INT_MAX &&
					dist[field[i]][field[k]] + dist[field[k]][field[j]] < dist[field[i]][field[j]])
					dist[field[i]][field[j]] = dist[field[i]][field[k]] + dist[field[k]][field[j]];

	double MAX = 0;
	for(int i = 0; i < field.size(); ++i)
		for(int j = 0; j < field.size(); ++j)
			MAX = max(dist[field[i]][field[j]], MAX);

	return MAX;
}

int main(){
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");

	fin >> N;
	for(int i = 0, x, y; i < N; ++i){
		fin >> x >> y;
		pastures[i][0] = x; pastures[i][1] = y;
		pastures[i][2] = 0;
	}

	for(int i = 0; i < N; ++i){
		string row; fin >> row;
		for(int j = 0; j < N; ++j){
			if(row[j]-'0')
				matrix[i][j] = sqrt(pow(pastures[i][0] - pastures[j][0], 2) + pow(pastures[i][1] - pastures[j][1], 2) * 1.0);
			else if(i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INT_MAX;
		}
	}

	for(int i = 0; i < N; ++i){
		if(!pastures[i][2]){
			vector<int> field;
			DFS(field, i);
			fields.pb(field);
		}
	}

	vector<double> MAXs;
	for(int i = 0; i < fields.size(); ++i)
		MAXs.pb(FW(fields[i]));

	double MIN = INT_MAX;
	for(int i = 0; i < fields.size()-1; ++i){
		for(int j = i+1; j < fields.size(); ++j){
			for(int k = 0; k < fields[i].size(); ++k){
				for(int l = 0; l < fields[j].size(); ++l){
					double iMAX = 0, jMAX = 0, 
					connect = sqrt(pow(pastures[fields[i][k]][0] - pastures[fields[j][l]][0], 2) + 
						pow(pastures[fields[i][k]][1] - pastures[fields[j][l]][1], 2) * 1.0);
					for(int m = 0; m < fields[i].size(); ++m)
						iMAX = max(dist[fields[i][k]][fields[i][m]], iMAX);
					for(int m = 0; m < fields[j].size(); ++m)
						jMAX = max(dist[fields[j][l]][fields[j][m]], jMAX);
					MIN = min(max({MAXs[i], MAXs[j], iMAX + jMAX + connect}), MIN);
				}
			}
		}
	}
	fout << fixed << setprecision(6) << MIN << endl;
}
//Keep It Simple, Stupid!
