
#include "std_lib_facilities.h"

class Point {
public:
	Point(double p_1, double p_2): x{p_1}, y{p_2} {};
	Point();
    double x;
    double y;
};

bool operator==(const Point& p1, const Point& p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}


istream& operator>>(istream& is, vector<Point>& p)
{
	for(int i = 0;i < 7; i++)
	{
		double x = 0, y = 0 ;
		is >> x >> y;

		p.push_back(Point{x,y});
	}

	return is;
}

ostream& operator<<(ostream& os, vector<Point>& p){
	for(auto& v : p)
		os<< '(' << v.x << ',' << v.y << ')' << endl;

	return os;
}
	vector<Point> original_points;

void getPoints()
{
	double x = 0;
	double y = 0;

	for(int i = 0;i < 7 ;i++)
	{
		cin >> x >> y;
		original_points.push_back(Point{x, y});
	}

}

int main()
try{
	vector<Point> processed_points;

	Point point(3.2,32.2);
	cout << '(' << point.x << ',' << point.y<< ')' << endl;


	cout <<"--------------<original_points>-----------------"<< endl;
	getPoints();
	cout << original_points;

	const string ofile = "mydata.txt";
	ofstream ost {ofile};

	for(auto& pt : original_points)	
		ost <<  pt.x << " " << pt.y << endl; // Never do here stuff like that ost <<'(' <<pt.x << ', ' << pt.y << ')'<< endl; u did it in the os override to look a like this (x,y)
	ost.close();


    cout <<"--------------<processed_points>-----------------"<< endl;

    const string ifile = "mydata.txt";
	ifstream ist {ifile};
	ist >> processed_points;
	ist.close();

	cout << processed_points << endl;

	if(original_points != processed_points)
		cout << "They are not equal !" << endl;
	else
		cout << "The original_points and processed_points are equal !" << endl;

	return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}