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

ll mpow(ll x, ll y){
	ll ret = 1;
	x = x%MOD;
	while(y > 0){
		if(y & 1)
			ret = (ret*x) % MOD;
		y >>= 1;
		x = (x*x) % MOD;
	}
	return ret;
}

ll fpow(ll x, ll y){
	ll ret = 1, tmp;
	while(y > 0){
		if(y & 1)
			ret = ret*x;
		y >>= 1;	
		x = x*x;
	}
	return ret;
}

int main(){
	ll X, N;
	cin >> X >> N;

	vector<ll> pfs;
	int n = X;
	if(n%2 == 0){
		pfs.pb(2);
		while(n%2 == 0)
			n = n/2;
	}
	for(int i = 3; i <= sqrt(n); i += 2){
		if(n%i == 0){
			pfs.pb(i);
			while(n%i == 0)
				n = n/i;
		}
	}
	if(n > 2)
		pfs.pb(n);

	ll k, tot, tmp, ans = 1;
	for(auto &pf : pfs){
		for(k = 0; fpow(pf, k) <= N; ++k) if(fpow(pf, k)*2LL > N) break;
		if(N/fpow(pf, k) == 0) --k;
		for(ll i = k, tot = 0, tmp = 0; i >= 0; --i){
			tmp = N/fpow(pf, i) - tot; 
			if(fpow(pf, i) < 0)
				tmp = N/ll(round(pow(pf, i))) - tot; //to prevent overflow using fpow, use regular pow and round (very crusty ik)
			tot += tmp;
			ans = (ans * mpow(mpow(pf, i), tmp)) % MOD;
		}
	}

	cout << ans << endl;
}
//Keep It Simple, Stupid!