#include "mainwindow.h"
#include "k1class.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    k1class k1;
    k1.init();
    std::cout << "Clouds: " << k1.clouds.size() << std::endl;

    k1.registration(k1.clouds);

    return a.exec();
}
