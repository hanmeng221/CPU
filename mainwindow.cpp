#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->alu = new Alu();
    this->regs = new Regs();
    this->ssi = new Ssi();
    this->pkg = new Package();
    this->other = new Other();
    this->inst = new Inst(this->ui->instTableWidget->rowCount());
    this->setPortCombobox();
    this->outputbit = 16;
    this->printAlu();
    this->printRegs();
    this->printInst();
    this->printOther();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete alu;
    delete regs;
    delete other;
}

void MainWindow::printAlu()
{
    this->ui->aluTableWidget->setItem(0,0,new QTableWidgetItem("Inst"));
    this->ui->aluTableWidget->setItem(1,0,new QTableWidgetItem("Option"));
    this->ui->aluTableWidget->setItem(2,0,new QTableWidgetItem("Reg1"));
    this->ui->aluTableWidget->setItem(3,0,new QTableWidgetItem("Reg2"));
    this->ui->aluTableWidget->setItem(4,0,new QTableWidgetItem("Result"));
    this->ui->aluTableWidget->setItem(0,1,new QTableWidgetItem(this->alu->getShowInst(this->outputbit)));
    this->ui->aluTableWidget->setItem(1,1,new QTableWidgetItem(this->alu->getShowOption()));
    this->ui->aluTableWidget->setItem(2,1,new QTableWidgetItem(this->alu->getShowReg1(this->outputbit)));
    this->ui->aluTableWidget->setItem(3,1,new QTableWidgetItem(this->alu->getShowReg2(this->outputbit)));
    this->ui->aluTableWidget->setItem(4,1,new QTableWidgetItem(this->alu->getShowResult(this->outputbit)));
}

