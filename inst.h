#ifndef INST_H
#define INST_H
#include "QQueue"
#include "iostream"
#include "QObject"

class Inst:public QObject
{
    Q_OBJECT
public:
    explicit Inst(int queueSize,QObject* parent = nullptr);
    QQueue<unsigned int> getQueue();
    void append(unsigned int inst);
    void init();
private:

    QQueue<unsigned int> queue;
    int queuesize;
};

#endif // INST_H
