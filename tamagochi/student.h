#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;


class student
{
    public:
        string imie;
        int ilosc_alk, pieniadze, stan_emoc, stan_fiz, stan_najeb, wiedza, dni, czas;
        void kup();
        void pij();
        void pracuj(student* &s1);
        void spij(student* &s1);
        void bio(student* &s1);
        void sprawdz(student* &s1);
        void trzezwiej(student* &s1);
        void studia(student* &s1);
        student();
        int licz();
        virtual ~student();
};

#endif // STUDENT_H
