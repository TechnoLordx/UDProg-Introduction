#include "std_lib_facilities.h"

int main()
{
    try{

      // Cout << "Success!\n"; // nincs deklarálva a Cout Compile-time error
        cout << "1. Success!\n";

        
      //  cout << "Success!\n; // hiányzik egy " ezért minden uttanna következőt string nek tekint (és sok mindent kiír még miatta) Compile-time error
        cout << "2. Success!\n";


      // cout << "Success" << !\n";
      cout << "3. Success" << "!\n"; 

       
      // cout << success << '\n'; // nincs deklarálva a success Compile-time error
        cout << "4. Success!\n";

   
      // string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; // a v egy int tipusu vektor és az nm vehet fel string tipusut, tipus eltérési hiba Compile-time error

        int res = 7; vector<int> v1(10);
        v1[5] = res; cout << "5. Success!\n";

        
      // vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n"; // nincs eggyezés a vektor hivásra () helyett [] kell Compile-time error
        
        vector<int> v2(10); 
        v2[5] = 7; 
        if (v2[5]!=7) cout << "6. Success!\n";

        
      // if (cond) cout << "Success!\n"; else cout << "Fail!\n"; // cond nincs deklarálva Compile-time error

        bool cond = true;
        if (cond) cout << "7. Success!\n"; 
        else cout << "Fail!\n"; 


      // bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; // logikai hiba

        bool c1 = true; 
        if (c1) cout << "8. Success!\n"; 
        else cout << "Fail!\n";
        

      // string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n"; // nincs deklarálva a boo és => c-se  logikai hiba

        string s1 = "ape";
        bool c2 = "fool"<s1; 
        if (!c2) cout << "9. Success!\n";


      // string s = "ape"; if (s=="fool") cout << "Success!\n"; // nincs lekezelve az else ága (ha nm igaz az állítás)  logikai hiba

        string s2 = "ape"; 
        if (s2 !="fool") cout << "10. uccess!\n";

        
      // string s = "ape"; if (s=="fool") cout < "Success!\n"; // "<<" kell írni logikai hiba

        string s3 = "ape"; 
        if (s3 != "fool") cout << "11. Success!\n"; 


        
      // string s = "ape"; if (s+"fool") cout < "Success!\n"; // az if en belűl egy logikai vizsgálat van  logikai hiba

        string s4 = "ape";
        if (s4 != "fool") cout << "12. Success!\n";

       
      // vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n"; // for(i = 1; i<... logikai hiba o -val végtelen ciklusba kerül

        vector<char> v3(5); 
        for (int i=0; i<v3.size(); ++i)  
            cout << "13. Success!\n";
             
         
      // ector<char> v4(5); for (int i=0; i<=v4.size(); ++i) ; cout << "Success!\n"; // Nincs hiba,  v14.size () időket akarjuk megismételni.

        vector<char> v4(5); 
        for (int i=0; i<v4.size(); ++i)  
            cout << "14. Success!\n";


      //string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i]; // logikai hiba 6? vmi 

        string s5 = "15. Success!\n";
        for (int i=0; i<s5.size(); ++i) cout << s5[i];


      //  if (true) then cout << "Success!\n"; else cout << "Fail!\n"; then nincs deklarálva Compile-time error / Syntax error

        if (true)  cout << "16. Success!\n"; 
        else cout << "Fail!\n";


      //  int x = 2000; char c = x; if (c==2000) cout << "Success!\n"; char tipusu volt a c x pedig int 
        
        int x01 = 2000; int c3 = x01; 
        if (c3==2000) cout << "17. Success!\n";


      //  string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i]; // nincs hiba de s.size() vel kell mert ugy biztos

        string s6 = "18. Success!\n"; 
        for (int i=0; i<s6.size(); ++i) cout << s6[i];


      //  vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; // Compile-time error nincs definiálva a vektor tipusa

        vector<int> v5(5); 
        for (int i=0; i<v5.size(); ++i)  cout << "19. Success!\n";


      // int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n"; //logikai hiba végtelen ciklus

        int i1 = 0;
        int j1 = 9;
        while (i1 < 10)
            ++i1;
            if (j1 < i1)
            cout << "20. Success!\n";

      //  int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n"; // 0 -val való osztás

        int x2 = 2;
        double d = 5/(x2+2);
        if (d == 2*x2+0.5) cout << "21. Success!\n";


      // string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]; // a vektornak string tipusúmnak kell lennie 

        string s01 = "22. Success!\n"; 
        for (int i=0; i<s01.size(); ++i) cout << s01[i];


      //  int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n"; // j nincs deklarálva

        int i2 = 0;
        int j2 = 0;
        while (i2 < 10)
            ++i2;
            if (j2 < i2)
            cout << "23. Success!\n";

      //  int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n"; // d == ,  működik, de csak azért, mert az if feltétel hozzárendelés. Nem tekinthetjük helyesnek.

        int x3 = 4;
        double d2 = 5.0/(x3-2);
            if (d2 == x3/2.0+0.5)
            cout << "24. Success!\n";

      //   cin << "Success!\n"; // roszz operátor, cout  kell , nincs találat erre: "cin << "|Compile-time error

        cout << "25. Success!\n";

        keep_window_open();

        return 0;

    }catch(exception& exc){
        cerr << "error: " << exc.what() << '\n';
        return 1;
    }

    try{

    }catch(...){
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
