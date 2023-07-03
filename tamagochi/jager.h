#ifndef JAGER_H
#define JAGER_H
#include "alkohol.h"
#include "student.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

static int ilosc_j;

class jager : public alkohol
{
    public:
        void kup(student* &s1);
        void wypij(student* &s1);
        jager();
        virtual ~jager();
    protected:
    private:
};

#endif // JAGER_H
