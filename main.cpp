#include "mainwindow.h"
#include <QApplication>
#include "registry.h"
#include"iostream"
#include "QString"

unsigned int QstringToUnInt(QString binary){

    if(binary.length() != 32){
        std::cout<<"the input is not 32'b"<<std::endl;
        return 0;
    }
    else{
        unsigned int temp = 0;
        for(int i = 0;i<32;i++){
            std::cout<<binary.at(i).digitValue() <<std::endl;
            temp += (binary.at(i).digitValue()) << (31-i);
        }
        return temp;
    }
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
