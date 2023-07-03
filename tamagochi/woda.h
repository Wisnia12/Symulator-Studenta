#include "alkohol.h"
#include "student.h"
#ifndef WODA_H
#define WODA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

static int ilosc_w;

class woda : public alkohol
{
    public:
        void kup(student* &s1);
        void wypij(student* &s1);
        woda();
        virtual ~woda();
    protected:
    private:
};

#endif // WODA_H
