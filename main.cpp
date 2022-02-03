#include <QCoreApplication>
#include <console.h>
#include <QDebug>

int main(int argc, char *argv[])
{

    Console a(argc,argv);
    return a.exec();

}
