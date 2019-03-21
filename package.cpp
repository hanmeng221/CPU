#include "package.h"

package::package(unsigned char head,unsigned char data1,unsigned char data2,unsigned char data3,unsigned char data4){
    int num = (head >> 5) & 1;
    this->legal = false;
    for(int i = 0;i<8;i++){
        num += ((data1>>i) & 1) + ((data2>>i) & 1) + ((data3>>i) & 1) + ((data4>>i) & 1);
    }
    if (num %2 == 0){
        this->data = static_cast<unsigned int>((data1<<24) + (data2 << 16) + (data3 << 8) + data4);
        switch (head / 64) {
        case 0:this->data = 0;this->kind = "ERROR";this->addr = 0;this->legal = false;break;
        case 1:this->kind = "REG";this->addr = head % 32;this->legal = true;break;
        case 2:this->kind = "ALU";this->addr = head % 32;this->legal = true;break;
        case 3:this->kind = "OTHER";this->addr = head % 32;this->legal = true;break;
        }
    }
    else{
        this->data = 0;
        this->kind ="EVENERROR";
        this->addr = 0;
        this->legal = false;
    }
}
QString package::getKind(){
    return this->kind;
}

int package::getAddr(){
    return this->addr;
}

bool package::isLegal(){
    return this->legal;
}

