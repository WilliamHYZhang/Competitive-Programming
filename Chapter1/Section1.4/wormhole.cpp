/*
ID: billz541
TASK: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

vector<vector<pair<pair<size_t,size_t>,pair<size_t,size_t>>>> pairCombos;

void generateCombos(const pair<vector<pair<pair<size_t,size_t>, pair<size_t,size_t>>>, vector<pair<size_t,size_t>>> &currentAndLeftover){
	if(currentAndLeftover.second.size() == 0) pairCombos.push_back(currentAndLeftover.first);
	else{
		for(size_t i = 1; i < currentAndLeftover.second.size(); ++i){
			auto current = currentAndLeftover.first;
			auto leftover = currentAndLeftover.second;
			auto pair1 = leftover[0];
			auto pair2 = leftover[i];
			current.push_back(make_pair(pair1, pair2));
			leftover.erase(leftover.begin()+i);
			leftover.erase(leftover.begin()+0);
			generateCombos(make_pair(current, leftover));
			current.pop_back();
			leftover.insert(leftover.begin(), pair1);
			leftover.insert(leftover.begin()+i, pair2);
		}
	}
}

bool simulateCycle(tuple<vector<pair<pair<size_t,size_t>,pair<size_t,size_t>>>,pair<size_t, size_t>, vector<pair<size_t, size_t>>> &comboPairSeen){
	pair<pair<size_t,size_t>,pair<size_t,size_t>> closest;
	closest.first = make_pair(1000000001,get<1>(get<1>(comboPairSeen)));
	for(const auto pair : get<0>(comboPairSeen)){
		if(get<1>(get<0>(pair)) == get<1>(get<1>(comboPairSeen)) && get<0>(get<0>(pair)) > get<0>(get<1>(comboPairSeen)) && get<0>(get<0>(pair)) < get<0>(get<0>(closest)))
			closest = pair;
		if(get<1>(get<1>(pair)) == get<1>(get<1>(comboPairSeen)) && get<0>(get<1>(pair)) > get<0>(get<1>(comboPairSeen)) && get<0>(get<1>(pair)) < get<0>(get<0>(closest))){
			closest.first = pair.second;
			closest.second = pair.first;
		}
	}
	if(get<0>(get<0>(closest)) == 1000000001) return false;
	for(const auto seen : get<2>(comboPairSeen)){
		if(closest.first == seen) return true;
	}
	get<1>(comboPairSeen) = closest.second;
	get<2>(comboPairSeen).push_back(closest.first);
	simulateCycle(comboPairSeen);
}
int main(){
	ifstream fin("wormhole.in");
	size_t num;
	fin >> num;
	vector<pair<size_t,size_t>> input;
	size_t pair1, pair2;
	for(size_t i = 0; i < num; ++i){
		fin >> pair1 >> pair2;
		input.push_back(make_pair(pair1, pair2));
	}
	pair<vector<pair<pair<size_t,size_t>,pair<size_t,size_t>>>, vector<pair<size_t,size_t>>> initial;
	initial.second = input;
	generateCombos(initial);
	size_t cycles = 0;
	for(const auto combo : pairCombos){
		bool yes = false;
		for(const auto coord : combo){
			vector<pair<size_t, size_t>> nothing;
			auto a = make_tuple(combo, coord.first, nothing);
			auto b = make_tuple(combo, coord.second, nothing);
			if(!yes) yes = (simulateCycle(a) || simulateCycle(b));
			else break;
		}
		if(yes) ++cycles;
	}
	ofstream fout("wormhole.out");
	fout << cycles << endl;
}