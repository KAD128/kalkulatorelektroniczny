#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double wartosc;
    double tolerance;

    double wynikowa;
    QString wynik;
    QString wynikk;
    int blad=0;
    int A; //wartosc pasaka pierwszego
    int B; //wartosc pasaka drugiego
    int C; //wartosc pasaka Trzeciego
    int D; // wartosc paska czwartego
    int E;
    double mnoznik;
    QString mnoznikk;
    int nowymnoznik = 0;
    QString wartoscmnoznika;


private slots:

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pasek1_currentIndexChanged();
    void on_pasek2_currentIndexChanged();
    void on_pasek3_currentIndexChanged();
    void on_pasek4_currentIndexChanged();
    void on_pasek5_currentIndexChanged();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
