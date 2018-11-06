/*
ID: billz541
TASK: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

size_t V;
size_t G;
vector<size_t> minimum;
vector<vector<size_t>> feeds;
vector<vector<size_t>> queue;

vector<size_t> BFS(){
	size_t current = 0;
	while(current < queue.size()){
		vector<size_t> indexes = queue[current];
		vector<size_t> temp (V, 0);
		for(auto index : indexes){	
			for(size_t i = 0; i < V; ++i){
				temp[i] += feeds[index][i];
			}
		}
		bool qDone = true;
		for(size_t i = 0; i < V; ++i){
			if(temp[i] < minimum[i]){
				qDone = false;
				break;
			}
		}
		if(qDone) return indexes;
		else if(queue[current].back() != feeds.size()-1){
			for(size_t last = queue[current].back()+1; last < feeds.size(); ++last){
				vector<size_t> temp = queue[current];
				temp.push_back(last);
				queue.push_back(temp);
			}
		}
		++current;
	}
}
int main(){
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> V;
	for(size_t i = 0, input; i < V; ++i){
		fin >> input;
		minimum.push_back(input);
	}
	
	fin >> G;
	for(size_t i = 0; i < G; ++i){
		vector<size_t> temp;
		for(size_t j = 0, input; j < V; ++j){fin >> input; temp.push_back(input);};
		feeds.push_back(temp);
		vector<size_t> temp1;
		temp1.push_back(i);
		queue.push_back(temp1);
	}
	auto ans = BFS();
	fout << ans.size();
	for(auto elem : ans) fout << " " << elem+1;
	fout << endl;
}