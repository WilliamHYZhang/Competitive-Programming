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
	int H, W;
	cin >> H >> W;
	int r[1000], c[1000], grid[1000][1000] = {0};
	for(int i = 0; i < H; ++i)
		cin >> r[i];
	for(int i = 0; i < W; ++i)
		cin >> c[i];

	for(int i = 0; i < H; ++i)
		for(int j = 0; j < r[i]; ++j)
			grid[i][j] = 1;
	for(int i = 0; i < W; ++i)
		for(int j = 0; j < c[i]; ++j)
			grid[j][i] = 1;
	
	for(int i = 0, cnt = 0; i < H; ++i, cnt = 0){
		for(int j = 0; j < W; ++j)
			{if(grid[i][j]) ++cnt; else break;};
		if(cnt > r[i])
			{cout << 0 << endl; return 0;};
	}
	for(int i = 0, cnt = 0; i < W; ++i, cnt = 0){
		for(int j = 0; j < H; ++j)
			{if(grid[j][i]) ++cnt; else break;};
		if(cnt > c[i])
			{cout << 0 << endl; return 0;};
	}

	int cnt = 0;
	for(int i = 0; i < H; ++i)
		for(int j = r[i]+1; j < W; ++j)
			if(!grid[i][j] && i > c[j]) ++cnt;
	
	ll ans = 1;
	for(int i = 0; i < cnt; ++i)
		ans = (ans*2)%MOD;

	cout << ans << endl;
}
//Keep It Simple, Stupid!