/*
ID: billz541
TASK: fracdec
LANG: C++11
*/
//Why have us output 76 characters per line? Made the code much more ugly >:(
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

int main(){
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	int N, D;
	fin >> N >> D;

	vector<int> dec;
	int b = -1, cp = 0, rem = N, q; //b: bracket, cp current point, rem: remainder, q: quotient
	map<int, int> seen;

	while(1){
		q = rem/D;
		rem = (rem - q*D)*10;
		dec.pb(q);
		++cp;
		if(!seen.insert(mp(rem, cp)).s)
			{b = seen[rem]; break;}
		if(rem == 0)
			break;
	}

	fout << dec[0];
	int cc = to_string(dec[0]).length(); //character count
	if(dec.size() == 1)
		{fout << ".0" << endl; return 0;}
	for(int i = 1; i < dec.size(); ++i){
		if(i == 1)
			{fout << "."; ++cc;}
		if(i == b)
			{if(cc%76 == 0) fout << endl; fout << "("; ++cc;}
		if(cc%76 == 0) fout << endl;
		fout << dec[i];
		++cc;
	}
	if(b != -1)
		{if(cc%76 == 0) fout << endl; fout << ")";}
	fout << endl;
}
//Keep It Simple, Stupid!