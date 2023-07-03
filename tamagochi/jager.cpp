#include "alkohol.h"
#include "jager.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>



jager::jager()
{
    cena = 50;
    procenty = 35;
}

jager::~jager()
{
    //dtor
}

void jager::kup(student* &s1)
{
    if(s1->pieniadze<50)
    {
        cout << "Nie masz pieniedzy" << endl;
    }
    else
    {

        fstream s;
        s.open("jager.txt", fstream::in);
        s >> ilosc_j;
        ilosc_j+=1;
        s.close();
        ofstream d("jager.txt", ios::trunc);
        d << ilosc_j;
        s1->pieniadze -=50;
        cout << "Kupiles jagera" << endl;
    }

}

void jager::wypij(student* &s1)
{
    fstream s;
    s.open("jager.txt", fstream::in);
    s >> ilosc_j;
    if(ilosc_j==0)
    {
        cout << "Nie masz Jagera." << endl;
    }
    else
    {
        ilosc_j-=1;
        s.close();
        ofstream d("jager.txt", ios::trunc);
        d << ilosc_j;
        cout << "Na zdrowie!" << endl;
        s1->stan_najeb +=1;
        if(s1->stan_najeb >3)
        {
            s1->stan_najeb = 3;
        }

    }
}
