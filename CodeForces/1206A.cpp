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
	int N, M;
	int a[100], b[100];
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	cin >> M;
	for(int i = 0; i < M; ++i)
		cin >> b[i];

	sort(a, a + N);
	sort(b, b + M);

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(!binary_search(a, a + N, a[i] + b[j]) && !binary_search(b, b + M, a[i] + b[j])){
				cout << a[i] << " " << b[j] << endl;
				return 0;
			}
		}
	}

}
//Keep It Simple, Stupid!