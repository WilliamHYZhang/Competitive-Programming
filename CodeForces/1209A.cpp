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
	int N;
	cin >> N;
	multiset<int> a;
	vector<int> r;
	for(int i = 0, n; i < N; ++i)
		{cin >> n; a.insert(n);};

	int ans = 0, m, mN, tmpM;
	while(sz(a) > 0){
		m = 0;
		for(auto &n : a){
			tmpM = 0;
			for(auto &i : a)
				if(i%n == 0)
					++tmpM;
			if(tmpM > m)
				{m = tmpM; mN = n;};
		}

		for(auto &i : a)
			if(i%mN == 0)
				r.pb(i);
		for(auto &i : r)
			a.erase(i);
		r.clear();
		
		++ans;
	}

	cout << ans << endl;
}
//Keep It Simple, Stupid!