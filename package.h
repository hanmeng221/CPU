#ifndef PACKAGE_H
#define PACKAGE_H

#include "QString"
#include "registry.h"
#include "QObject"

enum packagetype{
    REGS,
    ALU,
    INST,
    OTHER
};

class Package:public QObject
{
    Q_OBJECT
public:
    explicit Package(QObject *parent = nullptr);
    void packaging();
    bool receivedata(unsigned char data);
    packagetype getKind();
    int getAddr();
    unsigned int  getData();
    bool isbubble();
    ~Package();
private:
    unsigned char head;
    unsigned char data1;
    unsigned char data2;
    unsigned char data3;
    unsigned char data4;
    unsigned char tail;

    packagetype kind;
    registry* data;
    int addr;
    int data_count;
    void setKind();
    void setAddr();
    void setbubble(bool bubble);
    bool bubble;

    bool setHead(unsigned char head);
    bool setData1(unsigned char data1);
    bool setData2(unsigned char data2);
    bool setData3(unsigned char data3);
    bool setData4(unsigned char data4);
    bool setTail(unsigned char tail);
    bool isZero(unsigned char data, int addr);

    int getDataNum(unsigned char data,int addr);
signals:
    void DEBUG(QString );
};
#endif // PACKAGE_H
