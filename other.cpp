#include "other.h"

Other::Other(QObject *parent):QObject (parent)
{
    this->hi = new registry(parent);
    this->lo = new registry(parent);
    this->pc = new registry(parent);
    this->init();
}

void Other::init()
{
    this->hi->init();
    this->lo->init();
    this->pc->init();
}

unsigned int Other::getHi()
{
    return this->hi->getReg();
}

unsigned int Other::getLo()
{
    return this->lo->getReg();
}

unsigned int Other::getPc()
{
    return this->pc->getReg();
}

QString Other::getShowHi(int bit)
{
    return  this->hi->toQString(bit);
}

QString Other::getShowLo(int bit)
{
    return this->lo->toQString(bit);
}

QString Other::getShowPc(int bit)
{
    return this->pc->toQString(bit);
}

void Other::setData(int addr, unsigned int data)
{
    switch (addr)
    {
    case 1: //pc
        this->setPc(data);
        break;
    case 2://hi
        this->setHi(data);
        break;
    case 3://lo
        this->setLo(data);
        break;
    default:
        break;
    }
}

Other::~Other()
{
    delete hi;
    delete lo;
    delete pc;
}

void Other::setHi(unsigned int hi)
{
    this->hi->setReg(hi);
}

void Other::setLo(unsigned int lo)
{
    this->lo->setReg(lo);
}

void Other::setPc(unsigned int pc)
{
    this->pc->setReg(pc);
}





