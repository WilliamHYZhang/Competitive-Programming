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
	int T;
	cin >> T;
	int B, P, F, H, C;
	for(int i = 0; i < T; ++i){
		cin >> B >> P >> F >> H >> C;
		cout << (H > C ? min(P, B/2) * H + min(max(B/2 - P, 0), F) * C : min(F, B/2) * C + min(max(B/2 - F, 0), P) * H) << endl;
	}
}
//Keep It Simple, Stupid!