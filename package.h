#ifndef PACKAGE_H
#define PACKAGE_H

#endif // PACKAGE_H
#include "QString"
#include "registry.h"

class package{
public:
    package(unsigned char head,unsigned char data1,unsigned char data2,unsigned char data3,unsigned char data4);
    QString getKind();
    int getAddr();
    bool isLegal();
    unsigned int  getData();
private:
    QString kind;
    registry data;
    int addr;
    bool legal;
};
