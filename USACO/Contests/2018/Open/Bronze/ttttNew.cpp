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

int main(){
	ifstream fin("tttt.in");
	ofstream fout("tttt.out");
	int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,4,8}, {2,4,6}, {0,3,6}, {1,4,7}, {2,5,8}};
	string board = "";
	set<char> s1; set<pair<char, char>> s2;
	for(int i = 0; i < 3; ++i)
		{string row; fin >> row; board += row;}
	for(auto &win : wins){
		set<char> tmp;
		for(auto pos : win)
			tmp.insert(board[pos]);
		if(sz(tmp) == 1)
			s1.insert(*begin(tmp));
		else if(sz(tmp) == 2)
			s2.insert(mp(*begin(tmp), *++begin(tmp)));
	}
	fout << sz(s1) << endl << sz(s2) << endl;
}
//Keep It Simple, Stupid!