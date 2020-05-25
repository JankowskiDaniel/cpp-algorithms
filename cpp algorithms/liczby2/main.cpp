#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int nwdf(int a, int b)
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
    int liczba2=0;
    int obecna_dl=1;
    int obecny_max=obecna_dl;
    int obecne_nwd=0;
    int poczatek=0;
    int koniec=0;
    int nwd=0;
    int ob_koniec=0;
    int ob_koniec_max =0;
    int ob_poczatek_max =0;
    int T[500];
    plik.open("liczby.txt", ios::in);
    for(int i=0; i<500; i++)
    {
        plik>>T[i];
    }
    obecne_nwd=nwdf(T[0],T[1]);
    int ob_poczatek=T[0];
    for(int i=2; i<500; i++)
    {
        nwd=nwdf(T[i-1],T[i]);
        if(nwd==obecne_nwd)
        {
            obecna_dl++;
            ob_koniec=T[i];
            if(obecna_dl>obecny_max)
            {
                obecny_max=obecna_dl;
                ob_koniec_max = ob_koniec;
                ob_poczatek_max=ob_poczatek;
            }
        } else
            {
                obecne_nwd=nwd;
                ob_poczatek=T[i];
                obecna_dl=2;
            }
    }
    cout<<"Najdluzszy ciag ma dl.: "<<obecny_max<<" Zaczyna sie: "<<ob_poczatek_max<<" i konczy na: "<<ob_koniec_max<<endl;



    return 0;
}
