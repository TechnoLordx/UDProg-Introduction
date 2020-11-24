#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << "Value: " <<*a << " address: " << a <<endl;
		a++;
	}
	cout << '\n';
}

void delete_vector(vector<int*> v, int s){

	for (int i = 0; i < s; ++i)
	{
		delete v[i];
	}
}

int main()
try{

	int x = 7;
	int* p1 = &x;

	cout << "Pointer " << p1 << " points to " << *p1 << '\n'; // p a pointer azaz a memoria cim a *p pedig az az érték amira mutat
	int arr[7] = {1, 2, 4, 8, 16, 32, 64};
	int* p2 = arr;

	print_array(cout,p2,7); 

	int* p3 = p2;

	p2 = p1;
	p2 = p3;


	cout << "Address: " << p1 << '\t' << "value: " <<*p1 << endl;
	cout << "Address: " <<p2 << '\t' << "value: " <<*p2 << '\n' <<endl;



	int arr10[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	p1 = arr10;

	int arr12[10];
	p2 = arr12;

	for(int i = 0;i < 10; ++i)
	{
		p2[i] = p1[i];
	}
	print_array(cout, p2, 10);

	cout << "\nVector\n";

	vector<int*> v1;
	for(int i = 0;i < 10; ++i)
		v1.push_back(new int{p1[i]});


	vector<int*> v2;
	for(int i = 0;i < 10; ++i)
		v2.push_back(new int{p2[i]});


	for(int i = 0;i < 10; ++i)
		*v2[i] = *v1[i];

	for (int i = 0; i < 10; ++i)
	{
		cout << "Address: " << v1[i]  << "\tvalue: " << *v1[i] << '\t' << "Address: " << v2[i] << "\tvalue: " << *v2[i] << endl;
	}

	delete_vector(v1, 10);
	delete_vector(v2, 10);

	return 0;
}
catch(exception& e){
	cerr << "Exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Unknown exception\n";
	return 2;
}