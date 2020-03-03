#include <bits/stdc++.h>
using namespace std;
int x, y;
char puzzle[100][100];
string word;
pair<int, int> search(pair<int, int> d, pair<int, int> pos, int i){
	if(pos.first >= 0 && pos.first < x && pos.second >= 0 && pos.second < y && puzzle[pos.first][pos.second] == word[i]){
		if(++i == word.size())
			return make_pair(++pos.first, ++pos.second);
		return search(d, make_pair(d.first + pos.first, d.second + pos.second), i);
	}
	return make_pair(0, 0);
}
void find(){
	for(int a = 0; a < x; ++a) for(int b = 0; b < y; ++b)
		for(int dx = -1; dx <= 1; ++dx) for(int dy = -1; dy <= 1; ++dy){
				auto ret = search(make_pair(dx, dy), make_pair(a, b), 0);
				if(ret.first)
					{cout << ++a << " " << ++b << endl << ret.first << " " << ret.second << endl; return;}
			}
	cout << "word not found" << endl;
}
int main(){
	ifstream fin("puzzle.in");
	int N; fin >> N;
	cout << N << endl;
	for(int i = 0; i < N; ++i){
		fin >> word >> x >> y;
		for(int a = 0; a < x; ++a) for(int b = 0; b < y; ++b) fin >> puzzle[a][b];
		find();
	}
}