#include "ssi.h"

SSI::SSI()
{
    m_serialPort = new QSerialPort();
}

QList<QSerialPortInfo> SSI::getAllPorts()
{
    return QSerialPortInfo::availablePorts();
}

void SSI::connectPorts(QString portName)
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
    m_serialPort->setPortName(portName);
    if (!m_serialPort->open(QIODevice::ReadWrite))
    {
        std::cout<<portName.toStdString().data()<<"open failed"<<std::endl;
    }
    else
    {
        std::cout<<portName.toStdString().data()<<"open successed"<<std::endl;
        m_serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
        m_serialPort->setDataBits(QSerialPort::Data8);
        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
        m_serialPort->setParity(QSerialPort::NoParity);
        m_serialPort->setStopBits(QSerialPort::OneStop);
    }
}

QByteArray SSI::receiveInfo()
{
     return m_serialPort->readAll();
}
