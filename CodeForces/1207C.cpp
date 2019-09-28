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
	ll N, A, B, ans, cnt;
	string road;
	for(int i = 0; i < T; ++i){
		cin >> N >> A >> B;
		cin >> road;
		
		for(int j = 1; j < N-1; ++j)
			if(road[j-1] == '1' && road[j] == '0' && road[j+1] == '1')
				road[j] = '1';

		ans = 2*B;
		for(int j = 0; j < N; ++j){
			cnt = 1;
			while(j < N-1 && road[j] == road[j+1])
				{++cnt; ++j;};
			if(cnt == N)
				ans += cnt*A + (cnt-1)*B;	
			else if(j-cnt == -1 || j == N-1)
				ans += (cnt+1)*A + (cnt-1)*B;	
			else
				road[j] == '1' ? ans += cnt*A + 2*(cnt+1)*B : ans += min(cnt*A + 2*(cnt-1)*B, (cnt+2)*A + (cnt-1)*B);		
		}
		cout << ans << endl;
	}
}
//Keep It Simple, Stupid!