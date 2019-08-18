/*
ID: billz541
TASK: zerosum
LANG: C++11
*/
//not at all elegant :( but it works
#include <bits/stdc++.h>
using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int N;

void permute(vector<int> ops){
	if(ops.size() != N-1){
		ops.push_back(0);
		permute(ops);
		ops.pop_back();

		ops.push_back(1);
		permute(ops);
		ops.pop_back();

		ops.push_back(-1);
		permute(ops);
		ops.pop_back();
	}

	else{
		int sum = 1, n = 1, c;
		auto it = ops.begin();
		while(it != ops.end()){
			auto op = *it;
			if(op != 0){
				c = ++n;
				while(++it != ops.end()){
					if(*it == 0)
						c = c*10 + ++n;
					else
						break;
				}
				if(op == -1)
					sum -= c;
				else
					sum += c;
			}
			else{
				sum = sum*10 + ++n;
				++it;
			}
		}

		if(sum == 0){
			n = 1;
			fout << 1;
			for(auto &op : ops){
				if(op == 0)
					fout << " ";
				else if(op == 1)
					fout << "+";
				else
					fout << "-";
				fout << ++n;
			}
			fout << endl;
		}
	}
}

int main(){
	

	fin >> N;
	vector<int> ops;
	permute(ops);
}