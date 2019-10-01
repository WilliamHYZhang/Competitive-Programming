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
		int N;
		cin >> N;
		string R1, R2;
		cin >> R1 >> R2;
		int swc = 0, lvl = 0;
		bool ans = true;
		for(int j = 0; j < N; ++j){
			if((R1[j] - '0') >= 3 && (R2[j] - '0') >= 3)
				{++swc; lvl = !lvl;}
			else if(!lvl ? (R1[j] - '0') >= 3 : (R2[j] - '0') >= 3)
				ans = false;
		}
		if(swc%2 == 0)
			ans = false;

		cout << (ans ? "YES" : "NO") << endl;
	}
}
//Keep It Simple, Stupid!