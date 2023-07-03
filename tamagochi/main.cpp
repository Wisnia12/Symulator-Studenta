#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "student.h"
#include "alkohol.h"
#include "jager.h"
#include "woda.h"
#include "whisky.h"

using namespace std;

alkohol* a1;
student* s1;


void usun(student* &s1)
{
    ofstream a("student.txt" , ios::trunc);
    a << "" << endl;
    ofstream b("jager.txt" , ios::trunc);
    b << 0;
    ofstream c("woda.txt" , ios::trunc);
    c << 0;
    ofstream d("whisky.txt" , ios::trunc);
    d << 0;
    delete s1;
}

int pokaz_al()
{
    int j, w, wh, wybor_al, wybor_kup;
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
    cout << "Wybierz alkohol:" << endl;
    cout << "############-BAREK-##########" << endl;
    cout << "1.Jagery: " << j << endl;
    cout << "2.Vodki: " << w << endl;
    cout << "3.Whisky: " << wh << endl;
    cout << "4.Anuluj" << endl;
    cin >> wybor_al;
    return wybor_al;
}

int kup_al()
{
    int wyb;
    cout << "$$$$$$$$$$$-SKLEP-$$$$$$$$$$" << endl;
    a1 = new jager;
    cout << "1.Jager - cena: " << a1->cena << " " << a1->procenty << "%" << endl;
    delete a1;
    a1 = new woda;
    cout << "2.Vodka - cena: " << a1->cena << " " << a1->procenty << "%" << endl;
    delete a1;
    a1 = new whisky;
    cout << "3.Whisky - cena: " << a1->cena << " " << a1->procenty << "%" << endl;
    delete a1;
    cout << "4.Anuluj" << endl;
    cin >> wyb;
    return wyb;
}

int main()
{

    int wybor, wybor_al, wybor_kup;
    s1 = new student;
    s1->bio(s1);
    for(int i =1;i>0;i++)
    {
        cout << "**************-MENU-**************" << endl;
        cout << "1.Pokaz bio studenta" <<endl;
        cout << "2.Kup alkohol" << endl;
        cout << "3.Wypij alkohol" << endl;
        cout << "4.Pracuj" << endl;
        cout << "5.Spij" << endl;
        cout << "6.Poczekaj i wytrzezwiej" << endl;
        cout << "7.Idz na studia" << endl;
        cout << "8.Usun zapis" << endl;
        cout << "9.Wyjdz z gry" << endl;
        cin >> wybor;
        switch (wybor)
        {
        case 1:

            s1->bio(s1);
            break;

        case 2:

            wybor_kup = kup_al();
            switch (wybor_kup)
            {
            case 1:

                a1 = new jager;
                a1->kup(s1);
                delete a1;
                break;

            case 2:


                a1 = new woda;
                a1->kup(s1);
                delete a1;
                break;

            case 3:

                a1 = new whisky;
                a1->kup(s1);
                delete a1;
                break;

            case 4:

                break;

            default:

                cout << "Nie ma takiej opcji" << endl;

            }
            break;

        case 3:

            wybor_al = pokaz_al();
            switch (wybor_al)
            {
            case 1:

                a1 = new jager;
                a1->wypij(s1);
                delete a1;
                break;

            case 2:

                a1 = new woda;
                a1->wypij(s1);
                delete a1;
                break;

            case 3:

                a1 = new whisky;
                a1->wypij(s1);
                delete a1;
                break;

            case 4:

                break;

            default:

                cout << "Nie ma takiej opcji" << endl;

            }
            break;

        case 4:

            s1->pracuj(s1);
            break;

        case 5:
            s1->spij(s1);
            break;

        case 6:
            s1->trzezwiej(s1);
            break;

        case 7:
            s1->studia(s1);
            break;

        case 8:
            int z;
            cout << "Czy napewno chcesz usunac zapis gry?" << endl;
            cout << "1.TAK\n2.NIE" << endl;
            cin >> z;
            switch(z)
            {
            case 1:
                {
                    usun(s1);
                    s1 = new student;
                    s1->bio(s1);
                    break;
                }
            case 2:
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;
            }
            break;

        case 9:
            int w;
            cout << "Czy napewno chcesz wyjsc z gry?" << endl;
            cout << "1.TAK\n2.NIE" << endl;
            cin >> w;
            switch (w)
            {
            case 1:
                {

                    ofstream a("student.txt" , ios::trunc);
                    a << s1->imie << endl;
                    a << s1->pieniadze << endl;
                    a << s1->stan_emoc << endl;
                    a << s1->stan_fiz << endl;
                    a << s1->ilosc_alk << endl;
                    a << s1->stan_najeb << endl;
                    a << s1->dni << endl;
                    a << s1->czas << endl;
                    exit(0);
                }
            case 2:
                break;

            default:
                cout << "Nie ma takiej opcji" << endl;
                break;
            }

            break;

        default:

            cout << "Nie ma takiej opcji" << endl;
            break;

        }

    }


    return 0;
}
