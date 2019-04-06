#ifndef REGS_H
#define REGS_H
#include "registry.h"
#include "qvector.h"
#include "QObject"

class Regs:public QObject
{
    Q_OBJECT
public:
    explicit Regs(QObject * parent = nullptr);
    void init();
    unsigned int getData(int addr);
    QString getShowData(int addr,int bit);
    void setData(int addr,unsigned int data);
    ~Regs();
    QVector<unsigned int> getAll();
private:
    registry* reg;
};

#endif // REGS_H
