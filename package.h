#ifndef PACKAGE_H
#define PACKAGE_H

#endif // PACKAGE_H
#include "QString"
#include "registry.h"

class package{
public:
    package();
    void packaging();
    void receivedata(unsigned char data);
    QString getKind();
    int getAddr();
    bool isLegal();
    unsigned int  getData();
private:
    unsigned char head;
    unsigned char data1;
    unsigned char data2;
    unsigned char data3;
    unsigned char data4;
    unsigned char tail;

    QString kind;
    registry data;
    int addr;
    bool legal;
    int data_count;
    void setKind();
    void setAddr();
    void setLegal();

    bool setHead(unsigned char head);
    bool setData1(unsigned char data1);
    bool setData2(unsigned char data2);
    bool setData3(unsigned char data3);
    bool setData4(unsigned char data4);
    bool setTail(unsigned char tail);
    bool isZero(unsigned char data, int addr);
    int getDataNum(unsigned char data,int addr);
};
