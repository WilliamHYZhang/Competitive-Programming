#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream in("teleport.in");
	int start, end, teleX, teleY;
	in >> start >> end >> teleX >> teleY;
	int teleport1 = abs(start-teleX)+abs(end-teleY);
	int teleport2 = abs(start-teleY)+abs(end-teleX);
	int haul = abs(start-end);
	ofstream out("teleport.out");
	out << min(teleport1, min(teleport2, haul)) << endl;
}
