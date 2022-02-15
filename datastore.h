#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include "StructuresList.h"
#include "QMutex"
#include "QTime"
#include "sensor/sensor.h"
#include "QPair"
#include <QVector>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QVectorIterator>


class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = nullptr);
    bool SwitcOnSensor();
    QVector<MeasurementStruc> getLastTenValues();

private:
    QMutex MeasureStore_mutex;
    void ListenSensor();
    QVector<MeasurementStruc> getDataFromMeasureStore(); // для версии 0.1 возвращает 10 последних измерений
    void SetDataToMeetDataStore(MeetData);

    bool IsLesteningNow=false;
    QVector<MeasurementStruc> MeasureStore;
    QVector<MeetData> MeetDataStore;


signals:

};

#endif // DATASTORE_H
