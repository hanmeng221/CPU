#ifndef OTHER_H
#define OTHER_H
#include <QString>
#include <registry.h>
#include "QObject"

#endif // OTHER_H
class Other:public QObject
{
    Q_OBJECT
public:
    explicit Other(QObject *parent = nullptr);
    void init();
    unsigned int getHi();
    unsigned int getLo();
    unsigned int getPc();

    QString getShowHi(int bit);
    QString getShowLo(int bit);
    QString getShowPc(int bit);

    void setData(int addr,unsigned int data);

    ~Other();
private:
    registry* hi;
    registry* lo;
    registry* pc;

    void setHi(unsigned int hi);
    void setLo(unsigned int lo);
    void setPc(unsigned int pc);

};

