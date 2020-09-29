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
    double num;
    vector<double> szamok;
    vector<string> meretek;
    string meret;
    string stop;
    vector<double> atvaltott;
    double sum = 0;
    vector<double> valtasSzam;

     while(stop !="|")
    { 
        cout << "Ha szeretné folytatni akkor nyomjon meg egy tetszöleges billentyűt, ha megállitani szeretné a programot írja be | -t." << endl;
        cin >> stop;
        if(stop == "|")
        {
            break;
        }


        cout << "Írjon egy számot: " << endl;
        cin >> num;

        while(!cin)
        {
            cout << "Ez nem szám, kérem írjon számot!" << endl;

            cin.clear();
            cin.ignore();
            cin >> num;

        }
        szamok.push_back(num);
        // ha szám => be kerula ("listába") vektorba.


        cout << "Kérem adjon meg egy méretet. (pl: cm, in, ft, m)" << endl;
        cin >> meret;

        while( meret != "cm" and meret != "in" and meret != "ft" and meret != "m")
        {
            cout << "Ez nem egy, a megadott mértéke egységekből, kérem ezek közzül válasszon (cm, in, ft, m) " << endl;
            
            cin.clear();
            cin.ignore();
            cin >> meret;
        }
        meretek.push_back(meret);
        //ha a megadott mérték egységek közűl lett be írva => be kerül a vektorba.

        if(meret == "cm")
        {
            num /= 100;
            sum += num;
            atvaltott.push_back(num);

        }
        if(meret == "in") 
        {
            num = num * 0.0254;
            sum += num;
            atvaltott.push_back(num);

        }if(meret == "ft")
        {
           num = (num *12) * (0.0254);
            sum += num;
            atvaltott.push_back(num);

        }if(meret == "m")
        {
            num = num;
            sum += num;
            atvaltott.push_back(num);
        }
     
        if(atvaltott.size() > 1)
        {

        cout << "A legkisebb szám: " << *min_element(atvaltott.begin(), atvaltott.end()) << " m" << endl; 

        cout << "A legnagyobb szám: " << *max_element(atvaltott.begin(), atvaltott.end()) << " m" << endl; 
    
        }

    }

        for (int i = 0; i < atvaltott.size(); ++i)
        {
            sort(atvaltott);
            cout << atvaltott[i] << " " << "m" << endl; //rendezett kiíratás
        }
    
    cout << "Az összértékük: " << sum << endl;
	return 0;
        

}