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

ll grid[100][100];
int dirs[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

bool is_elim(int i, int j, int r, int c){
	int sum = 0, n = 4;
	for(auto &dir : dirs){
		int ti = i, tj = j;
		while(1){
			ti += dir[0];
			tj += dir[1];
			if(ti >= 0 && ti < r && tj >= 0 && tj < c){
				if(grid[ti][tj]){
					sum += grid[ti][tj];
					break;
				}
			}
			else{
				--n;
				break;
			}
		}
	}
	return grid[i][j]*n < sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case){
		int R, C;
		cin >> R >> C;
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				cin >> grid[i][j];
		ll ans = 0;
		while(1){
			vector<pair<int, int>> elims;
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j){
					if(grid[i][j] && is_elim(i, j, R, C))
						elims.pub(mp(i,j));
					ans += grid[i][j];
				}
			}
			if(!sz(elims))
				break;
			for(auto &elim : elims)
				grid[elim.f][elim.s] = 0;
		}
		cout << "Case #" << test_case << ": " << ans << "\n";
	}
}
//Keep It Simple, Stupid!