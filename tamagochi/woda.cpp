#include "alkohol.h"
#include "woda.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>


woda::woda()
{
    cena = 35;
    procenty = 40;
}

woda::~woda()
{
    //dtor
}
void woda::kup(student* &s1)
{
    if(s1->pieniadze<35)
        {
            cout << "Nie masz pieniedzy" << endl;
        }
        else
        {

            fstream s;
            s.open("woda.txt", fstream::in);
            s >> ilosc_w;
            ilosc_w+=1;
            s.close();
            ofstream d("woda.txt", ios::trunc);
            d << ilosc_w;
            s1->pieniadze -=35;
            cout << "Kupiles vodke" << endl;
        }
}

void woda:: wypij(student* &s1)
{
    fstream s;
    s.open("woda.txt", fstream::in);
    s >> ilosc_w;
    if(ilosc_w==0)
    {
        cout << "Nie masz Vodki." << endl;
    }
    else
    {
        ilosc_w-=1;
        s.close();
        ofstream d("woda.txt", ios::trunc);
        d << ilosc_w;
        cout << "Na zdrowie!" << endl;
        s1->stan_najeb +=1;
        if(s1->stan_najeb >3)
        {
            s1->stan_najeb = 3;
        }
    }
}
