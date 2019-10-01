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
	string s;
	cin >> s;
	map<char, set<int>> m;
	for(int i = 0; i < sz(s); ++i)
		m[s[i]].insert(i);

	int Q;
	cin >> Q;
	for(int i = 0, tQ; i < Q; ++i){
		cin >> tQ;
		if(tQ == 1){
			int pos;
			char c;
			cin >> pos >> c;
			--pos;	
			m[s[pos]].erase(pos);
			m[c].insert(pos);
			s[pos] = c;
		}
		else{
			int l, r;
			cin >> l >> r;
			--l; --r;
			int ans = 0;
			for(auto &let : m){
				auto it = let.s.lb(l);
				if(it != end(let.s) && *it <= r)
					++ans;
			}
			cout << ans << endl;
		}
	}
}
//Keep It Simple, Stupid!