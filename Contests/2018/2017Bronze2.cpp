#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin ("shuffle.in");
	ofstream cout ("shuffle.out");
	int numOfCows;
	cin >> numOfCows;
	int cowShuffleKey[numOfCows];
	for(int i = 0; i < numOfCows; ++i)
	{
		cin >> cowShuffleKey[i];
		cowShuffleKey[i] -= 1;
	}
	int cowNames[numOfCows];
	for(int i = 0; i < numOfCows; ++i)
	{
		cin >> cowNames[i];
	}
	for(int x = 0; x < 3; ++x)
	{
		int tempOrder[numOfCows];
		for(int y = 0; y < numOfCows; ++y)
		{
			tempOrder[y] = cowNames[cowShuffleKey[y]];
		}
		for(int y = 0; y < numOfCows; ++y)
		{
			cowNames[y] = tempOrder[y];
		}
	}
	for(int i = 0; i < numOfCows; ++i)
	{
		cout << cowNames[i] << "\n";
	}
}