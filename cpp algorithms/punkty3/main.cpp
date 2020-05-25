#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main()
{
    fstream plik;
    plik.open("punkty.txt", ios::in);
    int x[1000];
    int y[1000];
    int dl;
    int max_dl=0;
    int max_x1;
    int max_y1;
    int max_x2;
    int max_y2;
    for(int i=0; i<1000; i++)
    {
        plik>>x[i];
        plik>>y[i];
    }
    for(int j=0; j<1000; j++)
    {
        for(int k=0; k<1000; k++)
        {
            dl=0;
           if(j!=k)
           {
               dl=pow((x[j]-x[k]),2)+pow((y[j]-y[k]),2);
               if(dl>max_dl)
               {
                   max_dl=dl;
                   max_x1=x[j];
                   max_y1=y[j];
                   max_x2=x[k];
                   max_y2=y[k];
               }
           }
        }
    }
    cout<<"Najdluzszy odcinek: "<<endl;
    cout<<"x1: "<<max_x1<<" y1: "<<max_y1<<endl;
    cout<<"x2: "<<max_x2<<" y2: "<<max_y2<<endl;
    cout<<"Odleglosc wynosi: "<<round(sqrt(max_dl))<<endl;
    return 0;
}

