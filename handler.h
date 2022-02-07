#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "StructuresList.h"


class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr);

private:
    QVector<AnswerStruc> AnswerPool;
    QVector<RequestStruc> RequestPool;


signals:

};

#endif // HANDLER_H
