#ifndef ALU_H
#define ALU_H
#include "QString"
#include "registry.h"

#endif // ALU_H

class Alu{
public:
    Alu();
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

    QString getShowInst(int bit);
    QString getShowReg1(int bit);
    QString getShowReg2(int bit);
    QString getShowResult(int bit);
    QString getShowOption();


    ~Alu();
private:
    registry reg1;
    registry reg2;
    registry result;
    registry inst;
    QString option;
    void setOption();
};
