#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>

double wartosc;
QString mnoznik;
QString wartoscpaskapierwszego;
QString tekst;
int kolorpaskapierwszego;
QString kolorpaskadrugiego;
QString kolorpaskatrzeciego;
QString kolorpaskaczwartego;
QString kolorpaskapiatego;
int wartoscliczbowapaskapierwszego;
int A; //wartosc pasaka pierwszego
int B; //wartosc pasaka drugiego
int C; //wartosc pasaka Trzeciego



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wartosc = 10;
    mnoznik = "wartość mnożnika";


        ui->pasek1->addItem(QString::number(0)); ui->pasek1->addItem(QString::number(1) + " Czarny"); ui->pasek1->addItem(QString::number(2) + " Brązowy");
        ui->pasek1->addItem(QString::number(3) + " Czerwony"); ui->pasek1->addItem(QString::number(4) + " Pomarańcz"); ui->pasek1->addItem(QString::number(5) + " Zółty");
        ui->pasek1->addItem(QString::number(6) + " Zielony");  ui->pasek1->addItem(QString::number(7) + " Niebieski"); ui->pasek1->addItem(QString::number(8) + " Fioletowy");
        ui->pasek1->addItem(QString::number(9) + " Szary");  ui->pasek1->addItem(QString::number(10) + " Biały"); ui->pasek1->currentText();


        ui->pasek2->addItem(QString::number(0)); ui->pasek2->addItem(QString::number(1) + " Czarny"); ui->pasek2->addItem(QString::number(2) + " Brązowy");
        ui->pasek2->addItem(QString::number(3) + " Czerwony"); ui->pasek2->addItem(QString::number(4) + " Pomarańcz"); ui->pasek2->addItem(QString::number(5) + " Zółty");
        ui->pasek2->addItem(QString::number(6) + " Zielony");  ui->pasek2->addItem(QString::number(7) + " Niebieski"); ui->pasek2->addItem(QString::number(8) + " Fioletowy");
        ui->pasek2->addItem(QString::number(9) + " Szary");  ui->pasek2->addItem(QString::number(10) + " Biały"); ui->pasek2->currentText();

        ui->pasek3->addItem(QString::number(0)); ui->pasek3->addItem(QString::number(1) + " Czarny"); ui->pasek3->addItem(QString::number(2) + " Brązowy");
        ui->pasek3->addItem(QString::number(3) + " Czerwony"); ui->pasek3->addItem(QString::number(4) + " Pomarańcz"); ui->pasek3->addItem(QString::number(5) + " Zółty");
        ui->pasek3->addItem(QString::number(6) + " Zielony");  ui->pasek3->addItem(QString::number(7) + " Niebieski"); ui->pasek3->addItem(QString::number(8) + " Fioletowy");
        ui->pasek3->addItem(QString::number(9) + " Szary");  ui->pasek3->addItem(QString::number(10) + " Biały"); ui->pasek3->currentText();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{



    kolorpaskapierwszego = ui->pasek1->currentIndex();
    ui->label_4->setText(QString::number(kolorpaskapierwszego));

    A = ui->pasek1->currentIndex();
    B = ui->pasek2->currentIndex();
    C = ui->pasek3->currentIndex();

    if (A==0){
        ui->label->setText("Błąd");
      }
    else if ((A!=0&&B!=0)&&C==0) {

        ui->label->setText(QString::number(A*10+B));
    }
    else if ((A!=0&&B!=0)&&C!=0) {
        ui->label->setText(QString::number(A*100+B*10+C));
    }



    //ui->label->setText(QString::number(wartosc));
    ui->label_2->setText(mnoznik);
}

