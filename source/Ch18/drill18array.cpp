#include "std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int arr[], int sz)
{
	int la[10];
	for (int i = 0; i < 10; ++i)
	{
		la[i] = ga[i];
		cout << la[i] << endl;
	}

	int* p = new int[sz];
	for (int i = 0; i < sz; ++i)
	{
		p[i] = arr[i];
		cout << p[i] << endl;
	}
	delete[] p;
 }

int factor(int n)
{

	return n > 1 ? n*(factor(n - 1)) : 1;

}

int main()
try{
	cout << "The element of the ga array: \n";
	for (int i = 0; i < 10; ++i)
	{
		cout << ga[i] <<endl;
	}

	cout << "Function ga print: \n";
	f(ga,10);

	cout << "The aa array (factortor) elements: \n";

	int aa[10] = {factor(1), factor(2), factor(3), factor(4), factor(5), factor(6), factor(7), factor(8), factor(9), factor(10)};
	f(aa,10);

	return 0;

}catch(exception& e){
	cerr << "Exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Unknown exception\n";
	return 2;
}