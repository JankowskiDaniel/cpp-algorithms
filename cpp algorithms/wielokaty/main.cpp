#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int kratowe(int a, int b)
{
	int pom;

  	while(b!=0)
	{
    	pom = b;
    	b = a%b;
    	a = pom;
  	}
    return abs(a)-1;
}

int main()
{
    fstream plik;
    plik.open("wielokaty.txt", ios::in);
    int wielokat;
    int x,y;
    int trojkaty=0;
    int pieciokaty=0;
    int odcinek=0;
    int max_odcinek=0;
    int max_x=0;
    int max_y=0;
    int punkty;
    while(!plik.eof())
    {
        plik>>wielokat;
        cout<<wielokat<<endl;
        punkty=wielokat;
        for(int i=0; i<wielokat; i++)
        {
            odcinek=0;
            plik>>x;
            plik>>y;
            odcinek=pow(x,2)+pow(y,2);
            if(odcinek>max_odcinek)
            {
                max_odcinek=odcinek;
                max_x=x;
                max_y=y;
            }
        }
        cout<<punkty<<endl;
        if(wielokat==3) trojkaty++;
        if(wielokat==5) pieciokaty++;
        //kratowe

    }
    cout<<"Liczba trojkatow: "<<trojkaty<<endl;
    cout<<"Liczba pieciokatow: "<<pieciokaty<<endl;
    cout<<"Najmniejszy promien: "<<sqrt(max_odcinek)<<endl;

    return 0;
}
