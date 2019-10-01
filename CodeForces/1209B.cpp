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
	string l;
	cin >> l;
	int a[100], b[100];
	for(int i = 0; i < N; ++i)
		cin >> a[i] >> b[i];

	int ans = 0;
	for(int i = 0; i < 1000; ++i){
		int tmp = 0;
		for(int j = 0; j < N; ++j){
			if(i >= b[j] && (i-b[j]) % a[j] == 0)
				l[j] == '1' ? l[j] = '0' : l[j] = '1';
			if(l[j] == '1')
				++tmp;
		}
		ans = max(ans, tmp);
	}

	cout << ans << endl;
}
//Keep It Simple, Stupid!