#ifndef ALU_H
#define ALU_H
#include "QString"
#include "registry.h"
#include "QObject"


class Alu :public QObject
{
    Q_OBJECT
public:
    explicit Alu(QObject *parent = nullptr);
    void init();
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
    void setData(int addr,unsigned int data);

    ~Alu();
private:
    registry* reg1;
    registry* reg2;
    registry* result;
    registry* inst;
    QString option;
    void setOption();
    void setInst(unsigned int inst);
    void setReg1(unsigned  reg1);
    void setReg2(unsigned int reg2);
    void setResult(unsigned int result);

};
#endif // ALU_H

