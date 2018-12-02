/*
ID: billz541
TASK: preface
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

struct values{
	size_t value[7];
};

int main(){
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	values ans = {0,0,0,0,0,0,0};
	size_t N;
	fin >> N;

	unordered_map<size_t, values> key;
	key[0] = {0,0,0,0,0,0,0};
	key[1] = {1,0,0,0,0,0,0};
	key[2] = {2,0,0,0,0,0,0};
	key[3] = {3,0,0,0,0,0,0};
	key[4] = {1,1,0,0,0,0,0};
	key[5] = {0,1,0,0,0,0,0};
	key[6] = {1,1,0,0,0,0,0};
	key[7] = {2,1,0,0,0,0,0};
	key[8] = {3,1,0,0,0,0,0};
	key[9] = {1,0,1,0,0,0,0};

	key[10] = {0,0,1,0,0,0,0};
	key[20] = {0,0,2,0,0,0,0};
	key[30] = {0,0,3,0,0,0,0};
	key[40] = {0,0,1,1,0,0,0};
	key[50] = {0,0,0,1,0,0,0};
	key[60] = {0,0,1,1,0,0,0};
	key[70] = {0,0,2,1,0,0,0};
	key[80] = {0,0,3,1,0,0,0};
	key[90] = {0,0,1,0,1,0,0};

	key[100] = {0,0,0,0,1,0,0};
	key[200] = {0,0,0,0,2,0,0};
	key[300] = {0,0,0,0,3,0,0};
	key[400] = {0,0,0,0,1,1,0};
	key[500] = {0,0,0,0,0,1,0};
	key[600] = {0,0,0,0,1,1,0};
	key[700] = {0,0,0,0,2,1,0};
	key[800] = {0,0,0,0,3,1,0};
	key[900] = {0,0,0,0,1,0,1};

	key[1000] = {0,0,0,0,0,0,1};
	key[2000] = {0,0,0,0,0,0,2};
	key[3000] = {0,0,0,0,0,0,3};

	for(size_t i = 0; i <= N; ++i){
		size_t num = i, exp = 1;
		while(num != 0){
			size_t digit = num%10 * exp;
			for(size_t i = 0; i < 7; ++i)
				ans.value[i] += key[digit].value[i];
			num /= 10;
			exp *= 10;
		}
	}

	fout << "I " << ans.value[0] << endl;
	if(ans.value[1]) fout << "V " << ans.value[1] << endl;
	if(ans.value[2]) fout << "X " << ans.value[2] << endl;
	if(ans.value[3]) fout << "L " << ans.value[3] << endl;
	if(ans.value[4]) fout << "C " << ans.value[4] << endl;
	if(ans.value[5]) fout << "D " << ans.value[5] << endl;
	if(ans.value[6]) fout << "M " << ans.value[6] << endl;

}
