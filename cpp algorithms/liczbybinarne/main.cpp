#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int na_dziesietny(string a)
{
    int dziesietna=0;
    int wartosc=1;
    for(int i=a.length()-1; i>=0; i--)
    {
        if(a[i]=='1') dziesietna+=1*wartosc;
        wartosc*=2;
    }

    return dziesietna;
}


int main()
{
    fstream plik;
    plik.open("liczby.txt", ios::in);
    string liczba="";
    int ile_wiecej_zer =0;
    int ile_podzielnych_2 =0;
    int ile_podzielnych_8 =0;
    string obecny_max_string;
    string obecny_min;
    int indeks_max=0;
    int indeks_min=0;

    int obecny_min_int = na_dziesietny(obecny_min);
    for(int i=1; i<=1000; i++)
    {
        plik>>liczba;
        int jedynki=0;
        int zera=0;
        for(int j=0; j<liczba.length(); j++)
        {
            if(liczba[j]=='0') zera++;
            else jedynki++;
        }
        if(zera>jedynki) ile_wiecej_zer++;
        if(liczba[liczba.length()-1]=='0') ile_podzielnych_2++;
        if(na_dziesietny(liczba)%8==0) ile_podzielnych_8++;
        if(liczba.length()>obecny_max_string.length())
        {
            obecny_max_string=liczba;
            indeks_max=i;
        }
        if(liczba.length()==obecny_max_string.length())
        {
            if(liczba>obecny_max_string)
            {
                 obecny_max_string=liczba;
                indeks_max= i;
            }
        }
        if(liczba.length()<obecny_min.length())
        {
            obecny_min=liczba;
            indeks_min=i;
        }
    }
    cout<<"Liczb ktore maja wiecej zer niz jedynek jest: "<<ile_wiecej_zer<<endl;
    cout<<"Liczby, ktore sa podzielne przez 2: "<<ile_podzielnych_2<<endl;
    cout<<"Liczby, ktore sa podzielne przez 8: "<<ile_podzielnych_8<<endl;
    cout<<"Najwieksza: "<<indeks_max<<endl;
    cout<<"Najmniejsza: "<<indeks_min<<endl;
    return 0;
}
