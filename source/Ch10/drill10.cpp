
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

	for(int i = 0; i < 7; i++){

	double x = 0, y = 0 ;
	char ch1,ch2,ch3;

	is >> ch1 >> x >> ch2 >> y >> ch3;
	if(!is) return is;
	
	if(ch1 != '(' && ch2 != ',' && ch3 == ')'){

		is.clear(ios_base::failbit);
		return is;
		}

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
	for(int i = 0;i < 7 ;i++)
	{
		double x = 0;
		double y = 0;

		cin >> x >> y;
		original_points.push_back(Point{x, y});
	}

}

int main()
try{
	vector<Point> processed_points;

	Point point(3.2,32.2);
	cout << '(' << point.x << ',' << point.y<< ')' << endl;

	cout << "Pls give me seven pairs of coordinate!"<< endl;
	cout <<"--------------<original_points>-----------------"<< endl;

	getPoints();
	cout << original_points;

	const string ofile = "mydata.txt";
	ofstream ost {ofile};

	ost << original_points << endl; 
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