#ifndef REGS_H
#define REGS_H
#include "registry.h"
#include "qvector.h"

class Regs
{
public:
    Regs();
    void init();
    unsigned int getData(int addr);
    void setData(int addr,unsigned int data);
    ~Regs();
    QVector<unsigned int> getAll();
private:
    registry reg[32];
};

#endif // REGS_H
