#include "std_lib_facilities.h"

int main()
{
//1
	cout << "Enter the name of the person you want to write to" << endl;
	string first_name;
	cin >> first_name;

	cout << "Dear " << first_name << "," << endl;
//2,

	cout << "\tHow are you? I miss you." << endl;
//3,

    string friend_name;
    cout << "Please enter your friend's name .\n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";
//4,

    cout << "If your friend is male enter m  if your friend is female enter f\n";
    char  friend_sex = '0';
    cin >> friend_sex;

    if(friend_sex == 'm')
    	cout << "If you see "<< friend_name << " please ask him to call me.\n";

    if(friend_sex == 'f')
    	cout << "If you see "<< friend_name << " please ask her to call me.\n";
//5,

    cout << "Please enter your age.\n";

     int age =0;
     cin >> age ;

     if(age <= 0 || age >= 110)
       simple_error("you're kidding!");

     else{
     
     	cout << "I hear you just had a birthday and you are " << age << " years old.\n";

//6,

     if(age == 12)
     	cout <<"Next year you will be " << age +1 << endl;
     	
     if(age == 17)
     	cout <<"Next year you will be able to vote.\n";
     	
     if(age >= 70)
     	cout <<"I hope you are enjoying retirement.\n";

     cout << "Yours sincerely\n\n" << endl;

     cout << "Illés Zoltán Levente\n";


	}return 0;
}
