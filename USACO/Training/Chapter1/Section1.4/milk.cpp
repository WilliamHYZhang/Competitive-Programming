/*
ID: billz541
TASK: milk
LANG: C++11        
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){

	ifstream in("milk.in");
	size_t goalAmount, numOfFarmers;
	in >> goalAmount >> numOfFarmers;
	vector<pair<size_t, size_t>> priceAndAmount;
	size_t price, amount;
	for(size_t i = 0; i < numOfFarmers; ++i){
		in >> price >> amount;
		pair<size_t,size_t> temp (price, amount);
		priceAndAmount.push_back(temp);
	}

	sort(priceAndAmount.begin(), priceAndAmount.end(), 
		[](const pair<size_t, size_t> &a, const pair<size_t, size_t> &b){return a.first < b.first;});

	size_t moneySpent = 0, milkLeft = goalAmount;
	while(milkLeft > 0){
		for(auto const &farmer : priceAndAmount){
			if(farmer.second <= milkLeft){
				moneySpent += farmer.first*farmer.second;
				milkLeft -= farmer.second;
			}
			else{
				moneySpent += farmer.first*milkLeft;
				milkLeft -= milkLeft;
			}
		}
	}

	ofstream out("milk.out");
	out << moneySpent << endl;
}
