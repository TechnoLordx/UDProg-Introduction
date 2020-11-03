#include "std_lib_facilities.h"

constexpr char number = '8';
constexpr char quit = 'e';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = '#';
constexpr char square_root = '@';
constexpr char cpow = 'p';

// const string declkey = "#";
const string quitkey = "exit";
const string sqrtkey = "sqrt";
const string powkey = "pow";

double expression();

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var){
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val){
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s){
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;

}

void set_value(string s, double d){
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
		error("set: undefined variable", s);
}

class Token{
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t){

	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get(){

	if (full){
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch){
		case print:
		case quit:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case let: // már karakterként van értelmeve nm deckey '#'
		case ',': 
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback(ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch)){
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
    			cin.putback(ch);
    			//if (s == declkey) return Token{let}; // let x = ...
    			if(s == quitkey) return Token{quit}; // quit a kilépéshez
    			else if(s == sqrtkey) return Token{square_root}; //square_root tipusu token hivja clac_sqrt
    			else if(s == powkey) return Token{cpow};  

    			else if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
    	return 0;
	}
}

void Token_stream::ignore(char c){

	if (full && c == buffer.kind){
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

Token_stream ts;

double calc_sqrt(){

	char ch; //olvassuk a következő karaktert és ha ez 
	if (cin.get(ch) && ch !='(') error ("'(' expected");
	cin.putback(ch); // vissza kell tenni mert eggyel többet olvasott be
	double d = expression(); // az ilyen esetek miatt (3*2+1) v (12+y)

	if(d < 0) error("sqrt: negative value expected ");

	return sqrt(d);

}

double primary();

double calc_pow(){

	char ch;
	if (cin.get(ch) && ch != '(') error("'(' expected");
		double d = primary();

	Token t = ts.get();
	if (t.kind != ',') error("',' expected");
		double d2 = primary();

	Token t2 = ts.get();
	if (t2.kind != ')') error("')' expected");

	return pow(d, narrow_cast<int>(d2));
}


double primary(){

	Token t = ts.get();
	switch (t.kind){
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error ("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		case square_root:
			return calc_sqrt(); 	
		case cpow:
			return calc_pow();		
		default:
			error("primary expected");
	}
	return -1;
}


double term(){

	double left = primary();
	Token t = ts.get();
	while(true){
		switch (t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error ("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error ("%: Zero oszto");
				left = fmod (left, d);
				t = ts.get();
				break;

				/*
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/

			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression(){

	double left = term();
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void clean_up_mess(){
	ts.ignore(print);
}

double declaration(){
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression(); // 
	define_name(var_name, d);
	return d;
}

double statement(){
	Token t = ts.get();
	switch(t.kind){
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void calculate(){
	
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << "=" << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() 

try {

	define_name("k", 1000);
	
	calculate();

	return 0;
} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}