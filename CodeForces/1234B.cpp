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
	int N, K;
	cin >> N >> K;
	deque<int> sc;
	set<int> co;
	for(int i = 0, id; i < N; ++i){
		cin >> id;
		if(co.find(id) == end(co)){
			if(sz(sc) == K){
				co.erase(sc.back());
				sc.pop_back();	
			}
			co.insert(id);
			sc.push_front(id);
		}
	}

	cout << sz(sc) << endl;
	for(auto &c : sc)
		cout << c << " ";
	cout << endl;
}
//Keep It Simple, Stupid!