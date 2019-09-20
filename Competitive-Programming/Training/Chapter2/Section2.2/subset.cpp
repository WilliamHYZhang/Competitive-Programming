/*
ID: billz541
TASK: subset
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
//modified from geeksforgeeks dp 25
size_t qSubset(size_t arr[], size_t index, size_t sum){
	size_t subset[index+1][sum+1];
	for(size_t i = 0; i <= index; ++i)
		subset[i][0] = 1;
	for(size_t i = 1; i <= sum; ++i)
		subset[0][i] = 0;
	for(size_t i = 1; i <= index; ++i){
		for(size_t j = 1; j <= sum; ++j){
			if(j < arr[i-1])
				subset[i][j] = subset[i-1][j];
			else
				subset[i][j] = (subset[i-1][j] + subset[i-1][j-arr[i-1]]);
		}
	}
	return subset[index][sum];
}
int main(){
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	size_t N;
	fin >> N;
	size_t arr[N];
	size_t sum = 0;
	for(size_t i = 1; i <= N; ++i){
		arr[i-1] = i;
		sum += i;
	}
	if(sum%2 == 1){
		fout << 0 << endl;
		return 0;
	}
	else
		fout << qSubset(arr, N-1, sum/2) << endl;

}