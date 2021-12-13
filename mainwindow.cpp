#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>
#include <QSizePolicy>
#include <QPixmap>

double wartosc;
double tolerance;
QString wynik;
int A; //wartosc pasaka pierwszego
int B; //wartosc pasaka drugiego
int C; //wartosc pasaka Trzeciego
int D; // wartosc paska czwartego
int E;
double mnoznik;
int mnoznikk;
QString wartoscmnoznika;
QString wynikk;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix (":/images/4paski.png");
    int w = ui->obraz->width();
    int h = ui->obraz->height();
    ui->obraz->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));



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

    wynik = (QString::number(wartosc) + QString(wartoscmnoznika)+ "  " + "Ohms");
    wynikk = ("tolerancja: ±" + QString::number(tolerance) + "%");

    }else {
        wynik = ("Błąd");
        wynikk = ("Błąd");
    }
    ui->label->setText(wynik);
    ui->label_2->setText(wynikk);

}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file ("D:/telekomunikacja/Semestry/Moje/Semestr 3/Programowanie aplikacyjne/Projekt/1/kalkulatorelektroniczny/file.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){ // metoda open w otwiera plik w trybie tylko do odczytu z zamianą znaków \r\n ma \n
        QTextStream out(&file);

        out << ui->pasek1->currentText() + " | " +  ui->pasek2->currentText() + " | " +  ui->pasek3->currentText() + " | " +  ui->pasek4->currentText()+ " | " +  ui->pasek5->currentText() + " | " + wynik + " | "+ wynikk;
        file.close();
    }

}

