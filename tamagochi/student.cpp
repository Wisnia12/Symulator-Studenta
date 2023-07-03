#include "student.h"
#include <iostream>
#include "alkohol.h"
#include "jager.h"
#include "woda.h"
#include "whisky.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
void usun(student* &s1);
int dodaj;


student::student()
{
    string i, j;
    ifstream f;
    f.open("student.txt");
    getline(f, i);
    if(i.length() == 0)
    {

        cout << "Podaj imie: " << endl;
        cin >> imie;
        ofstream s("student.txt", ios::trunc);
        s << imie << endl;
        pieniadze = 500;
        stan_emoc = 2;
        stan_fiz = 2;
        ilosc_alk = 0;
        stan_najeb = 0;
        wiedza = 0;
        dni = 2;
        czas = 12;
    }
    else
    {
        imie = i;
        getline(f,j);
        pieniadze = stoi(j);
        getline(f,j);
        stan_emoc = stoi(j);
        getline(f,j);
        stan_fiz = stoi(j);
        getline(f,j);
        ilosc_alk = stoi(j);
        getline(f,j);
        stan_najeb = stoi(j);
        getline(f,j);
        dni = stoi(j);
        getline(f,j);
        czas = stoi(j);
    }

    cout << "Twoj student ma na imie " << imie << endl;

    f.close();
}

student::~student()
{

}

void student:: bio(student* &s1)
{
    s1->sprawdz(s1);

    cout << "------------------BIO-------------------" << endl;
    cout << "Stan konta: " << pieniadze << endl;
    switch (stan_emoc)
    {
    case 0:
        cout << "Czuje sie fatalnie" << endl;
        break;
    case 1:
        cout << "Czuje sie zle" << endl;
        break;
    case 2:
        cout << "Czuje sie nawet dobrze" << endl;
        break;
    case 3:
        cout << "Czuje sie dobrze" << endl;
        break;
    case 4:
        cout << "Czuje sie wysmienicie" << endl;
        break;

    }

    switch (stan_fiz)
    {
    case 0:
        cout << "Jestem padniety" << endl;
        break;
    case 1:
        cout << "Jestem zmeczony" << endl;
        break;
    case 2:
        cout << "Jestem w dobrm stanie" << endl;
        break;
    case 3:
        cout << "Jestem wypoczety" << endl;
        break;
    }
    cout << "Mam " << licz() << " butelek alkoholu" << endl;
    switch (stan_najeb)
    {
    case 0:
        cout << "Jestm trzezwy" << endl;
        break;
    case 1:
        cout << "Jestm podchmielony" << endl;
        break;
    case 2:
        cout << "Jestm pijany" << endl;
        break;
    case 3:
        cout << "Juz nie kontaktuje" << endl;
        break;
    }
    cout << "Dni bez studiow: ";
    switch(dni)
    {
    case 0:
        cout << "2"<< endl;
        break;
    case 1:
        cout << "1" << endl;
        break;
    case 2:
        cout << "0" << endl;
    }
    cout << "Jest godzina " << czas << endl;

}
int student:: licz()
{
    int suma, j, w, wh;
    fstream s;
    s.open("jager.txt", fstream::in);
    s >> j;
    s.close();
    s.open("woda.txt", fstream::in);
    s >> w;
    s.close();
    s.open("whisky.txt", fstream::in);
    s >> wh;
    s.close();
    suma = j+w+wh;
    return suma;
}
void student:: sprawdz(student* &s1)
{
    if(s1->stan_najeb < 0)
    {
        s1->stan_najeb = 0;
    }
    if(s1->stan_emoc > 4)
    {
        s1->stan_emoc = 4;
    }
    if(s1->stan_fiz < 0)
    {
        s1->stan_fiz = 0;
    }
    if(s1->dni > 2)
    {
        s1->dni = 2;
    }
    if(s1->czas>23)
    {
        s1->czas -=24;
        s1->dni-=1;
    }
    s1->stan_emoc = 2*s1->stan_najeb + s1->stan_fiz;
    ilosc_alk = licz();
    if(s1->stan_emoc == 0 && s1->pieniadze <35 && s1->ilosc_alk == 0)
    {
        cout << "!!!!!!!!!!!!!PORAZKA!!!!!!!!!!!!!\nJestes biedny i dostales depresji." << endl;
        usun(s1);
        s1 = new student;
    }
    if(s1->dni <0)
    {
        cout << "!!!!!!!!!!!!!PORAZKA!!!!!!!!!!!!!" << endl;
        cout << "Wyrzucili mnie z PUTu" << endl;
        usun(s1);
        s1 = new student;
    }
}

