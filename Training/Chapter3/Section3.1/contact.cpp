/*
ID: billz541
TASK: contact
LANG: C++11
*/
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
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	map<string, int> pats; //patterns
	int A, B, N; fin >> A >> B >> N;
	string s, line;
	while(getline(fin, line))
		s += line;

	for(int i = 0; i < sz(s); ++i){
		line = "";
		for(int j = i; j < min(i+B, sz(s)); ++j){
			line += s[j];
			if(sz(line) >= A)
				++pats[line];
		}
	}

	set<pair<string, int>, function<bool(pair<string, int>, pair<string, int>)>> output(
		all(pats), [](pair<string, int> a, pair<string, int> b)
		{return a.s == b.s ? (sz(a.f) == sz(b.f) ? a.f < b.f : sz(a.f) < sz(b.f)) : (a.s > b.s);});

	auto it = output.begin();
	for(int i = 0; it != output.end() && i < N; ++i){
		auto pat = *it;
		if(pat.s < A) break;
		fout << pat.s << endl;
		int n = 0;
		while(it != output.end() && pat.s == (*it).s){
			fout << (*it).f; ++n;
			++it;
			if(n%6 == 0) fout << endl;
			else if(it != output.end() && pat.s == (*it).s) fout << " ";
		}
		if(n%6 != 0) fout << endl;
	}
}
//Keep It Simple, Stupid!