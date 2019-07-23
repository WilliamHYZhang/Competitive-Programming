/*
ID: billz541
TASK: prefix
LANG: C++11
*/
//
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	vector<string> prims;
	string seq = "";
	string prim;
	fin >> prim;
	while(prim != "."){
		prims.push_back(prim);
		fin >> prim;
	}
	string temp;
	while(true){
		fin >> temp;
		if(fin.eof())
			break;
		seq+=temp;
	}

	bool seen[seq.size()+1] = {false};
	stack<int> simStack;
	simStack.push(0);
	int ans = 0;

	while(simStack.size() != 0){
		int i = simStack.top();
		simStack.pop();
		seen[i] = true;
		for(auto prim : prims){
			string s = "";
			for(int j = i; j < min(seq.size(), i+prim.size()); ++j){
				s += seq[j];
			}
			if(prim == s){
				if(!seen[i+prim.size()])
					simStack.push(i+prim.size());		
			}
		}
		
		if(ans < i)
			ans = i;
	}

	fout << ans << endl;
}