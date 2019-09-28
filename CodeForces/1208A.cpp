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
	int A, B, N;
	bitset<31> bA, bB, bN;
	int pat[3] = {0, 1, 1};
	for(int i = 0; i < T; ++i){
		cin >> A >> B >> N;
		bA = A; bB = B;
		for(int j = 0; j < 31; ++j){
			if(!bA[j] && !bB[j])
				bN[j] = 0;
			else if(!bA[j] && bB[j])
				bN[j] = pat[N%3];
			else if(bA[j] && !bB[j])
				bN[j] = pat[(N-1)%3];
			else
				bN[j] = pat[(N-2)%3];
		}
		cout << bN.to_ullong() << endl;
	}
}
//Keep It Simple, Stupid!