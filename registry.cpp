#include "registry.h"

registry::registry(QObject *parent) : QObject(parent)
{
    this->reg = 0;
}
registry::registry (const registry *other)
{
    this->setReg(other->reg);
}
void registry::init(){
    this->reg = 0;
    printf("init finish\n");
}


unsigned int registry::getReg(){
        return this->reg;
}

void registry::setReg(unsigned int data){
        this->reg = data;
}

unsigned int registry::getSubData(int start,int end)
{
    int b = start>end?start:end;
    int s = start<end?start:end;
    if(s < 0 || b >32 || s > b )
    {
        std::cout<<"[Error] function:getSubData  param wrong ,input start :"<<start<<"end:"<<end<<std::endl;
        return  0;
    }
    else
    {
        return (this->reg>> s) & ((1<<(b-s+1)) -1);
    }
}

QString registry::toQString(int bit)
{
    if(bit < 2 || bit >16)
    {
        bit = 10;
        std::cout<<"the outputbit is out of range [2,16] ,use 10 to instead of "<<std::endl;
    }
    return  QString::fromUtf8(QByteArray::number(this->reg,bit));
}
registry::~registry(){
}
