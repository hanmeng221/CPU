#include "regs.h"
#include "iostream"
Regs::Regs(QObject *parent)
{
    this->reg = new registry[32];
    this->init();
}

void Regs::init()
{
    for(int i = 0;i<32;i++)
    {
        this->reg[i].init();
    }
}

unsigned int Regs::getData(int addr)
{
    if(addr < 0 || addr > 31 )
    {
        std::cout<<"[Error] function:getData addr is wrong ,must between [0,31],input addr :"<<addr<<std::endl;
        return 0;
    }
    else
    {
        return this->reg[addr].getReg();
    }
}

void Regs::setData(int addr,unsigned int data)
{
    if(addr < 0 || addr > 31)
    {
        std::cout<<"[Error] function:setData addr is wrong ,must between [0,31],input addr :"<<addr<<std::endl;
        return;
    }
    else
    {
        if(addr != 0)
            this->reg[addr].setReg(data);
        return;
    }
}

QVector<unsigned int> Regs::getAll()
{
    QVector<unsigned int> result;
    for(int i = 0;i < 32; i ++)
    {
        result.append(this->reg[i].getReg());
    }
    return  result;
}

QString Regs::getShowData(int addr,int bit)
{
    if(addr < 0 || addr > 31)
    {
        addr = 0;
        std::cout<<"the addr is out of range [0,31],use 0 instead of "<<std::endl;
    }
    return this->reg[addr].toQString(bit);
}
Regs::~Regs()
{
    delete [] this->reg;
}
