#include "console.h"
#include <QDebug>
QTextStream qin(stdin);
QTextStream qout(stdout);

Console::Console(int argc, char *argv[],QObject *parent) : QObject(parent)
{
    a = new QCoreApplication(argc, argv);
}

bool Console::Switch_On_Console()
{
    QString name;
    while(true){
//    qout << "Please enter your name = " << ;
    qout << "Type your command: " << Qt::endl;
    name = qin.readLine();
    qout << Qt::endl;
    if(name == "exit")
        break;
    }

    return true;

}

int Console::exec()
{
    if(Switch_On_Console())
            qout << "Application is swithed off" << Qt::endl;

    return a->exec();
}