void MainWindow::printRegs()
{
    this->ui->regsTableWidget->setItem(0,0,new QTableWidgetItem("0"));
    this->ui->regsTableWidget->setItem(1,0,new QTableWidgetItem("1"));
    this->ui->regsTableWidget->setItem(2,0,new QTableWidgetItem("2"));
    this->ui->regsTableWidget->setItem(3,0,new QTableWidgetItem("3"));
    this->ui->regsTableWidget->setItem(4,0,new QTableWidgetItem("4"));
    this->ui->regsTableWidget->setItem(5,0,new QTableWidgetItem("5"));
    this->ui->regsTableWidget->setItem(6,0,new QTableWidgetItem("6"));
    this->ui->regsTableWidget->setItem(7,0,new QTableWidgetItem("7"));
    this->ui->regsTableWidget->setItem(8,0,new QTableWidgetItem("8"));
    this->ui->regsTableWidget->setItem(9,0,new QTableWidgetItem("9"));
    this->ui->regsTableWidget->setItem(10,0,new QTableWidgetItem("10"));
    this->ui->regsTableWidget->setItem(11,0,new QTableWidgetItem("11"));
    this->ui->regsTableWidget->setItem(12,0,new QTableWidgetItem("12"));
    this->ui->regsTableWidget->setItem(13,0,new QTableWidgetItem("13"));
    this->ui->regsTableWidget->setItem(14,0,new QTableWidgetItem("14"));
    this->ui->regsTableWidget->setItem(15,0,new QTableWidgetItem("15"));

    this->ui->regsTableWidget->setItem(0,2,new QTableWidgetItem("16"));
    this->ui->regsTableWidget->setItem(1,2,new QTableWidgetItem("17"));
    this->ui->regsTableWidget->setItem(2,2,new QTableWidgetItem("18"));
    this->ui->regsTableWidget->setItem(3,2,new QTableWidgetItem("19"));
    this->ui->regsTableWidget->setItem(4,2,new QTableWidgetItem("20"));
    this->ui->regsTableWidget->setItem(5,2,new QTableWidgetItem("21"));
    this->ui->regsTableWidget->setItem(6,2,new QTableWidgetItem("22"));
    this->ui->regsTableWidget->setItem(7,2,new QTableWidgetItem("23"));
    this->ui->regsTableWidget->setItem(8,2,new QTableWidgetItem("24"));
    this->ui->regsTableWidget->setItem(9,2,new QTableWidgetItem("25"));
    this->ui->regsTableWidget->setItem(10,2,new QTableWidgetItem("26"));
    this->ui->regsTableWidget->setItem(11,2,new QTableWidgetItem("27"));
    this->ui->regsTableWidget->setItem(12,2,new QTableWidgetItem("28"));
    this->ui->regsTableWidget->setItem(13,2,new QTableWidgetItem("29"));
    this->ui->regsTableWidget->setItem(14,2,new QTableWidgetItem("30"));
    this->ui->regsTableWidget->setItem(15,2,new QTableWidgetItem("31"));


    this->ui->regsTableWidget->setItem(0,1,new QTableWidgetItem(this->regs->getShowData(0,this->outputbit)));
    this->ui->regsTableWidget->setItem(1,1,new QTableWidgetItem(this->regs->getShowData(1,this->outputbit)));
    this->ui->regsTableWidget->setItem(2,1,new QTableWidgetItem(this->regs->getShowData(2,this->outputbit)));
    this->ui->regsTableWidget->setItem(3,1,new QTableWidgetItem(this->regs->getShowData(3,this->outputbit)));
    this->ui->regsTableWidget->setItem(4,1,new QTableWidgetItem(this->regs->getShowData(4,this->outputbit)));
    this->ui->regsTableWidget->setItem(5,1,new QTableWidgetItem(this->regs->getShowData(5,this->outputbit)));
    this->ui->regsTableWidget->setItem(6,1,new QTableWidgetItem(this->regs->getShowData(6,this->outputbit)));
    this->ui->regsTableWidget->setItem(7,1,new QTableWidgetItem(this->regs->getShowData(7,this->outputbit)));
    this->ui->regsTableWidget->setItem(8,1,new QTableWidgetItem(this->regs->getShowData(8,this->outputbit)));
    this->ui->regsTableWidget->setItem(9,1,new QTableWidgetItem(this->regs->getShowData(9,this->outputbit)));
    this->ui->regsTableWidget->setItem(10,1,new QTableWidgetItem(this->regs->getShowData(10,this->outputbit)));
    this->ui->regsTableWidget->setItem(11,1,new QTableWidgetItem(this->regs->getShowData(11,this->outputbit)));
    this->ui->regsTableWidget->setItem(12,1,new QTableWidgetItem(this->regs->getShowData(12,this->outputbit)));
    this->ui->regsTableWidget->setItem(13,1,new QTableWidgetItem(this->regs->getShowData(13,this->outputbit)));
    this->ui->regsTableWidget->setItem(14,1,new QTableWidgetItem(this->regs->getShowData(14,this->outputbit)));
    this->ui->regsTableWidget->setItem(15,1,new QTableWidgetItem(this->regs->getShowData(15,this->outputbit)));

    this->ui->regsTableWidget->setItem(0,3,new QTableWidgetItem(this->regs->getShowData(16,this->outputbit)));
    this->ui->regsTableWidget->setItem(1,3,new QTableWidgetItem(this->regs->getShowData(17,this->outputbit)));
    this->ui->regsTableWidget->setItem(2,3,new QTableWidgetItem(this->regs->getShowData(18,this->outputbit)));
    this->ui->regsTableWidget->setItem(3,3,new QTableWidgetItem(this->regs->getShowData(19,this->outputbit)));
    this->ui->regsTableWidget->setItem(4,3,new QTableWidgetItem(this->regs->getShowData(20,this->outputbit)));
    this->ui->regsTableWidget->setItem(5,3,new QTableWidgetItem(this->regs->getShowData(21,this->outputbit)));
    this->ui->regsTableWidget->setItem(6,3,new QTableWidgetItem(this->regs->getShowData(22,this->outputbit)));
    this->ui->regsTableWidget->setItem(7,3,new QTableWidgetItem(this->regs->getShowData(23,this->outputbit)));
    this->ui->regsTableWidget->setItem(8,3,new QTableWidgetItem(this->regs->getShowData(24,this->outputbit)));
    this->ui->regsTableWidget->setItem(9,3,new QTableWidgetItem(this->regs->getShowData(25,this->outputbit)));
    this->ui->regsTableWidget->setItem(10,3,new QTableWidgetItem(this->regs->getShowData(26,this->outputbit)));
    this->ui->regsTableWidget->setItem(11,3,new QTableWidgetItem(this->regs->getShowData(27,this->outputbit)));
    this->ui->regsTableWidget->setItem(12,3,new QTableWidgetItem(this->regs->getShowData(28,this->outputbit)));
    this->ui->regsTableWidget->setItem(13,3,new QTableWidgetItem(this->regs->getShowData(28,this->outputbit)));
    this->ui->regsTableWidget->setItem(14,3,new QTableWidgetItem(this->regs->getShowData(30,this->outputbit)));
    this->ui->regsTableWidget->setItem(15,3,new QTableWidgetItem(this->regs->getShowData(31,this->outputbit)));
}

