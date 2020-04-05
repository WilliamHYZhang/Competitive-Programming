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
		vector<pair<pair<int, int>, int>> times;
		int N;
		cin >> N;
		for(int i = 0, a, b; i < N; ++i){
			cin >> a >> b;
			times.pub(mp(mp(a, b), i));
		}
		sort(all(times));
		vector<pair<int, char>> ret;
		int c = 0, j = 0;
		bool works = true;
		for(auto &time : times){
			if(time.f.f >= c){
				ret.pub(mp(time.s,'C'));
				c = time.f.s;
			}
			else if(time.f.f >= j){
				ret.pub(mp(time.s, 'J'));
				j = time.f.s;
			}
			else{
				works = false;
				break;
			}
		}
		sort(all(ret));
		string ans;
		for(auto &time : ret)
			ans += time.s;
		cout << "Case #" << test_case << ": " << (works ? ans : "IMPOSSIBLE") << "\n";
	}
}
//Keep It Simple, Stupid!