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
    void init();
private:

    QQueue<unsigned int> queue;
    int queuesize;
};

#endif // INST_H
