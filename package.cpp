#include "package.h"
/*Package struct
 * legal: 偶校验
 * 1 | 0 | legal| addr [4:0]                         |
 * 0 | d[30:24]                                      |
 * 0 | d[22:16]                                      |
 * 0 | d[14:8]                                       |
 * 0 | d[6:0]                                        |
 * 1 | 1 | k[1] | k[0] |d[31] | d[23] | d[15] | d[7] |
 *
 */


Package::Package(QObject *parent): QObject (parent)
{
    this->data = new registry(parent);
    this->head = 0;
    this->data1 = 0;
    this->data2 = 0;
    this->data3 = 0;
    this->data4 = 0;
    this->tail = 0;
    this->data_count = 0;
}

void Package::packaging()
{
    this->setLegal();
    if(this->isLegal())
    {
        this->data->setReg(static_cast<unsigned int>(((this->data1 + (this->getDataNum(this->tail,3) << 7)) << 24)
                      +((this->data2 + (this->getDataNum(this->tail,2) << 7)) << 16)
                      +((this->data3 + (this->getDataNum(this->tail,1) << 7)) << 8)
                      +(this->data4 + (this->getDataNum(this->tail,0) << 7))));
        this->setAddr();
        this->setKind();
        return ;
    }
    else
    {
        emit DEBUG(QString("the Package is not legal:receive data:\n\thead:%1\n\tdata1:%2\n\tdata2:%3\n\tdata3:%4\n\tdata4:%5\n\ttail:%6")
                .arg(this->head)
                .arg(this->data1)
                .arg(this->data2)
                .arg(this->data3)
                .arg(this->data4)
                .arg(this->tail));
    }
}

bool Package::setHead(unsigned char head)
{
    //10xxxxxx
    if(!isZero(head,7) && isZero(head,6))
    {
        this->head = head;
        return true;
    }
    else
    {
        return false;
    }

}

bool Package::setData1(unsigned char data1)
{
    //0xxxxxxx
    if(isZero(data1,7))
    {
        this->data1 = data1;
        return true;
    }
    else
    {
        return false;
    }
}

bool Package::setData2(unsigned char data2)
{
    //0xxxxxxx
    if(isZero(data2,7))
    {
        this->data2 = data2;
        return true;
    }
    else
    {
        return false;
    }
}
bool Package::setData3(unsigned char data3)
{
    //0xxxxxxx
    if(isZero(data3,7))
    {
        this->data3 = data3;
        return true;
    }
    else
    {
        return false;
    }

}

bool Package::setData4(unsigned char data4)
{
    //0xxxxxxx
    if(isZero(data4,7))
    {
        this->data4 = data4;
        return true;
    }
    else
    {
        return false;
    }
}

bool Package::setTail(unsigned char tail)
{
    //11xxxxxx
    if(!isZero(tail,7) && !isZero(tail,6))
    {
        this->tail = tail;
        return true;
    }
    else
    {
        return false;
    }
}

bool Package::isZero(unsigned char data,int addr)
{
    return  (((data >> addr) & 1) == 0 ) ? true:false;
}

int Package::getDataNum(unsigned char data, int addr)
{
    return (data >> addr ) & 1;
}

packagetype Package::getKind()
{
    return this->kind;
}

int Package::getAddr()
{
    return this->addr;
}

bool Package::isLegal()
{
    return this->legal;
}

unsigned int  Package::getData()
{
    return this->data->getReg();
}

Package::~Package()
{
    delete this->data;
}

void Package::setKind()
{
    switch ((this->getDataNum(this->tail,5) << 1 )+ this->getDataNum(this->tail,4)) {
    case 0:
        this->kind = REGS;
        break;
    case 1:
        this->kind = ALU;
        break;
    case 2:
        this->kind = INST;
        break;
    case 3:
        this->kind = OTHER;
        break;
    default:
        break;
    };
}

void Package::setAddr()
{
    this->addr = this->head  &  31;
}

void Package::setLegal()
{
    this->legal = (this->getDataNum(this->head,5) ^ (this->data1 & 1) ^ (this->data2 & 1) ^ (this->data3 & 1) ^ (this->data4 & 1) ^ (this->tail & 1))  == 0 ? true:false;
}

bool Package::receivedata(unsigned char data)
{
    switch (this->data_count) {
    case 0:
        if(this->setHead(data))
            this->data_count  = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive head is illegal");
        }
        break;
    case 1:
        if(this->setData1(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive data1 is illegal");
        }
        break;
    case 2:
        if(this->setData2(data))
            this->data_count = (this->data_count + 1 ) % 6;
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive data2 is illegal");
        }
        break;
    case 3:
        if(this->setData3(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive data3 is illegal");
        }
        break;
    case 4:
        if(this->setData4(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive data4 is illegal");
        }
        break;
    case 5:
        if(this->setTail(data))
        {
            this->data_count = (this->data_count + 1) % 6;
            this->packaging();
            if(this->isLegal())
            {
                return true;
            }
        }
        else
        {
            this->data_count = 0;
            emit DEBUG("data receive tail is illegal");
        }
        break;
    default:
        break;
    }
    return false;
}
