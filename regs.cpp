#include "regs.h"
#include "iostream"
Regs::Regs()
{

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
    if(addr < 1 || addr > 31)
    {
        std::cout<<"[Error] function:setData addr is wrong ,must between [1,31],input addr :"<<addr<<std::endl;
        return;
    }
    else
    {
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

Regs::~Regs()
{

}