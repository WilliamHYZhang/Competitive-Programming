#include <iostream>
#include <fstream>
using namespace std;
int intersectLine(int var1, int var2, int t1, int t2)
{
	int maxLeft = max(var1,t1);
	int minRight = min(var2,t2);
	if(minRight > maxLeft)
	{
		return minRight - maxLeft;
	}
	return 0;
}
int intersectArea(int x1, int y1, int x2, int y2, int tx1, int ty1, int tx2, int ty2)
{
	return intersectLine(x1, x2, tx1, tx2)*intersectLine(y1, y2, ty1, ty2);
}
int totalArea(int x1, int y1, int x2, int y2)
{
	return (x2-x1)*(y2-y1);
}
int main()
{
	int _1x1, _1y1, _1x2, _1y2, _2x1, _2y1, _2x2, _2y2, tx1, ty1, tx2, ty2;
	ifstream cin ("billboard.in");
	ofstream cout ("billboard.out");
	cin >> _1x1 >> _1y1 >> _1x2 >> _1y2 >> _2x1 >> _2y1 >> _2x2 >> _2y2 >> tx1 >> ty1 >> tx2 >> ty2;
	int billboard1Visible = totalArea(_1x1, _1y1, _1x2, _1y2) - intersectArea(_1x1, _1y1, _1x2, _1y2, tx1, ty1, tx2, ty2);
	int billboard2Visible = totalArea(_2x1, _2y1, _2x2, _2y2) - intersectArea(_2x1, _2y1, _2x2, _2y2, tx1, ty1, tx2, ty2);
	int totalVisible = billboard1Visible + billboard2Visible;
	cout << totalVisible << '\n';
	return 0;
}
