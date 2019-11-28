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
#define ins insert
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (size_t)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int MOD = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

int cows[100000];
ordered_set<int> sorted;

int main(){
	//USACO
	ifstream fin("sleepy.in");
	fin.sync_with_stdio(false);
	fin.tie(NULL);
	ofstream fout("sleepy.out");

	int N;
	fin >> N;
	for(int i = 0; i < N; ++i)
		fin >> cows[i];

	int K = 0;
	for(int i = N-1; i >= 1; --i){
		sorted.ins(cows[i]);
		if(cows[i] < cows[i-1]){
			K = i;
			break;
		}
	}

	fout << K << endl;
	int tmp = K;
	for(int i = 0; i < K; ++i){
		sorted.ins(cows[i]);
		fout << --tmp + sorted.ook(cows[i]);
		if(i != K-1)
			fout << " ";
	}
	fout << endl;
}
/*
Keep It Simple, Stupid!
Caution:
- integer overflow (check num constraints)
- segfault (check array / other ds bounds)
- special / edge cases
Stay organized and think before you type.
*/