void MainWindow::on_pushButton_5_clicked()
{
    this->ui->comboBox->clear();
    this->setPortCombobox();
}

void MainWindow::setPortCombobox()
{
    QList<QSerialPortInfo> ports = this->ssi->getAllPorts();
    for(QList<QSerialPortInfo>::iterator port = ports.begin(); port != ports.end();port ++)
    {
        this->ui->comboBox->addItem(port->portName());
    }
}

void MainWindow::printInst()
{
    int ptr = this->ui->instTableWidget->rowCount() - 1;
    QQueue<unsigned int> temp = this->inst->getQueue();
    for(QQueue<unsigned int>::iterator i = temp.begin() , total = temp.end(); i!= total; i++,ptr --)
    {
        this->ui->instTableWidget->setItem(ptr,0,new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::printOther()
{
    this->ui->otherTableWidget->setItem(0,0,new QTableWidgetItem("Hi"));
    this->ui->otherTableWidget->setItem(0,1,new QTableWidgetItem("Lo"));
    this->ui->otherTableWidget->setItem(0,2,new QTableWidgetItem("PC"));
    this->ui->otherTableWidget->setItem(1,0,new QTableWidgetItem(this->other->getShowHi(this->outputbit)));
    this->ui->otherTableWidget->setItem(1,1,new QTableWidgetItem(this->other->getShowLo(this->outputbit)));
    this->ui->otherTableWidget->setItem(1,2,new QTableWidgetItem(this->other->getShowPc(this->outputbit)));
}


void MainWindow::receiveinfo()
{
    //if continue receive lots of messages,we need to analize them one by one.
    QByteArray list = this->ssi->receiveInfo();

   for(QByteArray::iterator i = list.begin();i != list.end();i++)
   {
       unsigned char temp = static_cast<unsigned char>(*i);
       if(this->pkg->receivedata(temp))
       {
            switch(this->pkg->getKind())
            {
            case REGS:
            {
                std::cout<<'['<<QTime::currentTime().second()<<']'<<"set regs"<<std::endl;
                this->regs->setData(this->pkg->getAddr(),this->pkg->getData());
                this->printRegs();
                break;
            }
            case ALU:
            {
                std::cout<<"set alu"<<std::endl;
                this->alu->setData(this->pkg->getAddr(),this->pkg->getData());
                this->printAlu();
                break;
            }
            case INST:
            {
                std::cout<<"set inst"<<std::endl;
                this->inst->append(this->pkg->getData());
                this->printInst();
                break;
            }
            case OTHER:
            {
                std::cout<<"set other"<<std::endl;
                this->other->setData(this->pkg->getAddr(),this->pkg->getData());
                this->printOther();
                break;
            }
            }
       }
   }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(this->ui->pushButton_3->text() == "CONNECT")
    {
        if(this->ui->comboBox->count() == 0)
        {
            std::cout<<"can not find a useable port"<<std::endl;
        }
        else
        {
            QString portName = this->ui->comboBox->currentText();
            this->ssi->connectPorts(portName);
            connect(this->ssi->m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveinfo()));
            this->ui->pushButton_3->setText("DISCONNECT");
        }
    }
    else
    {
        this->ssi->disconnectPorts();
        disconnect(this->ssi->m_serialPort,SIGNAL(readyRead()),this,nullptr);
        this->ui->pushButton_3->setText("CONNECT");
    }
}

void MainWindow::on_pushButton_clicked() //get
{
       this->ssi->sendData(GET);
}

void MainWindow::on_pushButton_4_clicked() //ping
{
    this->ssi->sendData(PING);
}

void MainWindow::on_pushButton_2_clicked() // resetn
{
    this->ssi->sendData(RESET);
}
