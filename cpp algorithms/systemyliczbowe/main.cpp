#include <iostream>
#include <fstream>

using namespace std;

int na_dziesietny(string a)
{
    int liczba_dziesietna=0;
    int wartosc=1;
    int dodaj;
    int system=int(a[a.length()-1])-48;
    for(int i=a.length()-2; i>=0; i--)
    {
        dodaj=0;
        dodaj=(int(a[i])-48)*wartosc;
        liczba_dziesietna+=dodaj;
        wartosc*=system;
    }
    return liczba_dziesietna;
}

int main()
{
    fstream plik;
    plik.open("liczby.txt", ios::in);
    string liczba;
    int ile_osemkowych=0;
    int zad2=0;
    int zad3=0;
    int suma_osemkowych=0;
    int obecny_maks=0;
    int obecny_min=INT_MAX;
    char system_maxa;
    char system_min;
    for(int i=1; i<=999; i++)
    {
        plik>>liczba;
        if(na_dziesietny(liczba)>obecny_maks)
        {
            obecny_maks=na_dziesietny(liczba);
            system_maxa=liczba[liczba.length()-1];
        }
        if(na_dziesietny(liczba)<obecny_min)
        {
            obecny_min=na_dziesietny(liczba);
            system_min=liczba[liczba.length()-1];
        }





        if(liczba[liczba.length()-1]=='8')
        {
            ile_osemkowych++;
            suma_osemkowych+=na_dziesietny(liczba);
        }
        int flaga=0;
        if(liczba[liczba.length()-1]=='4')
        {
            for(int j=0; j<liczba.length(); j++)
            {
                if(liczba[j]=='0') flaga=1;
            }
            if(flaga==0) zad2++;
        }
        if(liczba[liczba.length()-1]=='2')
        {
            if(liczba[liczba.length()-2]=='0') zad3++;
        }
    }
    cout<<"Liczb osemkowych: "<<ile_osemkowych<<endl;
    cout<<"Zadanie 2: "<<zad2<<endl;
    cout<<"Zadanie 3: "<<zad3<<endl;
    cout<<"Zadanie 4: "<<suma_osemkowych<<endl;
    cout<<"Najwieksza liczba ma system: "<<system_maxa<<" oraz przyjmuje wartosc: "<<obecny_maks<<endl;
    cout<<"Najmniejsza liczba ma system: "<<system_min<<" oraz przyjmuje wartosc: "<<obecny_min<<endl;
    return 0;
}
