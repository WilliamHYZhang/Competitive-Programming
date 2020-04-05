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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case){
		int parens[101] = {};
		string str;
		cin >> str;
		string mem = str;
		bool ret = false;
		while(!ret){
			int i = 0;
			while(i < sz(str)){
				for(; i < sz(str)-1 && str[i] == '0'; ++i);
				if(str[i] != '0')
					--parens[i];
				else
					break;
				for(; i < sz(str) && str[i] != '0'; --str[i], ++i);
				++parens[i];
			}
			ret = true;
			for(auto &pos : str)
				if(pos != '0')
					{ret = false; break;}
		}
		cout << "Case #" << test_case << ": ";
		for(int i = 0; i <= sz(mem); ++i){
			for(int j = 0; j < abs(parens[i]); ++j)
				cout << (parens[i] < 0 ? '(' : ')');
			if(i != sz(mem))
				cout << mem[i];
		}
		cout << "\n";
	}
}
//Keep It Simple, Stupid!