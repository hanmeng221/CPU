#ifndef ALU_H
#define ALU_H
#include "QString"
#include "registry.h"

#endif // ALU_H

class ALU{
public:
    ALU();
    void init();
    void setInst(unsigned int inst);
    void setReg1(unsigned  reg1);
    void setReg2(unsigned int reg2);
    void setResult(unsigned int result);
    unsigned int getInst();
    unsigned int getReg1();
    unsigned int getReg2();
    unsigned int getResult();
    QString getOption();
    ~ALU();
private:
    registry reg1;
    registry reg2;
    registry result;
    registry inst;
    QString option;
    void setOption();
};
