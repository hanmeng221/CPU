#include"reg.h"
#include"stdio.h"
#include"iostream"

Reg::Reg(){
    this->regs = new unsigned int[32];
    this->init();
}

void Reg::init(){
    for(int i = 0;i< 32;i++)
        this->regs[i] = 0;
    printf("init finish\n");
}


unsigned int Reg::getReg(int addr){
    if (addr < 32 && addr >= 0)
        return this->regs[addr];
    else
        return 0;
}

void Reg::setReg(int addr,unsigned int data){
    if(addr >31 || addr < 0)
        return;
    else
        this->regs[addr] = data;
}

void Reg::getAll(unsigned int* a){
    for(int i = 0;i< 32;i++ )
        a[i] = this->regs[i];
}


Reg::~Reg(){
    delete this->regs;

}
