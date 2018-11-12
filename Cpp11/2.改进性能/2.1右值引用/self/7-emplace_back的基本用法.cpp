#include <vector>
#include <iostream>
using namespace std;

struct A
{
	int x;
	double y;
	A(int a, double b):x(a),y(b){}
};

int main()
{
	vector<A> v;
	v.emplace_back(1, 2);
	cout << v.size() << endl;
	cout << v[0].x << ", " << v[0].y << endl;
	return 0;
}
