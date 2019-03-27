#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alu = new ALU();
    regs = new Regs();
    this->printAlu();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete alu;
    delete regs;
}

void MainWindow::printAlu()
{
    this->ui->aluTableWidget->setItem(0,0,new QTableWidgetItem("Inst"));
    this->ui->aluTableWidget->setItem(1,0,new QTableWidgetItem("Option"));
    this->ui->aluTableWidget->setItem(2,0,new QTableWidgetItem("Reg1"));
    this->ui->aluTableWidget->setItem(3,0,new QTableWidgetItem("Reg2"));
    this->ui->aluTableWidget->setItem(4,0,new QTableWidgetItem("Result"));
}

void MainWindow::printRegs()
{

}
