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

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

int main(){
	ifstream fin("piepie.in");
	ofstream fout("piepie.out");

	int N, D;
	fin >> N >> D;

	vector<pair<pair<int, int>, int>> b, eS; //value b/e, value b/e, min dist
	b.rsz(N); eS.rsz(N);
	for(int i = 0; i < N; ++i){
		fin >> b[i].f.s >> b[i].f.f;
		b[i].s = -1;
	}
	for(int i = 0; i < N; ++i){
		fin >> eS[i].f.f >> eS[i].f.s;
		eS[i].s = -1;
	}

	auto bS = b;
	sort(all(bS)); sort(all(eS));

	queue<pair<pair<int, int>, int>> q; // b/e 0/1, index, min dist
	for(int i = 0; i < N; ++i){
		if(bS[i].f.f == 0)
			q.push(mp(mp(0, i), 1));
		if(eS[i].f.f == 0)
			q.push(mp(mp(1, i), 1));
	}

	auto c1 = [](pair<pair<int, int>, int> &a, int b){return a.f.f < b;};
	pair<pair<int, int>, int> pie;
	vector<pair<pair<int, int>, int>>::iterator it;

	while(!q.empty()){
		pie = q.front();
		q.pop();

		if(!pie.f.f && bS[pie.f.s].s == -1){
			bS[pie.f.s].s = pie.s;
			for(it = lower_bound(all(eS), bS[pie.f.s].f.s - D, c1); it != end(eS) && it->f.f <= bS[pie.f.s].f.s; ++it)
				if(it->s == -1)
					q.push(mp(mp(1, int(it-begin(eS))), pie.s+1));
		}

		else if(pie.f.f && eS[pie.f.s].s == -1){
			eS[pie.f.s].s = pie.s;
			for(it = lower_bound(all(bS), eS[pie.f.s].f.s - D, c1); it != end(bS) && it->f.f <= eS[pie.f.s].f.s; ++it)
				if(it->s == -1)
					q.push(mp(mp(0, int(it-begin(bS))), pie.s+1));
		}
	}

	auto c2 = [](pair<pair<int,int>, int> a, pair<int, int> b){return a.f.f == b.f ? a.f.s < b.s : a.f.f < b.f;};
	for(auto &p : b)
		fout << lower_bound(all(bS), p.f, c2)->s << endl;
}
//Keep It Simple, Stupid!