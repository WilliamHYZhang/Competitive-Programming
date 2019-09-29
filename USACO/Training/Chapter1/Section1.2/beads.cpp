/*
ID: billz541
TASK: beads
LANG: C++11
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int INF = INT_MAX;
const int MOD = 1000000007;

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int N;
	string b;
	fin >> N;
	fin >> b;

	int MAX = 0, tmpMAX = 0;
	char cur, nxt;
	for(int i = 0; i < N; ++i){
		tmpMAX = 2;
		for(int j = i, cur = b[j];; --j){
			nxt = j == 0 ? b[N-1] : b[j-1];
			if(j == 0) j = N;
			if(cur == 'w' && nxt != 'w') cur = nxt; 
			if(nxt == cur || nxt == 'w') ++tmpMAX;
			else break;
			if(tmpMAX > N) break;
		}
		for(int j = i+1 == N ? 0 : i+1, cur = b[j];; ++j){
			nxt = j == N-1 ? b[0] : b[j+1];
			if(j == N-1) j = -1;
			if(cur == 'w' && nxt != 'w') cur = nxt; 
			if(nxt == cur || nxt == 'w') ++tmpMAX;
			else break;
			if(tmpMAX > N) break;
		}
		MAX = max(MAX, min(tmpMAX, N));
	}
	fout << MAX << endl;
}
//Keep It Simple, Stupid!
