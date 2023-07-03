#include "alkohol.h"
#include "student.h"
#ifndef WHISKY_H
#define WHISKY_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

static int ilosc_wh;

class whisky : public alkohol
{
    public:
        void kup(student* &s1);
        void wypij(student* &s1);
        whisky();
        virtual ~whisky();
    protected:
    private:
};

#endif // WHISKY_H
