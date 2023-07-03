#include "whisky.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "alkohol.h"

whisky::whisky()
{
    cena = 85;
    procenty = 40;
}

whisky::~whisky()
{
    //dtor
}
void whisky::kup(student* &s1)
{
    if(s1->pieniadze<85)
    {
        cout << "Nie masz pieniedzy" << endl;
    }
    else
    {

        fstream s;
        s.open("whisky.txt", fstream::in);
        s >> ilosc_wh;
        ilosc_wh+=1;
        s.close();
        ofstream d("whisky.txt", ios::trunc);
        d << ilosc_wh;
        s1->pieniadze -=85;
        cout << "Kupiles whisky" << endl;
    }

}

void whisky::wypij(student* &s1)
{
    fstream s;
    s.open("whisky.txt", fstream::in);
    s >> ilosc_wh;
    if(ilosc_wh==0)
    {
        cout << "Nie masz Whisky." << endl;
    }
    else
    {
        ilosc_wh-=1;
        s.close();
        ofstream d("whisky.txt", ios::trunc);
        d << ilosc_wh;
        cout << "Na zdrowie!" << endl;
        s1->stan_najeb +=1;
        if(s1->stan_najeb >3)
        {
            s1->stan_najeb = 3;
        }
    }
}
