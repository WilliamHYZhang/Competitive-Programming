#include <iostream>
#include <fstream>
using namespace std;
int intersectLine(int b1, int b2, int l1, int l2){
	int maxLeft = max(b1,l1);
	int minRight = min(b2,l2);
	if(minRight > maxLeft){
		return minRight - maxLeft;
	}
	return 0;
}
int main(){
	ifstream cin("billboard.in");
	ofstream cout("billboard.out");
	int lx1, ly1, lx2, ly2, bx1, by1, bx2, by2;
	cin >> lx1 >> ly1 >> lx2 >> ly2 >> bx1 >> by1 >> bx2 >> by2;
	if((intersectLine(bx1, bx2, lx1, lx2) == lx2-lx1 || intersectLine(by1, by2, ly1, ly2) == ly2-ly1) && (bx1 <= lx1 || bx2 >= lx2) && (by1 <= ly1 || by2 >= ly2))
		cout << ((lx2-lx1)*(ly2-ly1))-(intersectLine(bx1, bx2, lx1, lx2)*intersectLine(by1, by2, ly1, ly2)) << endl;
	else
		cout << (lx2-lx1)*(ly2-ly1) << endl;
}
