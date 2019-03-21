#ifndef ALU_H
#define ALU_H
#include "QString"

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
    unsigned int reg1;
    unsigned int reg2;
    unsigned int result;
    unsigned int inst;
    QString option;
    void setOption();
};
