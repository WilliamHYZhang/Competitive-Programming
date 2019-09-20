#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
bool wayToSort(vector<int> const &i, vector<int> const &j){return i[0] < j[0];}
int main()
{
	ifstream cin ("measurement.in");
	ofstream cout ("measurement.out");
	int numOfEntries;
	cin >> numOfEntries;
	vector<vector<int>> entries;
	map<string, int> names;
	for(size_t i = 0; i < numOfEntries; ++i){
		int day, change, nameIndex = 0;
		string name;
		vector<int> tempVector;
		cin >> day >> name >> change;
		if(names.find(name) == names.end()){
			auto nameSize = names.size();
			names[name] = nameSize;
		}
		nameIndex = names[name];
		tempVector.push_back(day);
		tempVector.push_back(nameIndex);
		tempVector.push_back(change);
		entries.push_back(tempVector);
	}
	sort(entries.begin(), entries.end(), wayToSort);
	int scores[names.size()];
	int changeCount = 0;
	vector<int> previousDisplay;
	for(size_t i = 0; i < names.size(); ++i){
		scores[i] = 7;
		previousDisplay.push_back(i);
	}
	for(auto const &entry : entries){
		vector<int> currentDisplay;
		scores[entry[1]] += entry[2];
		int maxOutput = -1;
		for(size_t i = 0; i < names.size(); ++i){
			if(scores[i] > maxOutput)
				maxOutput = scores[i];
		}
		for(size_t i = 0; i < names.size(); ++i){
			if(scores[i] == maxOutput)
				currentDisplay.push_back(i);
		}
		if(previousDisplay != currentDisplay){
			++changeCount;
			previousDisplay = currentDisplay;
		}
	}
	cout << changeCount << "\n";
	return 0;
}
