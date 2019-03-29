#ifndef REGISTRY_H
#define REGISTRY_H

#include <QObject>
#include "iostream"
#include <QString>
#include "QByteArray"

class registry : public QObject
{
    Q_OBJECT
public:
    explicit registry(QObject *parent = nullptr);
    registry (const registry *other);
    void init();
    unsigned int getReg();
    unsigned int getSubData(int start,int end);
    void setReg(unsigned int data);
    QString toQString(int bit);
    ~registry();
signals:

public slots:

private:
    unsigned int reg;
};

#endif // REGISTRY_H
