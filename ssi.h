#ifndef SSI_H
#define SSI_H
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>
#include <QSerialPort>
#include <package.h>
#include "QObject"

enum SsiInfo {
    GET,
    PING,
    RESET
};

class Ssi:public QObject
{
    Q_OBJECT
public:
    explicit Ssi(QObject * parent = nullptr);
    QList<QSerialPortInfo> getAllPorts();
    void connectPorts(QString portName);
    void sendData(SsiInfo data);
    QByteArray receiveInfo();
    QSerialPort* m_serialPort;
    void disconnectPorts();
signals:
    void DEBUG(QString );

};

#endif // SSI_H
