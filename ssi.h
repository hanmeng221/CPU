#ifndef SSI_H
#define SSI_H
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>
#include <QSerialPort>
#include <package.h>


class Ssi
{
public:
    Ssi();

    QList<QSerialPortInfo> getAllPorts();
    void connectPorts(QString portName);
    QByteArray receiveInfo();
    QSerialPort* m_serialPort;
private:
};

#endif // SSI_H
