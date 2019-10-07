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

map<vector<int>, ll> ss;

void gsub(vector<int> &sub, int in, int flav[5]){
	++ss[sub];
	if(in < 4){
		for(int i = in+1; i < 5; ++i){
			sub.pub(flav[i]);
			gsub(sub, i, flav);
			sub.pob();
		}
	}
}
int main(){
	ifstream fin("cowpatibility.in");
	ofstream fout("cowpatibility.out");

	ll N;
	fin >> N;
	for(int i = 0; i < N; ++i){
		int flav[5];
		for(int j = 0; j < 5; ++j)
			fin >> flav[j];
		sort(all(flav));
		for(int j = 0; j < 5; ++j){
			vector<int> sub = {flav[j]};
			gsub(sub, j, flav);
		}
	}

	ll ans = (N*(N-1))/2;
	for(auto &sub : ss){
		if(sz(sub.f)%2 == 1)
			ans -= (sub.s*(sub.s-1))/2;
		else
			ans += (sub.s*(sub.s-1))/2;
	}

	fout << ans << endl;
}
//Keep It Simple, Stupid!