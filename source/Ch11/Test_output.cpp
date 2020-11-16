#include "std_lib_facilities.h"

int main()
{
	int birth_year = 2001;
	int my_age = 19;

	cout << dec << birth_year << "\t(decimal)\n"
		<< hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n";

	cout << "\nMy age: " << dec << my_age << '\n' << endl;


	cout << showbase << dec << birth_year << "\t(decimal)\n"
		<< hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n" << noshowbase << dec;

	int a, b, c, d;
	cin >> a >>	oct >> b >> hex >> c >> d;
	cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;


	cout << '\n' 
		<< defaultfloat << 1234567.89 << "\t(defaultfloat)\n"
		<< fixed << 1234567.89 << "\t(fixed)\n"
		<< scientific << 1234567.89 << "\t(scientific)\n";

	cout << '\n' <<setw(8) << "Illés" << '|' <<  setw(9) << "Zoltán" << '|' <<  setw(13) << "0123456789" << '|'  <<  setw(19) << "zoli@freedom.com" << endl;
}