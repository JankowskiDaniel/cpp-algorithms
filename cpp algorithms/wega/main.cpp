#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

string sortowanie(string a)
{
	for(int i=0;i<a.length();i++)
		for(int j=1;j<a.length()-i;j++)
		if(a[j-1]>a[j])
			swap(a[j-1], a[j]);


    return a;
}

int main()
{
    fstream plik;
    plik.open("sygnaly.txt", ios::in);
    string sygnal;
    string w="";
    string pom="";
    int rozne=0;
    int rozne_max=rozne;
    string sygnal_max="";
    int flaga=0;
    for(int i=1; i<=1000; i++)
    {
        plik>>sygnal;
        //cout<<sygnal<<endl;
        //zadanie1
        if(i>=40 && i%40==0)
        {
            w+=sygnal[9];
        }
        //
        //zadanie2
        rozne=0;
        pom=sortowanie(sygnal);
        for(int j=1; j<=pom.length(); j++)
        {
            if(pom[j-1]!=pom[j]) rozne++;
        }
        if(rozne>rozne_max)
        {
            rozne_max = rozne;
            sygnal_max=sygnal;
        }
        //zadanie2
        //zadanie3
        flaga=0;
        for(int m=1; m<sygnal.length(); m++)
        {
            if(abs(sygnal[m-1]-sygnal[m])>10)
            {
                flaga=1;
            }
        }
        if(flaga!=1)
        {
            cout<<sygnal<<endl;
        }
    }
    cout<<"Wiadomosc zad1: "<<w<<endl;
    cout<<"Rozne litery: "<<rozne_max<<" To slowo to: "<<sygnal_max<<endl;
    return 0;
}
