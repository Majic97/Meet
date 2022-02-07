#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include "StructuresList.h"
#include "QMutex"

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = nullptr);
    void ReciveRequest(RequestStruc &request);

private:
    QMutex mutex_request, mutex_answer;
    bool GetRequest(RequestStruc &req);
    void SetAnswer(AnswerStruc &answ);
    QVector<AnswerStruc> AnswerPool;
    QVector<RequestStruc> RequestPool;
    bool GetSensordata();

signals:

};

#endif // DATASTORE_H
