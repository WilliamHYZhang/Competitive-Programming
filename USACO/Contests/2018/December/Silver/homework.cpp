#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
	
	ifstream ifs("homework.in");
	int numOfQuestions; 
	ifs >> numOfQuestions;
	vector<int> scores(numOfQuestions);
	for(size_t i = 0; i < numOfQuestions; ++i)
		ifs >> scores[i];

	int sum = scores[numOfQuestions-1], minimum = sum, num = 1;
	double maximum = -1.0;
	vector<double> averages;
	for(size_t i = numOfQuestions-2; i > 0; --i){
		int newNum = scores[i];
		if(newNum < minimum)
			minimum = newNum;
		sum += newNum;
		double average = double(sum-minimum)/double(num);
		if(average > maximum)
			maximum = average;
		averages.push_back(average);
		++num;
	}

	ofstream ofs("homework.out");
	for(int i = averages.size()-1; i > -1; --i){
		if(averages[i] == maximum)
			ofs << numOfQuestions-2-i << endl; 
	}
}
