#include "obliczenia.h"
#include "mainwindow.h"
#include <iostream>


double obliczenia::rezystorym1(int D, double mnoznik)
{
    if (D==1){
        mnoznik = 1;
    } else if (D==2){
        mnoznik = 10;
    } else if (D==3){
        mnoznik = 100;
    } else if (D==4){
        mnoznik = 1;
    }else if (D==5){
        mnoznik = 10;
    }else if (D==6){
        mnoznik = 100;
    }else if (D==7){
        mnoznik = 1;
    }else if (D==8){
        mnoznik = 10;
    }else if (D==9){
        mnoznik = 100;
    }else if (D==10){
        mnoznik = 1;
    }else if (D==11){
        mnoznik = 0.1;
    }else if (D==12){
        mnoznik = 0.01;
    }
    return mnoznik;
}

QString obliczenia::rezystorym2(int D, QString mnoznikk)
{
    if (D==1){
        mnoznikk = " ";
    } else if (D==2){
        mnoznikk = " ";
    } else if (D==3){
        mnoznikk = " ";
    } else if (D==4){
        mnoznikk = "k";
    }else if (D==5){
        mnoznikk = "k";
    }else if (D==6){
        mnoznikk = "k";
    }else if (D==7){
        mnoznikk = "M";
    }else if (D==8){
        mnoznikk = "M";
    }else if (D==9){
        mnoznikk = "M";
    }else if (D==10){
        mnoznikk = "G";
    }else if (D==11){
        mnoznikk = " ";
    }else if (D==12){
        mnoznikk = " ";
    }
    return  mnoznikk;
}

double obliczenia::tolerance(int E, double tolerance){

    if (E==1) {
        tolerance = 1 ;
    } else if (E==2) {
        tolerance =2 ;
    } else if (E==3){
        tolerance = 0.5;
    } else if (E == 4) {
        tolerance = 0.25;
    } else if (E==5){
        tolerance = 0.1;
    } else if (E==6){
        tolerance = 0.05;
    } else if (E == 7){
        tolerance = 5;
    } else if (E == 8){
        tolerance = 10;
    }
    return tolerance;
}

double obliczenia::rezystory1(int A, int B, int C, int D, int E, double mnoznik, double wynikowa){

    if (A!=0 && C!=0 && B!=0 && D!=0 && E!=0){
        wynikowa = (((A-1)*100+(B-1)*10+(C-1))*mnoznik);
    }
    else if (A!=0 && C==0 && B!=0 && D!=0 && E!=0){
        wynikowa = ((A-1)*10+(B-1))*mnoznik;
    }
    else {
        wynikowa = 0;
    }
    return wynikowa;
}

/*double obliczenia::rezystory2(int mnoznikk, double wynikowa, int nowymnoznik){
nowymnoznik = mnoznikk;
    if (wynikowa>1000){
        nowymnoznik = nowymnoznik + 1;
    }
    return nowymnoznik;
}*/

double obliczenia::rezystory3(double wartosc, double wynikowa){

    if (wynikowa>1000){
        wartosc = wynikowa/1000;
    } else wartosc = wynikowa;
    return wartosc;
}

/*QString obliczenia::mnoznikkkkk(QString wartoscmnoznika, int nowymnoznik){

    if (nowymnoznik==1){
        wartoscmnoznika= " ";
    }else if (nowymnoznik == 2){
        wartoscmnoznika = "k";
    }else if (nowymnoznik == 3){
        wartoscmnoznika = "M";
    }else if (nowymnoznik == 4){
        wartoscmnoznika = "G";
    }
    return wartoscmnoznika;

}*/
