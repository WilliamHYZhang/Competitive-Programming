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
	int N, M;
	cin >> N >> M;
	int a[50][50];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			cin >> a[i][j];

	vector<pair<int, int>> ops;
	for(int i = 0; i < N-1; ++i){
		for(int j = 0; j < M-1; ++j){
			if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]){
				ops.pb(mp(i+1, j+1));
				++a[i][j]; ++a[i][j+1]; ++a[i+1][j]; ++a[i+1][j+1];
			}
			else if(a[i][j] == 1)
				{cout << -1 << endl; return 0;};
		}
	}

	for(int i = 0; i < M; ++i)
		if(a[N-1][i] == 1)
			{cout << -1 << endl; return 0;};
	for(int i = 0; i < N; ++i)
		if(a[i][M-1] == 1)
			{cout << -1 << endl; return 0;};
		
	cout << sz(ops) << endl;
	for(auto &op : ops)
		cout << op.f << " " << op.s << endl;
}
//Keep It Simple, Stupid!