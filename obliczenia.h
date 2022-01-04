#ifndef OBLICZENIA_H
#define OBLICZENIA_H
//#include "mainwindow.h"
#include <string>
#include <iostream>
#include <QtCore>

class obliczenia
{
public:

    double rezystorym1(int D, double mnoznik);
    QString rezystorym2(int D, QString mnoznikk);
    double rezystory1(int A, int B, int C, int D, int E, double mnoznik, double wynikowa);
    double rezystory2(int mnoznikk, double wynikowa, int nowymnoznik);
    double rezystory3(double wartosc, double wynikowa);
    double tolerance(int E, double tolerance);
    QString mnoznikkkkk(QString wartoscmnoznika, int nowymnoznik);

};

#endif // OBLICZENIA_H

