#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

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
	ifstream fin("hoofball.in");
	ofstream fout("hoofball.out");

	int N;
	fin >> N;

	vector<int> cows(N);
	for(int i = 0; i < N; ++i)
		fin >> cows[i];

	sort(all(cows));

	vector<vector<int>> ball(N);
	for(int i = 0; i < N; ++i){
		if(i == 0)
			ball[i+1].pb(i);
		else if(i == N-1)
			ball[i-1].pb(i);
		else
			ball[(cows[i+1]-cows[i]) < (cows[i]-cows[i-1]) ? i+1 : i-1].pb(i);	
	}

	int ans = sz(ball[0]) ? 0 : 1;
	for(int i = 1; i < N; ++i)
		if((!sz(ball[i])) || (sz(ball[i]) == 1 && sz(ball[i-1]) == 1 && ball[i][0] == i-1 && ball[i-1][0] == i))
			++ans;

	fout << ans << endl;
}
//Keep It Simple, Stupid!