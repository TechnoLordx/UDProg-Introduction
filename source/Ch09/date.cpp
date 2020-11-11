#include "std_lib_facilities.h"

namespace UDChrono{

class Year{
	static  constexpr int min = 1800;
	static  constexpr int max = 2100;
public: // Year nek van egy x konstruktorja
	class Invalid{};
	Year(int x): y(x) { if (x < min || x > max) throw Invalid{}; }
	//átadjuk vmi lokális év változónak

	int year() { return y; } // mivel privát igy ezen keresztűl kérjük el y-t
	void increment() { y++; if (y > max ) throw Invalid{}; } // ha tag fvn keresztül érjuk el van erre is lehetöseg 
private:
	int y; // ez az az év amit replezentálunk ebben az osztályba int
};

Year operator++(Year& year)
{
	year.increment();
}

ostream& operator<<(ostream& os, Year year)
{
	return os << year.year();
}

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month{ // enum felsorolási típusok
	jan, feb, mar, apr, may, june, july, aug, sept, oct, nov, dec // alapértrelmezett értékek 0,1,2... de meg is lehet adni h pl jan =1
};
				//jobb értéket használjuk
Month operator++(Month& m)// referenciát adunk m
{    // ha a honap = dec    akkor jan    hanem akkor ez
	m = (m == Month::dec) ? Month::jan : Month(int (m)+1); // ha valami ? igaz ez fut le : hamis e fut le 
	return m;
}                    //pl cout << m
//                  jobb érték  bal érték
ostream& operator<<(ostream& os, Month m) // A Month miatt kell elkésziteni mi csináltuk és a gép nm tudja h mit csinaljon vele ezért meg kell adni override
{
	return os << months[int(m)]; 
}

class Date{
private://itt nm kell kiirni
	Year year;
	Month month;
	int day; 
public: 
	class Invalid {};         
	Date(): year(Year{2002}), month(Month::jan), day(1) {}//adtunk egy kezdö erteket (alap értelmezett)
								// értékadás                   ha hamis akkor dob kivételett 
	Date(Year y, Month m, int d): year(y), month(m), day(d) {if(!is_valid()) throw Invalid{}; } 

	bool is_valid();
	void add_day(int n); // itt deklalárjuk ** |és ezegy prototipus

 	Year get_year() const { return year; }// "getter fv vissza adnak vmit " a const kulcs szóval jelezzük hogy nm változtatja meg objektum állapotát
 	Month get_month() const { return month; } // vissza adja a tagok értékét
 	int get_day() const { return day; } 
};

bool Date::is_valid()
{
	if(day < 1 || day > 31) return false;

	return true;
}

void Date::add_day(int n) // itt meg deffiniáljuk **
{
	day += n;
	if(day > 31)
	{
		++month;
		day -= 31;
		if (month == Month::jan)
		{
			++year;
		}
	}
}

} // UDChrono vége

int main()
try{

	UDChrono::Date today {UDChrono::Year{1978}, UDChrono::Month::june, 25}; // 3 paraméteres konstuktor
	
	cout << "Date: " << today.get_year() << "." << today.get_month() <<
	 "." << today.get_day() << "\n";

	UDChrono::Date tomorrow {today};
	tomorrow.add_day(1);

	cout << "Date: " << tomorrow.get_year() << "." << tomorrow.get_month() <<
	 "." << tomorrow.get_day() << "\n";

	 vector<UDChrono::Date> dates(10);

	 cout << "Vector\n";
	 for (const auto& date : dates)
	 	cout << "Date: " << date.get_year() << "." << date.get_month() <<
	 "." << date.get_day() << "\n";


	return 0;

}catch (UDChrono::Date::Invalid){
	cout << "Invalid date\n" << endl;
	return 1;

}catch (UDChrono::Year::Invalid){
	cout << "Invalid year\n" << endl;
	return 1;


} catch (exception& e){
	cout << e.what() << endl;
	return 2;
}
