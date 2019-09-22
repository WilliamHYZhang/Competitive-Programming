#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define INF INT_MAX
#define MOD 1000000007

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	int N;
	cin >> N;
	if(N%2 == 0)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		int a[200000];
		for(int n = 1, i = 0; n <= 2*N; n += 2){
			a[i] = n;
			a[(i+N)%(2*N)] = n + 1;
			i = (i+N-1)%(2*N);
		}
		for(int i = 0; i < 2*N; ++i)
			cout << a[i] << " ";
		cout << endl;
	}
}
//Keep It Simple, Stupid!