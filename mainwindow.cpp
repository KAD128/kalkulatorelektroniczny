#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>

double wartosc;
double tolerance;
int A; //wartosc pasaka pierwszego
int B; //wartosc pasaka drugiego
int C; //wartosc pasaka Trzeciego
int D; // wartosc paska czwartego
int E;
double mnoznik;
int mnoznikk;
QString wartoscmnoznika;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wartosc = 10;

/*
        ui->pasek1->addItem("Brak"); ui->pasek1->addItem(QString::number(0) + " Czarny"); ui->pasek1->addItem(QString::number(1) + " Brązowy");
        ui->pasek1->addItem(QString::number(2) + " Czerwony"); ui->pasek1->addItem(QString::number(3) + " Pomarańcz"); ui->pasek1->addItem(QString::number(4) + " Zółty");
        ui->pasek1->addItem(QString::number(5) + " Zielony");  ui->pasek1->addItem(QString::number(6) + " Niebieski"); ui->pasek1->addItem(QString::number(7) + " Fioletowy");
        ui->pasek1->addItem(QString::number(8) + " Szary");  ui->pasek1->addItem(QString::number(9) + " Biały"); ui->pasek1->currentText();


        ui->pasek2->addItem("  "); ui->pasek2->addItem(QString::number(0) + " Czarny"); ui->pasek2->addItem(QString::number(2) + " Brązowy");
        ui->pasek2->addItem(QString::number(3) + " Czerwony"); ui->pasek2->addItem(QString::number(4) + " Pomarańcz"); ui->pasek2->addItem(QString::number(5) + " Zółty");
        ui->pasek2->addItem(QString::number(6) + " Zielony");  ui->pasek2->addItem(QString::number(7) + " Niebieski"); ui->pasek2->addItem(QString::number(8) + " Fioletowy");
        ui->pasek2->addItem(QString::number(9) + " Szary");  ui->pasek2->addItem(QString::number(10) + " Biały"); ui->pasek2->currentText();

        ui->pasek3->addItem(QString::number(0)); ui->pasek3->addItem(QString::number(1) + " Czarny"); ui->pasek3->addItem(QString::number(2) + " Brązowy");
        ui->pasek3->addItem(QString::number(3) + " Czerwony"); ui->pasek3->addItem(QString::number(4) + " Pomarańcz"); ui->pasek3->addItem(QString::number(5) + " Zółty");
        ui->pasek3->addItem(QString::number(6) + " Zielony");  ui->pasek3->addItem(QString::number(7) + " Niebieski"); ui->pasek3->addItem(QString::number(8) + " Fioletowy");
        ui->pasek3->addItem(QString::number(9) + " Szary");  ui->pasek3->addItem(QString::number(10) + " Biały"); ui->pasek3->currentText();

        ui->pasek4->addItem(QString::number(0)); ui->pasek4->addItem(QString::number(1) + " Czarny"); ui->pasek4->addItem(QString::number(2) + " Brązowy");
        ui->pasek4->addItem(QString::number(3) + " Czerwony"); ui->pasek4->addItem(QString::number(4) + " Pomarańcz"); ui->pasek4->addItem(QString::number(5) + " Zółty");
        ui->pasek4->addItem(QString::number(6) + " Zielony");  ui->pasek4->addItem(QString::number(7) + " Niebieski"); ui->pasek4->addItem(QString::number(8) + " Fioletowy");
        ui->pasek4->addItem(QString::number(9) + " Szary");  ui->pasek4->addItem(QString::number(10) + " Biały"); ui->pasek4->addItem(QString::number(11) + " Złoty");
        ui->pasek4->addItem(QString::number(12) + " Srebrny"); ui->pasek4->currentText();
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    A = ui->pasek1->currentIndex();
    B = ui->pasek2->currentIndex();
    C = ui->pasek3->currentIndex();
    D = ui->pasek4->currentIndex();
    E = ui->pasek5->currentIndex();

    if (D==1){
        mnoznik = 1;
        mnoznikk = 1;
    } else if (D==2){
        mnoznik = 10;
        mnoznikk = 1;
    } else if (D==3){
        mnoznik = 100;
        mnoznikk = 1;
    } else if (D==4){
        mnoznik = 1;
        mnoznikk = 2;
    }else if (D==5){
        mnoznik = 10;
        mnoznikk = 2;
    }else if (D==6){
        mnoznik = 100;
        mnoznikk = 2;
    }else if (D==7){
        mnoznik = 1;
        mnoznikk = 3;
    }else if (D==8){
        mnoznik = 10;
        mnoznikk = 3;
    }else if (D==9){
        mnoznik = 100;
        mnoznikk = 3;
    }else if (D==10){
        mnoznik = 1;
        mnoznikk = 4;
    }else if (D==11){
        mnoznik = 0.1;
        mnoznikk = 1;
    }else if (D==12){
        mnoznik = 0.01;
        mnoznikk = 1;
    }



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

    if (A==0||B==0||D==0||E==0){
        ui->label->setText("Błąd");
        ui->label_2->setText("?");
      }
    else if (C==0) {
        wartosc = ((A-1)*10+(B-1))*mnoznik;
        if (wartosc>1000){
            wartosc=wartosc/1000;
            mnoznikk++;

        }

    }
    else if (C!=0) {
        wartosc = ((A-1)*100+(B-1)*10+(C-1))*mnoznik;
        if (wartosc>1000){
            wartosc=wartosc/1000;
            mnoznikk++;
        }
        //ui->label->setText(QString::number(wartosc));
        //ui->label_2->setText("±" + QString::number(tolerance) + "%");
    }
    if (mnoznikk==1){
        wartoscmnoznika= " ";
    }else if (mnoznikk == 2){
        wartoscmnoznika = "k";
    }else if (mnoznikk == 3){
        wartoscmnoznika = "M";
    }else if (mnoznikk == 4){
        wartoscmnoznika = "G";
    }

    if(A!=0&&B!=0&&D!=0&&E!=0){
    ui->label->setText(QString::number(wartosc) + QString(wartoscmnoznika)+ "  " + "Ohms");
    ui->label_2->setText("tolerancja: ±" + QString::number(tolerance) + "%");
    }else {
        ui->label->setText("Błąd");
        ui->label_2->setText("Błąd");
    }

}

