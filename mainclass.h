#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);

signals:

};

#endif // MAINCLASS_H
