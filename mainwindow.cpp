#include "obliczenia.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>
#include <QSizePolicy>
#include <QPixmap>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    obliczenia paski;  // //wywołanie klasy
    paski.rezystorym1(D, mnoznik); // wywołanie metody na obiektach
    mnoznik = paski.rezystorym1(D, mnoznik); //przypisanie tego co zwraca do zmiennej
    paski.rezystorym2(D, mnoznikk);
    mnoznikk = paski.rezystorym2(D, mnoznikk);
    paski.tolerance(E, tolerance);
    tolerance = paski.tolerance(E, tolerance);
    paski.rezystory1(A, B, C, D, E, mnoznik, wynikowa);
    wartosc = paski.rezystory1(A, B, C, D, E, mnoznik, wynikowa);


    if (wartosc != 0)
    {
        wynik = (QString::number(wartosc) + QString(mnoznikk)+ "  " + "Ohms");
        wynikk = ("tolerancja: ±" + QString::number(tolerance) + "%");

    } else {
        wynik = ("Błąd");
        wynikk = ("Błąd");
    }

    ui->label->setText(wynik);
    ui->label_2->setText(wynikk);

}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file ("D:/telekomunikacja/Semestry/Moje/Semestr 3/Programowanie aplikacyjne/Projekt/1/kalkulatorelektroniczny/file.txt");

    if(file.open(QIODevice::Append | QIODevice::Text)){ // metoda open w otwiera plik w trybie tylko do odczytu z zamianą znaków \r\n ma \n
        QTextStream out(&file);

        out << ui->pasek1->currentText() + " | " +  ui->pasek2->currentText() + " | " +  ui->pasek3->currentText() + " | " +  ui->pasek4->currentText()+ " | " +  ui->pasek5->currentText() + " | " + wynik + " | "+ wynikk + " \n";
        file.close();
    }

}


void MainWindow::on_pasek1_currentIndexChanged()
{
    A = ui->pasek1->currentIndex();
}

void MainWindow::on_pasek2_currentIndexChanged()
{
    B = ui->pasek2->currentIndex();
}

void MainWindow::on_pasek3_currentIndexChanged()
{
    C = ui->pasek3->currentIndex();
}

void MainWindow::on_pasek4_currentIndexChanged()
{
    D = ui->pasek4->currentIndex();
}

void MainWindow::on_pasek5_currentIndexChanged()
{
    E = ui->pasek5->currentIndex();
}
