#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<size_t> possible;

void travel(size_t first, vector<size_t> current1, vector<size_t> current2, size_t day){
	if(day == 5){
		possible.insert(first);
		return;
	}
	else{
		if(day%2 == 1){
			for(size_t i = 0; i < current1.size(); ++i){
				auto bucket = current1[i];
				auto new1 = current1, new2 = current2;
				new1.erase(new1.begin()+i);
				new2.push_back(bucket);
				travel(first - bucket, new1, new2, day+1);
			}
		}
		else{
			for(size_t i = 0; i < current2.size(); ++i){
				auto bucket = current2[i];
				auto new1 = current1, new2 = current2;
				new1.push_back(bucket);
				new2.erase(new2.begin()+i);
				travel(first + bucket, new1, new2, day+1);
			}
		}
	}
}
int main(){
	ifstream fin("backforth.in");
	ofstream fout("backforth.out");
	vector<size_t> current1, current2;
	for(size_t i = 0, bucket; i < 10; ++i){
		fin >> bucket;
		current1.push_back(bucket);
	}
	for(size_t i = 0, bucket; i < 10; ++i){
		fin >> bucket;
		current2.push_back(bucket);
	}
	travel(1000, current1, current2, 1);
	fout << possible.size() << endl;
}