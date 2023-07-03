#ifndef ALKOHOL_H
#define ALKOHOL_H
#include "student.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;



class alkohol
{
    public:
        int procenty = 0, cena = 0;
        virtual void kup(student* &s1);
        virtual void wypij(student* &s1);
};

#endif // ALKOHOL_H
