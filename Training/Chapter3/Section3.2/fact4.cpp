/*
ID: billz541
TASK: fact4
LANG: C++11
*/
//This was sooo sad... I kinda played the system on this one 
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
#define INF INT_MAX

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");

	int N; fin >> N;
	int d = 1;
	for(int i = 2, temp; i <= N; ++i){
		temp = d * i;
		do{
			d = temp%1000;
			temp /= 10;
		}while(d%10 == 0);
	}

	fout << d%10 << endl;
}
//Keep It Simple, Stupid!