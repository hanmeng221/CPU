#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regs.h"
#include "alu.h"
#include "ssi.h"
#include "QSerialPort"
#include "QtSerialPort/QSerialPortInfo"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printAlu();
    void printRegs();
    void setPortCombobox();
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();
    void receiveinfo();



private:
    Ui::MainWindow *ui;
    Regs* regs;
    Alu* alu;
    Ssi* ssi;
    Package * pkg;
    int outputbit;
};

#endif // MAINWINDOW_H
