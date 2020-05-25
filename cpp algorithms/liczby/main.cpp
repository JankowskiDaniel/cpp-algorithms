#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int silnia(int l)
{
    int silnia=1;
    for(int i=1; i<=l; i++)
    {
        silnia*=i;
    }
    return silnia;
}

int nwd(int a, int b)
{
    while(a!=b)
        if(a>b) a=a-b;
        else b=b-a;
    return a;
}

int main()
{
    fstream plik;
    int liczba=0;
    int potegi_trojki=0;
    plik.open("liczby.txt", ios::in);
    for(int i=1; i<=500; i++)
    {
        plik>>liczba;
        for(int j=0; j<=11; j++)
        {
            if(pow(3,j)==liczba) potegi_trojki++;
        }
        int pom=liczba;
        int suma_silni=0;
        while(pom>0)
        {
            suma_silni+=silnia(pom%10);
            pom=pom/10;
        }
        if(suma_silni==liczba) cout<<liczba<<endl;

    }
    cout<<potegi_trojki<<endl;

    return 0;
}
