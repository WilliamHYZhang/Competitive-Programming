/*
ID: billz541
TASK: crypt1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

size_t partialProduct(size_t num1, size_t num2, size_t num3, size_t num4){return(num1*100 + num2*10 + num3)*num4;};

vector<size_t> getDigits(size_t val){
	vector<size_t> returnVector;
	do{
		returnVector.push_back(val%10);
		val /= 10;
	} while (val>0);
	return returnVector;
}

bool in(const vector<size_t> &arr1, const vector<size_t> &arr2){
	for(const auto elem1 : arr1){
		bool tempIn = false;
		for(const auto elem2 : arr2)
			if(elem1 == elem2) tempIn = true;
		if(!tempIn) return false;
	}
	return true;
} 

int main(){
	ifstream fin("crypt1.in");
	size_t num;
	fin >> num;
	vector<size_t> nums;
	size_t input;
	for(size_t i = 0; i < num; ++i){
		fin >> input;
		nums.push_back(input);
	}

	size_t ans = 0;
	for(const auto dig1 : nums){
		for(const auto dig2 : nums){
			for(const auto dig3 : nums){
				for(const auto dig4 : nums){
					for(const auto dig5 : nums){
						if(dig1 == 0 || dig4 == 0) continue;
						auto sum1 = partialProduct(dig1, dig2, dig3, dig5);
						auto sum2 = partialProduct(dig1, dig2, dig3, dig4);
						auto digits1 = getDigits(sum1);
						auto digits2 = getDigits(sum2);
						if(digits1.size() != 3 || digits2.size() != 3) continue;
						if(!in(digits1, nums)) continue;
						if(!in(digits2, nums)) continue;
						if(!in(getDigits(sum1 + (sum2*10)), nums)) continue;
						++ans;
					}
				}
			}
		}
	}

	ofstream fout("crypt1.out");
	fout << ans << endl;
}