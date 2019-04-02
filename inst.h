#ifndef INST_H
#define INST_H
#include "QQueue"
#include "iostream"

class Inst
{
public:
    Inst(int queueSize);
    QQueue<unsigned int> getQueue();
    void append(unsigned int inst);
private:
    void init();
    QQueue<unsigned int> queue;
    int queuesize;
};

#endif // INST_H
