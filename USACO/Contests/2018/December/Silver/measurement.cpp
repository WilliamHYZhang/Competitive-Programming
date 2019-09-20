#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){

	ifstream in("measurement.in");
	int num, initial;
	in >> num >> initial;
	vector<vector<int>> measurements;
	map<int, int> scores;
	set<pair<int,int>> setScores;
	vector<int> previousDisplay;
	previousDisplay.push_back(0);
	scores.insert(pair<int,int>(0, initial));
	setScores.insert(pair<int,int>(initial, 0));
	for(size_t i = 0; i < num; ++i){
		int day, name, change;
		in >> day >> name >> change;
		vector<int> temp;
		temp.push_back(day);
		temp.push_back(name);
		temp.push_back(change);
		measurements.push_back(temp);
		if(scores.find(name) == scores.end()){
			scores.insert(pair<int,int>(name, initial));
			setScores.insert(pair<int,int>(initial, name));
			previousDisplay.push_back(name);
		}
	}

	int changeCount = 0;
	sort(measurements.begin(), measurements.end(),[](vector<int> const &i, vector<int> const &j){return i[0] < j[0];});
	for(auto const &entry : measurements){
		setScores.erase(pair<int,int>(scores[entry[1]], entry[1]));
		scores[entry[1]] += entry[2];
		setScores.insert(pair<int,int>(scores[entry[1]],entry[1]));
		vector<int> currentDisplay;
		auto it = setScores.rbegin();
		auto maximum = it->first;
		for(auto e = setScores.rend(); it != e && it->first == maximum; ++it){
			currentDisplay.push_back(it->second);
		}
		if(currentDisplay != previousDisplay){
			previousDisplay.swap(currentDisplay);
			++changeCount;
		}
	}

	ofstream out("measurement.out");
	out << changeCount << endl;
}
