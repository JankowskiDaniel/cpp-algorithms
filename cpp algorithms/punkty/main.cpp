#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool pierwsza(int a)
{
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i==0) return false;
    }
    return true;
}

int main()
{
    fstream plik;
    plik.open("punkty.txt", ios::in);
    int x;
    int y;
    string x1;
    string y1;
    int zad1=0;
    int x[1000];
    int y[1000];
    for(int i=1; i<=1000; i++)
    {
        plik>>x;
        plik>>y;

        if(pierwsza(x) && pierwsza(y)) zad1++;


    }
    cout<<"Zadanie 1: "<<zad1<<endl;
    return 0;
}
