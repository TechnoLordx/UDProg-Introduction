#include "std_lib_facilities.h"

int main()
{
/*
    	cout <<"Kérem írjon 2 számot ha szeretné befejezni írja be | -t \n";
 	
    double a;
    double b;
 while(cin >> a >> b){
 	if(a == b){
 		cout << "A számok egyenlőek \n";
 	}else
       	if (a > b) 
        cout << "A nagyobbik szám: " << a << endl;
        if (b > a) 
        cout << "A nagyobbik szám: " << b << endl;
    if(abs(a - b) <= 0.01)
        cout << "Majdnem egyenlő" << endl;
   
    }
*/

    double szam;
    string meret;
    vector<string> joMeretek{"cm", "m", "in", "ft"};
    vector<double> atvaltott;
    double sum = 0;
    bool tartalmaz = false; // vizsgálathoz segéd
    int db = 0;

    cout << "Kérem adjon meg egy számot és hozzá egy méretet ezkközűl válasszon (pl: cm, in, ft, m)" << endl;

     while(cin >> szam >> meret)
    { 
        for (string elem : joMeretek)
        {
            if (meret == elem)
            {

                tartalmaz = true;  

            }
        
        }

        if(tartalmaz){

            db++;

            if(meret == "cm"){}
            {
                szam /= 100;
                sum += szam;
                atvaltott.push_back(szam);

            }
            else if(meret == "in") 
            {
                szam = szam * 0.0254;
                sum += szam;
                atvaltott.push_back(szam);

            }
            else if(meret == "ft")
            {
                szam = (szam *12) * (0.0254);
                sum += szam;
                atvaltott.push_back(szam);

            }
            else if(meret == "m")
            {   
                szam = szam;
                sum += szam;
                atvaltott.push_back(szam);

            }

 
            }else cout << "rossz méretet adott meg kérem ezkközűl válasszon (pl: cm, in, ft, m)" << endl;

            if(atvaltott.size() > 1)
            {

                cout << "A legkisebb szám: " << *min_element(atvaltott.begin(), atvaltott.end()) << " m" << endl; 

                cout << "A legnagyobb szám: " << *max_element(atvaltott.begin(), atvaltott.end()) << " m" << endl; 
            }
               
    }

    cout <<"Ennyi számot irt be: " <<db << endl;

    for (int i = 0; i < atvaltott.size(); ++i)
        {
            sort(atvaltott);
            cout << atvaltott[i] << " " << "m" << endl; //rendezett kiíratás
        }
    
         cout << "Az összértékük: " << sum << endl;
         
return 0;
}
