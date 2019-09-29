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
	int L, R;
	cin >> L >> R;
	string ds;
	int digs[10] = {0}, ans = -1;
	bool ret = false;

	for(int i = L; i <= R; ++i){
		ds = to_string(i);
		for(auto &d : ds)
			++digs[d - '0'];
		ret = true;
		for(int j = 0; j < 10; ++j)
			if(digs[j] > 1)
				ret = false;
		if(ret)
			{cout << i << endl; return 0;};
		fill(all(digs), 0);
	}
	if(!ret)
		{cout << -1 << endl;};
}
//Keep It Simple, Stupid!