#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (size_t)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int INF = INT_MAX;
const int MOD = 1000000007;

int main(){
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
		int N, R;
		cin >> N >> R;
		set<pair<int, int>> e;
		for(int j = 0; j < N; ++j){
			int X;
			cin >> X;
			e.insert(mp(X, (X/R)*R == X ? X/R : X/R+1));
		}
		int ans = 0, cnt = 0;
		for(auto it = e.rbegin(); it != e.rend(); ++it, ++cnt){
			if(it->s > cnt)
				++ans;
			else
				break;
		}
		cout << ans <<endl;
	}
}
//Keep It Simple, Stupid!