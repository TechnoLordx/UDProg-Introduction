#include "std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int> v)
{
	vector<int> lv(v.size());
	lv = gv;

	for(int num : lv)
		cout << num << endl;

	vector<int> lv2(v);

	for(int num : lv2)
		cout << num << endl;

}

int factor(int n)
{

	return n > 1 ? n*(factor(n - 1)) : 1;

}

int main()
try{
	cout << "The elements of gv vector: \n";
	f(gv);

	cout << "The elements of vv vector: \n";

	vector<int> vv = {factor(1), factor(2), factor(3), factor(4), factor(5), factor(6), factor(7), factor(8), factor(9), factor(10)};
	f(vv);

	return 0;

}catch(exception& e){
	cerr << "Exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Unknown exception\n";
	return 2;
}