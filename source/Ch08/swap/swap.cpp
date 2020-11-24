#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b) // objektum referenciát fogunk át adni// az "a" egy új név lessz az x objektumra
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}
/*
void swap_cr(const int& a, const int& b) // nem fordiltja le mert a és b csak olvasható referenciák
{										 //--> oka: megprobáltunk értéket rendelni neki const a& nak -||-
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}
*/

int main()
{
	int x = 7;
	int y = 9;

	swap_v(x,y); // nm cserél, csak az argumentumaink másolatát kezeli (void fv)
	cout <<"x: " << x << " y: " << y << endl;

	swap_r(x,y); // forditás van és cserél 
	cout <<"x: " << x << " y: " << y << endl;

	swap_v(7,9);// fordit DE nm tudjuk kiírni mert nincs inicializálva és amikor bef. a fv akkor nm irja ki mert nm is tudja ;(
//	swap_r(7,9);// nm fordija le mint referencia --> nincs inicializálva mint pl x igy referencia ként fv -bol az a& nm

	const int cx = 7;
	const int cy = 9;

	swap_v(cx,cy);// fordirja de nm cserél 
	cout << "cx: " << cx << "  cy: " << cy << '\n';

//	swap_r(cx,cy); // nm forditja le --> const int cx mert az fv -ben referencia van az meg nem const
	cout << "cx: " << cx << "  cy: " << cy << '\n';

	swap_v(7.7,9.9); // fordit elvégzi a cserét de amint bef. a fv az adatok elvesznek 
//	swap_r(7.7,9.9); // nm fordija le mint referencia --> nincs inicializálva mint pl x igy referencia ként fv -bol az a& nm
	
	//*Az alap hiba ,hogy a fv inteket kezel és ez double és így info loss van .)

	double dx = 7.7;
	double dy = 9.9;
/*
	swap_v(dx,dy); // leforditja de a fv csak a másolatokat kezeli igy nm történik csere
	cout << "dx: " << dx << " dy:" << dy << '\n';

	swap_r(dx,dy); // U.a a problléma mint elözzőnél double int --> info loss lessz
*/
	cout << "dx: " << dx << " dy:" << dy << '\n'; 

//	swap_v(7.7,9.9);// *


	return 0;
}