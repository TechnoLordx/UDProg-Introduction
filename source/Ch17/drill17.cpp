#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a){
	
	for (int i = 0; i < 10; ++i)
	{
		 os << i+1 << ". " << a[i] << endl;
	}
}

void print_array(ostream& os, int* a, int n){
	
	for (int i = 0; i < n; ++i)
	{
		os << i+1 << ". " << a[i] << endl;
	}
}

void print_vector(ostream& os, vector<int>& v){

	for (int i = 0; i < v.size(); ++i)
	{
		os <<i+1 << ". " << v[i] << endl;
	}
}
/*

void print_vector(ostream& os,vector<int*> v)
{
	for (int i = 0; i < v.size(); ++i)
		os << i+1 << ". " << *v[i] << endl;
}

void delete_vector(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
		delete v[i]; // a vektro eleminként törlöm/felszabaditom
}
*/
// a * -al jelezzük, hogy ez egy mutató ez a változó --> int tipusú elemre fog mutatni
// pointer egy memória cím pl: 600 cimen ---> mutat az értékére 7
int main()
try {
    
    int* arr10 = new int[10]; // new operátorral foglalunk memóriát 10 int nek foglal memóriát FS ben
    							// itt 10 db helyet foglalle
    for (int i = 0; i < 10; ++i)
    {
    	cout << i << ". " << arr10[i] << endl;
    }

    cout << "\n--------------1-2-----------\n\n";

    print_array10(cout,arr10);
    delete[] arr10; // itt deallokáljuk a heapről
    
    cout << "\n----------3---------------\n\n";




    int* arr20 = new int[10];
    int num = 100;

    for (int i = 0; i < 10; ++i)
    {
    	arr20[i] = num;
    	num++; 
    }
    num = 100;
    print_array10(cout,arr20);
    delete[] arr20;
    

    cout << "\n-------------4-5-----------\n\n";




    int* arr31 = new int[11];
    
      for (int i = 0; i < 10; ++i)
    {
    	arr31[i] = num;
    	num++;
    }
    num = 100;
    print_array10(cout,arr31);
    delete[] arr31;

    cout << "\n--------------6-----------\n\n";



    int* array = new int[20];
    
      for (int i = 0; i < 20; ++i)
    {
    	array[i] = num;
    	num++;
    }
    num = 100;
    print_array(cout,array,20);
    delete[] array;

    cout << "\n--------------7-8-9---------\n\n";

    cout << "Vektrok: \n";




    cout << "\n1. vektro\n\n";
    vector<int> v10;
    for (int i = 0; i < 10; ++i)
	{
		v10.push_back(num++);
	}
    num = 100;
	print_vector(cout,v10);
	//delete_vector(v10);




	cout << "\n2. vektro\n\n";
	vector<int> v11;
	for (int i = 0; i < 11; ++i)
	{
		v11.push_back(num++);
	}
    num = 100;
	print_vector(cout,v11);
	//delete_vector(v11);




	cout << "\n3.vektro\n\n";
    vector<int> v20;
    for (int i = 0; i < 20; ++i)
	{
		v20.push_back(num++);
	}
    num = 100;
	print_vector(cout,v20);
	//delete_vector(v20);


    cout << "\n-------------10----------\n\n";
    cout << "------------The End-----------\n";


    return 0;
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}