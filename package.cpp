#include "package.h"
/*package struct
 * 1 | 0 | legal| addr [4:0]                         |
 * 0 | d[30:24]                                      |
 * 0 | d[22:16]                                      |
 * 0 | d[14:8]                                       |
 * 0 | d[6:0]                                        |
 * 1 | 1 | k[1] | k[0] |d[31] | d[23] | d[15] | d[7] |
 *
 */


package::package()
{
    this->head = 0;
    this->data1 = 0;
    this->data2 = 0;
    this->data3 = 0;
    this->data4 = 0;
    this->tail = 0;
    this->data_count = 0;
}

void package::packaging()
{
    this->data.setReg(((this->data1 + (this->getDataNum(this->tail,3) << 7)) << 24)
                      +((this->data2 + (this->getDataNum(this->tail,2) << 7)) << 16)
                      +((this->data3 + (this->getDataNum(this->tail,1) << 7)) << 8)
                      +(this->data4 + (this->getDataNum(this->tail,0) << 7)) );
    this->setAddr();
    this->setKind();
    this->setLegal();
}

bool package::setHead(unsigned char head)
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

bool package::setData1(unsigned char data1)
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

bool package::setData2(unsigned char data2)
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
bool package::setData3(unsigned char data3)
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

bool package::setData4(unsigned char data4)
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

bool package::setTail(unsigned char tail)
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

bool package::isZero(unsigned char data,int addr)
{
    return  (((data >> addr) & 1) == 0 ) ? true:false;
}

int package::getDataNum(unsigned char data, int addr)
{
    return (data >> addr ) & 1;
}

QString package::getKind()
{
    return this->kind;
}

int package::getAddr()
{
    return this->addr;
}

bool package::isLegal()
{
    return this->legal;
}

unsigned int  package::getData()
{
    return this->data.getReg();
}

void package::setKind()
{

}

void package::setAddr()
{

}

void package::setLegal()
{

}

void package::receivedata(unsigned char data)
{
    switch (this->data_count) {
    case 0:
        if(this->setHead(data))
            this->data_count  = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            std::cout<<"data receive head is illegal"<<std::endl;
        }
        break;
    case 1:
        if(this->setData1(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            std::cout<<"data receive data1 is illegal" <<std::endl;
        }
        break;
    case 2:
        if(this->setData2(data))
            this->data_count = (this->data_count + 1 ) % 6;
        else
        {
            this->data_count = 0;
            std::cout<<"data receive data2 is illegal" <<std::endl;
        }
        break;
    case 3:
        if(this->setData3(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            std::cout << "data receive data3 is illegal" <<std::endl;
        }
        break;
    case 4:
        if(this->setData4(data))
            this->data_count = (this->data_count + 1) % 6;
        else
        {
            this->data_count = 0;
            std::cout<< "data receive data4 is illegal" <<std::endl;
        }
        break;
    case 5:
        if(this->setTail(data))
        {
            this->data_count = (this->data_count + 1) % 6;
            this->packaging();
        }
        else
        {
            this->data_count = 0;
            std::cout << "data receive tail is illegal" <<std::endl;
        }
        break;
    default:
        break;
    }
}
