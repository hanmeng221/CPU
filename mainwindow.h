#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regs.h"
#include "alu.h"

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

private:
    Ui::MainWindow *ui;
    Regs* regs;
    ALU* alu;
    int outputbit;
};

#endif // MAINWINDOW_H
