#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regs.h"
#include "alu.h"
#include "ssi.h"
#include "inst.h"
#include "QSerialPort"
#include "QtSerialPort/QSerialPortInfo"
#include "other.h"

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
    void printInst();
    void printOther();
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();
    void receiveinfo();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Regs* regs;
    Alu* alu;
    Ssi* ssi;
    Package * pkg;
    Inst *inst;
    Other *other;
    int outputbit;
};

#endif // MAINWINDOW_H
