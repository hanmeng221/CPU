#include "alu.h"

Alu::Alu(QObject *parent):QObject (parent){
    this->reg1 = new registry(parent);
    this->reg2 = new registry(parent);
    this->result = new registry(parent);
    this->inst = new registry(parent);
    this->init();
}

Alu::~Alu(){
    delete this->reg1;
    delete this->reg2;
    delete this->result;
    delete this->inst;
}
void Alu::init(){
    this->inst->init();
    this->reg1->init();
    this->reg2->init();
    this->result->init();
    this->option = "NOP";
}

void Alu::setInst(unsigned int inst){
    this->inst->setReg(inst);
    this->setOption();
}

void Alu::setReg1(unsigned int reg1){
    this->reg1->setReg(reg1);
}

void Alu::setReg2(unsigned int reg2){
    this->reg2->setReg(reg2);
}

void Alu::setResult(unsigned int result){
    this->result->setReg(result);
}

void Alu::setOption(){
    unsigned int op1 = this->inst->getSubData(31,26);
    switch (op1) { // op1 = inst[31:26]
        case 0:{
            unsigned int op2 = this->inst->getSubData(10,6); // op2 = inst[10:6]
            if(op2 == 0){
                unsigned int op4 = this->inst->getSubData(5,0); //op4 = inst[5:0]
                switch (op4) {
                case 4:this->option = "SLLV";break;
                case 6:this->option = "SRLV";break;
                case 7:this->option = "SRAV";break;
                case 8:this->option = "JR";break;
                case 9:this->option = "JALR";break;
                case 10:this->option = "MOVZ";break;
                case 11:this->option = "MOVN";break;
                case 15:this->option = "SYNC";break;
                case 16:this->option = "MFHI";break;
                case 17:this->option = "MTHI";break;
                case 18:this->option = "MFLO";break;
                case 19:this->option = "MTLO";break;
                case 24:this->option = "MULT";break;
                case 25:this->option = "MULTU";break;
                case 32:this->option = "ADD";break;
                case 33:this->option = "ADDU";break;
                case 34:this->option = "SUB";break;
                case 35:this->option = "SUBU";break;
                case 36:this->option = "AND";break;
                case 37:this->option = "OR";break;
                case 38:this->option = "XOR";break;
                case 39:this->option = "NOR";break;
                case 42:this->option = "SLT";break;
                case 43:this->option = "SLTU";break;
                default:this->option = "ERROR";break;
                }
            }//end if op2 = 0
            else{
                unsigned int op3 = this->inst->getSubData(25,21);//op3 = inst[25:21]
                if( op3 == 0){ //sll,srl,sra
                    unsigned int op4 = this->inst->getSubData(5,0); //op4 = inst[5:0]
                    switch (op4) {
                    case 0:this->option = "SLL";break;
                    case 2:this->option = "SRL";break;
                    case 3:this->option = "SRA";break;
                    default:this->option = "ERROR";break;
                    }
                }
                else{
                    this->option = "ERROR";
                    return ;
                }
            }
        break;
        }//end case 0
        case 1:{
        unsigned int op5 = this->inst->getSubData(20,16);//op5 = inst[20:16];
        switch (op5) {
        case 0:this->option = "BLTZ";break;
        case 1:this->option = "BGEZ";break;
        case 16:this->option = "BLTZAL";break;
        case 17:this->option = "BGEZAL";break;
        default:this->option = "ERROR";break;
        }
        break;
    }//end case 1
    case 2:this->option = "J";break;
    case 3:this->option = "JAL";break;
    case 4:this->option = "BEQ";break;
    case 5:this->option = "BNE";break;
    case 6:this->option = "BLEZ";break;
    case 7:this->option = "BGTZ";break;
    case 8:this->option = "ADDI";break;
    case 9:this->option = "ADDIU";break;
    case 10:this->option = "SLTI";break;
    case 11:this->option = "SLTIU";break;
    case 12:this->option = "ANDI";break;
    case 13:this->option = "ORI";break;
    case 14:this->option = "XORI";break;
    case 15:this->option = "LUI";break;
    case 28:{
        unsigned int op4 = this->inst->getSubData(5,0); //op4 = inst[5:0]
        switch (op4){
        case 2:this->option =  "MUL";break;
        case 32:this->option = "CLZ";break;
        case 33:this->option = "CLO";break;
        default:this->option = "ERROR";break;
        }
        break;
    }
    case 35:this->option = "LW";break;
    case 43:this->option = "SW";break;
    case 51:this->option = "PREF";break;
    default:this->option = "ERROR";break;
    }
}

unsigned int Alu::getInst(){
    return this->inst->getReg();
}
unsigned int Alu::getReg1(){
    return this->reg1->getReg();
}
unsigned int Alu::getReg2(){
    return this->reg2->getReg();
}
unsigned int Alu::getResult(){
    return this->result->getReg();
}
QString Alu::getOption(){
    return this->option;
}

QString Alu::getShowInst(int bit)
{
    return  this->inst->toQString(bit);
}
QString Alu::getShowReg1(int bit)
{
    return this->reg1->toQString(bit);
}
QString Alu::getShowReg2(int bit)
{
    return this->reg2->toQString(bit);
}
QString Alu::getShowResult(int bit)
{
    return this->result->toQString(bit);
}
QString Alu::getShowOption()
{
    return this->getOption();
}

void Alu::setData(int addr, unsigned int data)
{
    switch (addr)
    {
    case 1: //inst
        this->setInst(data);
        break;
    case 2: // reg1
        this->setReg1(data);
        break;
    case 3: // reg2
        this->setReg2(data);
        break;
    case 4://result
        this->setResult(data);
        break;
    default:
        break;
    }
}