void student::pracuj(student* &s1)
{
    if(s1->czas>7 && s1->czas<23)
    {


        if(s1->stan_najeb<2 && s1->stan_fiz>0)
        {
            cout << "Glupia robota" << endl;

            s1->stan_fiz -= 1;
            s1->stan_najeb -= 1;
            dodaj = 23-s1->czas;
            if(dodaj>4)
            {
                dodaj = 4;
            }
            s1->czas+=dodaj;
            s1->pieniadze += dodaj*15;

        }
        else
            if(s1->stan_najeb > 1 && s1->stan_fiz == 0)
            {
                cout << "Jestes zbyt pijany i zbyt zmeczony zeby pracowac" << endl;
            }
            else
            {
                if(s1->stan_najeb > 1)
                {
                    cout << "Jestes zbyt pijany zeby pracowac" << endl;
                }
                else
                {
                    cout << "Jestes zbyt zmeczony zeby pracowac" << endl;
                }
            }
    }
    else
    {
        cout << "Firma nie pozwala pracowac o tej godzinie" << endl;
    }

        s1->sprawdz(s1);
}
void student::spij(student* &s1)
{
    if(s1->stan_fiz < 3)
    {
        cout << "Dobranoc" << endl;
        s1->stan_fiz +=2;
        s1->stan_najeb -=3;
        s1->czas+=7;
    }
    else
    {
        cout << "Nie chce ci sie spac" << endl;
    }

    s1->sprawdz(s1);
}

void student::trzezwiej(student* &s1)
{
    cout << "Lepiej troche wytrzezwieje" << endl;
    s1->stan_najeb -=2;
    s1->stan_fiz-=1;
    czas+=3;
    s1->sprawdz(s1);
}

void student::studia(student* &s1)
{
    if(s1->czas>7 && s1->czas < 21)
    {


        if(s1->stan_fiz>0 && s1->stan_najeb<2)
        {
            cout << "Ehh znowu ten PUT" << endl;
            s1->stan_fiz-=1;
            s1->stan_najeb-=1;
            s1->wiedza+=1;
            s1->dni+=1;
            dodaj = 21- s1->czas;
            if(dodaj > 8)
            {
                dodaj = 8;
            }
            s1->czas+=dodaj;

        }
        else
        {
            if(s1->stan_fiz == 0)
            {
                cout << "Jestem zbyt zmeczony zeby isc na studia" << endl;
            }
            else
            {
                if(s1->stan_najeb < 3)
                {
                    cout << "Jesetm tak pijany ze nie rozumiem co gadaja, niczego sie nie nauczylem" << endl;
                    s1->stan_najeb-=1;
                    s1->stan_fiz-=1;
                    s1->dni+=1;
                    dodaj = 21- s1->czas;
                    if(dodaj > 8)
                    {
                        dodaj = 8;
                    }
                    s1->czas+=dodaj;

                }
                else
                {
                    cout << "!!!!!!!!!!!!!PORAZKA!!!!!!!!!!!!!" << endl;
                    cout << "Wyrzucili mnie z PUTu bo po pijaku zniszczylem komputery i pobilem sie z wykladowca" << endl;
                    usun(s1);
                    s1 = new student;
                }

            }
        }
    }
    else
    {
        cout << "Studia sa zamkniete o tej godzinie" << endl;
    }

    s1->sprawdz(s1);
}
