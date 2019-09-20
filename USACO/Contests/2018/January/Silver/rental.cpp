#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	ifstream fin("rental.in");
	ofstream fout("rental.out");

	size_t M, N, R;
	fin >> M >> N >> R;
	vector<size_t> cow;
	vector<pair<size_t, size_t>> milk;
	vector<size_t> rent;

	for(size_t i = 0, input; i < M; ++i)
		{fin >> input; cow.push_back(input);}
	for(size_t i = 0, a, b; i < N; ++i)
		{fin >> a >> b; milk.push_back(make_pair(a,b));}
	for(size_t i = 0, input; i < R; ++i)
		{fin >> input; rent.push_back(input);};

	sort(cow.begin(), cow.end(), 
		[](size_t a, size_t b){return a > b;});
	sort(milk.begin(), milk.end(), 
		[](pair<size_t, size_t> a, pair<size_t, size_t> b){return a.second > b.second;});
	sort(rent.begin(), rent.end(),
		[](size_t a, size_t b){return a > b;});

	vector<long long int> prices;
	long long int total = 0LL;
	size_t rentIndex = 0, cowIndex = 0, milkIndex = 0;
	for(; cowIndex < M; ++cowIndex){
		long long int current = 0LL;
		while(milkIndex < N){
			if(cow[cowIndex] <= milk[milkIndex].first){
				current += cow[cowIndex] * milk[milkIndex].second;
				milk[milkIndex].first -= cow[cowIndex];
				if(milk[milkIndex].first == 0)
					++milkIndex;
				break;
			}
			else{
				current += milk[milkIndex].first * milk[milkIndex].second;
				cow[cowIndex] -= milk[milkIndex].first;
				++milkIndex;
			}
		}
		prices.push_back(current);
		total += current;
	}

	while(cowIndex < M && rentIndex < R){
		total += rent[rentIndex];
		++cowIndex;
		++rentIndex;
	}

	for(size_t i = rentIndex; i < min(rentIndex + M, R); ++i){
		if(prices.back() > rent[i]) break;
		total = total - prices.back() + rent[i];
		prices.pop_back();
	}

	fout << total << endl;
}
