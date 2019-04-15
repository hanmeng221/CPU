#include "other.h"

Other::Other(QObject *parent):QObject (parent)
{
    this->hi = new registry(parent);
    this->lo = new registry(parent);
    this->pc = new registry(parent);
    this->state = new registry(parent);
    this->init();
}

void Other::init()
{
    this->hi->init();
    this->lo->init();
    this->pc->init();
    this->state->init();
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

unsigned int Other::getState()
{
    return this->state->getReg();
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


//state: normal, bubble, exception, interrupt
QString Other::getShowState()
{
    switch (this->state->getReg()) {
    case 0:
        return "normal";
        break;
    case 1:
        return "bubble";
        break;
    case 2:
        return "exception";
        break;
    case 3:
        return "interrupt";
    default:
        return "normal";
        break;
    }
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
    case 4://state
        this->setState(data);
    default:
        break;
    }
}

Other::~Other()
{
    delete hi;
    delete lo;
    delete pc;
    delete state;
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

void Other::setState(unsigned int state)
{
    this->state->setReg(state);
}





