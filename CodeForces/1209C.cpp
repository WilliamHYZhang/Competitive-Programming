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
	int T; cin >> T;

	for(int i = 0; i < T; ++i){
		int N; cin >> N;
		string str; cin >> str;
		int dig[10] = {0};
		for(auto &c : str)
			++dig[c-'0'];

		string ans(N, '2');
		for(int j = 0, in = 0; in < N && j < 10; ++j){
			for(int k = 0; in < N && k < dig[j]; ++in){
				if(str[in]-'0' == j) 
					{++k; ans[in] = '1';}
			}
		}
		bool sol = true;
		for(int j = 0, prev = -1; j < N; ++j){
			if(ans[j] == '2'){ 
				if(prev > str[j]-'0')
					{sol = false; break;}
				else
					prev = str[j]-'0';
			}
		}

		if(sol)
			cout << ans << endl;
		else
			cout << "-" << endl;
	}
}
//Keep It Simple, Stupid!