/*
ID: billz541
TASK: pprime
LANG: C++11
*/
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

size_t A, B;
vector<size_t> primes;
vector<size_t> ans;

int isPrime(size_t num){
	if(A <= num && num <= B){
		for(auto prime : primes){
			if(prime*prime > num){
				ans.push_back(num);
				return 0;
			}
			if(num%prime == 0) return 0;
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

	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	fin >> A >> B;
	size_t digA = to_string(A).length(), digB = to_string(B).length();
	for(size_t d1 = 1; d1 <= 9; d1 += 2){
		if(digA <= 1 && 1 <= digB) isPrime(d1);
		if(digA <= 2 && 2 <= digB) isPrime(10*d1+d1);
		for(size_t d2 = 0; d2 <= 9; ++d2){
			if(digA <= 3 && 3 <= digB) isPrime(100*d1+10*d2+d1);
			if(digA <= 4 && 4 <= digB) isPrime(1000*d1+100*d2+10*d2+d1);
			for(size_t d3 = 0; d3 <= 9; ++d3){
				if(digA <= 5 && 5 <= digB) isPrime(10000*d1+1000*d2+100*d3+10*d2+d1);
				if(digA <= 6 && 6<= digB) isPrime(100000*d1+10000*d2+1000*d3+100*d3+10*d2+d1);
				for(size_t d4 = 0; d4 <= 9; ++d4){
					if(digA <= 7 && 7 <= digB) isPrime(1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1);
					if(digA <= 8 && 8 <= digB) isPrime(10000000*d1+1000000*d2+100000*d3+10000*d4+1000*d4+100*d3+10*d2+d1);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto elem : ans)
		fout << elem << endl;
}