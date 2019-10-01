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
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
		int N, tot = 0;
		cin >> N;
		for(int j = 0, g; j < N; ++j)
			{cin >> g; tot += g;};
		if(N*(tot/N) == tot)
			cout << tot/N << endl;
		else
			cout << (tot/N)+1 << endl;
	}
}
//Keep It Simple, Stupid!