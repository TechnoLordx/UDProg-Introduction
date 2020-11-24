#include "std_lib_facilities.h"

int main()
try{
	
	int* arr10 = new int (10);

	for (int i = 0; i < 10; ++i)
	{
		cout >> "Array: " << i << " " << arr10[i] << endl;
	}

	return 0;

catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}