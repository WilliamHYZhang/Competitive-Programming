/*
ID: billz541
TASK: sprime
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

size_t N;
vector<size_t> primes;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool isPrime(size_t num){
	for(auto prime : primes){
		if((prime*prime) > num){
			return true;
		}
		if(num%prime == 0)
			return false;
	}
}
void findSP(size_t current){
	if(to_string(current).length() == N)
		fout << current << endl;
	else{
		for(size_t i = 1; i <= 9; i += 2){
			if(i == 5)
				continue;
			else if(isPrime(current*10+i))
				findSP(current*10+i);			
		}
	}
}

int main(){
	bool nums[10001];
	memset(nums, true, sizeof(nums));
	for(size_t i = 2; i <= 10000; ++i){
		if(nums[i]){
			primes.push_back(i);
			for(size_t j = i*2; j <= 10000; j += i)
				nums[j] = false;
		}
	}

	fin >> N;

	findSP(2);
	for(size_t i = 3; i <= 7; i += 2) findSP(i);
}