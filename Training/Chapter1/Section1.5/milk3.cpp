/*
ID: billz541
TASK: milk3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

size_t cA, cB, cC;
set<size_t> ans;
set<tuple<size_t, size_t, size_t>> seen;

void instances(size_t a, size_t b, size_t c){
	if(a == 0)
		ans.insert(c);
	if(seen.find(make_tuple(a,b,c)) != seen.end())
		return;
	seen.insert(make_tuple(a,b,c));
	if(a != 0){
		if(b != cB && a+b > cB)
			instances(a-(cB-b), cB, c);
		else if(b != cB && a+b <= cB)
			instances(0, a+b, c);
		if(c != cC && a+c > cC)
			instances(a-(cC-c), b, cC);
		else if(c != cC && a+c <= cC)
			instances(0, b, a+c);
	}
	if(b != 0){
		if(a != cA && b+a > cA)
			instances(cA, b-(cA-a), c);
		else if(a != cA && b+a < cA)
			instances(b+a, 0, c);
		if(c != cC && b+c > cC)
			instances(a, b-(cC-c), cC);
		else if(c != cC && b+c <= cC)
			instances(a, 0, b+c);
	}

	if(c != 0){
		if(a != cA && c+a > cA)
			instances(cA, b, c-(cA-a));
		else if(a != cA && c+a <= cA)
			instances(c+a, b, 0);
		if(b != cB && c+b > cB)
			instances(a, cB, c-(cB-b));
		else if(b != cB && c+b <= cB)
			instances(a, c+b, 0);
	}
}

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> cA >> cB >> cC;
	instances(0,0,cC);
	auto last = *ans.rbegin();
	for(auto &elem : ans){
		if(elem != last) fout << elem << " ";
		else fout << elem << endl;
	}
}