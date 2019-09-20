#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, string> mother;

string relation(string A, string B){
	unordered_map<string, size_t> directLevel;
	string currentDirect = mother[A];
	size_t currentLevel = 0;
	string ans;

	while(currentDirect != ""){
		if(currentDirect == B){
			ans.append(B);
			ans.append(" is the ");
			for(size_t i = 0; i < currentLevel; ++i){
				if(i == currentLevel-1) ans.append("grand-");
				else ans.append("great-");
			}
			ans.append("mother of ");
			ans.append(A);
			return ans;
		}
		directLevel[currentDirect] = currentLevel;
		currentDirect = mother[currentDirect];
		++currentLevel;
	}
	
	currentDirect = mother[B];
	if(directLevel.find(currentDirect) != directLevel.end()){
		if(directLevel[currentDirect] == 0)
			return "SIBLINGS";
		else{
			ans.append(B);
			ans.append(" is the ");
			for(size_t i = 0; i < directLevel[currentDirect]-1; ++i)
				ans.append("great-");
			ans.append("aunt of ");
			ans.append(A);
			return ans;
		}
	}

	else{
		while(directLevel.find(currentDirect) == directLevel.end()){
			currentDirect = mother[currentDirect];
			if(currentDirect == ""){
				return "NOT RELATED";
			}
		}
		return "COUSINS";
	}
}
int main(){
	ifstream fin("family.in");
	ofstream fout("family.out");

	size_t N;
	string A, B;
	fin >> N >> A >> B;
	string inputMother, inputChild;
	for(size_t i = 0; i < N; ++i){
		fin >> inputMother >> inputChild;
		mother[inputChild] = inputMother;
	}

	auto returnAB = relation(A,B), returnBA = relation(B,A);
	if(returnAB == "COUSINS" && returnBA == "COUSINS") fout << "COUSINS" << endl;
	else if(returnAB != "COUSINS" && returnAB != "NOT RELATED") fout << returnAB << endl;
	else fout << returnBA << endl;
}