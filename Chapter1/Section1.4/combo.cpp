/*
ID: billz541
TASK: combo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

vector<int> makeRange(int val, int num){
	vector<int> returnVal;
	for(int i = -2; i <= 2; ++i){
		int current = val + i;
		if(1 <= current && current <= num) returnVal.push_back(current);
		else if(current > num){
			while(current > num) current -= num;
			returnVal.push_back(current);
		}
		else{
			while(current < 1) current += num;
			returnVal.push_back(current);
		}
	}
	return returnVal;
}

void addCombos(set<tuple<int, int, int>> &combos, tuple<int, int, int> &key, int num){
	for(auto range1 : makeRange(get<0>(key), num)){
		for(auto range2 : makeRange(get<1>(key), num)){
			for(auto range3 : makeRange(get<2>(key), num)){
				combos.insert(make_tuple(range1, range2, range3));
			}
		}
	}
}

int main(){
	ifstream fin("combo.in");
	int num, farmer1, farmer2, farmer3, master1, master2, master3;
	fin >> num >> farmer1 >> farmer2 >> farmer3 >> master1 >> master2 >> master3;
	tuple<int, int, int> farmer = make_tuple(farmer1, farmer2, farmer3);
	tuple<int, int, int> master = make_tuple(master1, master2, master3);
	set<tuple<int, int, int>> combos;
	addCombos(combos, farmer, num);
	addCombos(combos, master, num);
	ofstream fout("combo.out");
	fout << combos.size() << endl;	
}