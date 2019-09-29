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
	int a[2000], sA[2000];
	unordered_map<int, int> m;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		++m[a[i]];
	}

	copy(a, a+N, sA);
	sort(sA, sA+N);
	int cnt = 0;
	for(int i = 0; i < N-1; ++i)
		if(sA[i] == sA[i+1]) 
			++cnt;
	if(cnt == 0)
		{cout << 0 << endl; return 0;};

	for(int i = 1; i <= N; ++i){
		for(int j = 0; j < i; ++j){
			--m[a[j]];
			if(m[a[j]] > 0)
				--cnt;
		}
		if(cnt == 0)
			{cout << i << endl; return 0;};
		for(int j = 0; j < N-i; ++j){
			++m[a[j]];
			if(m[a[j]] > 1)
				++cnt;
			--m[a[j+i]];
			if(m[a[j+i]] > 0)
				--cnt;
			if(cnt == 0)
				{cout << i << endl; return 0;};
		}
		for(int j = N-i; j < N; ++j){
			++m[a[j]];
			if(m[a[j]] > 1)
				++cnt;
		}
	}
}
//Keep It Simple, Stupid!