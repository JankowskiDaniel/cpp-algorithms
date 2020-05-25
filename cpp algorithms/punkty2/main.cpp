#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool czy_zawiera(string a, string b)
{
    int flaga=0;
    for(int i=0; i<a.length(); i++)
    {
        flaga=0;
        for(int j=0; j<b.length(); j++)
        {
            if(a[i]==b[j]) flaga=1;
        }
        if(flaga==0) return false;
    }
    return true;
}

int main()
{
    fstream plik;
    plik.open("punkty.txt", ios::in);
    string x1;
    string y1;
    int zad2=0;
    for(int i=1; i<=1000; i++)
    {
        plik>>x1;
        plik>>y1;
        if(czy_zawiera(x1,y1) && czy_zawiera(y1,x1)) zad2++;


    }
    cout<<"Zadanie 2: "<<zad2<<endl;
    return 0;
}
