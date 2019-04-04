#include "ssi.h"

Ssi::Ssi()
{
    m_serialPort = new QSerialPort();
}

QList<QSerialPortInfo> Ssi::getAllPorts()
{
    return QSerialPortInfo::availablePorts();
}

void Ssi::disconnectPorts()
{
    QString portName = this->m_serialPort->portName();
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
    std::cout<<portName.toStdString()<<" close successed"<<std::endl;
}
void Ssi::connectPorts(QString portName)
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
    m_serialPort->setPortName(portName);
    if (!m_serialPort->open(QIODevice::ReadWrite))
    {
        std::cout<<portName.toStdString().data()<<" open failed"<<std::endl;
    }
    else
    {
        std::cout<<portName.toStdString().data()<<" open successed"<<std::endl;
        m_serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
        m_serialPort->setDataBits(QSerialPort::Data8);
        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
        m_serialPort->setParity(QSerialPort::NoParity);
        m_serialPort->setStopBits(QSerialPort::OneStop);
    }
}

QByteArray Ssi::receiveInfo()
{
     return m_serialPort->readAll();
}

void Ssi::sendData(SsiInfo data)
{
    char toSentData;
    switch (data) {
    case GET:
        toSentData = 'g';
        break;
    case PING:
        toSentData = 'p';
        break;
    case RESET:
        toSentData = 'r';
        break;
    }
    this->m_serialPort->write(&toSentData);
}
