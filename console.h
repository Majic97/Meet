#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>


class Console : public QObject
{
    Q_OBJECT
public:
    explicit Console(int argc, char *argv[],QObject *parent = nullptr);
    bool Switch_On_Console();
    int exec();


private:
    QCoreApplication *a;



signals:

};

#endif // CONSOLE_H
