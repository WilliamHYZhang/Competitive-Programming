#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin("tttt.in");
	ofstream fout("tttt.out");

	char board[9];
	char input;
	string players;
	for(size_t i = 0; i < 9; ++i){
		fin >> input;
		board[i] = input;
		bool addToString = true;
		for(size_t j = 0; j < players.size(); ++j)
			if(input == players[j]) {addToString = false; break;}
		if(addToString) players += input;
	}

	size_t winningCombos[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,4,8}, {2,4,6}, {0,3,6}, {1,4,7}, {2,5,8}};
	size_t single = 0, team = 0;
	for(size_t i = 0; i < players.size(); ++i){
		for(size_t j = i; j < players.size(); ++j){
			size_t playerPos[9] = {0};
			for(size_t k = 0; k < 9; ++k)
				if(board[k] == players[i]) 
					playerPos[k] = 1;
				else if(board[k] == players[j])
					playerPos[k] = 2;
			bool win = false;
			for(size_t combo = 0; combo < 8; ++combo){
				bool comboWin = true;
				for(size_t pos = 0, num1 = 0, num2 = 0; pos < 3; ++pos){
					if(playerPos[winningCombos[combo][pos]] == 1) ++num1;
					else if(playerPos[winningCombos[combo][pos]] == 2) ++num2;
					else {comboWin = false; break;};
					if(pos == 2 && i != j) if(!num1 || !num2) {comboWin = false; break;};
				}
				if(comboWin){win = true; break;};
			}
			if(win){
				if(i == j) ++single;
				else ++team;
			}
		}
	}
	fout << single << endl << team << endl;
}
