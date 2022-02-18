#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "StructuresList.h"
#include "datastore.h"

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr);
    bool SwitchOnSensor();
    QVector<MeasurementStruc> getLastTenValues();

private:
    DataStore dataBase;
    QVector<AnswerStruc> AnswerPool;
    QVector<RequestStruc> RequestPool;


signals:

};

#endif // HANDLER_H
