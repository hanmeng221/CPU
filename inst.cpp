#include "inst.h"

Inst::Inst(int queueSize,QObject *parent ):QObject (parent)
{
    this->queuesize = queueSize;
    this->init();
}

void Inst::append(unsigned int data)
{
    this->queue.dequeue();
    this->queue.enqueue(data);
}

void Inst::init()
{
    this->queue.clear();
    for(int i = 0;i< this->queuesize;i++)
    {
        this->queue.enqueue(0);
    }
}

QQueue<unsigned int> Inst::getQueue()
{
    return this->queue;
}


