#ifndef REG_H
#define REG_H
#endif // REG_H


class Reg{
    public:
        Reg();
        void init();
        unsigned int getReg(int addr);
        void setReg(int addr,unsigned int data);
        void  getAll(unsigned int* a);
        ~Reg();
    private:
        unsigned int* regs;
};
