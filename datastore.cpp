#include "datastore.h"

DataStore::DataStore(QObject *parent) : QObject(parent)
{

}

bool DataStore::SwitchOnSensor()
{
    try{
        IsLesteningNow=true;
    QFuture<void> future= QtConcurrent::run([this](){
        ListenSensor();
    });
    }
    catch(...){
        return false;
    }

    return true;
}

QVector<MeasurementStruc> DataStore::getLastTenValues()
{
    QVector<MeasurementStruc> value;
    if(isAlreadySwitchOn)
    return getDataFromMeasureStore();
    else{
        if(SwitchOnSensor())
        {
            QThread::sleep(70);
            return getDataFromMeasureStore();
        }else
            return value;
    }

}

void DataStore::ListenSensor()
{
    while(IsLesteningNow){
        QPair<double,double> sensoeValue;
        MeasurementStruc StoreValue;
        sensoeValue = Sensor::getDataFromSensor();
        StoreValue.Temp=(unsigned char)sensoeValue.first;
        StoreValue.Hum =(unsigned char)sensoeValue.second;

        MeasureStore_mutex.lock();
        MeasureStore.append(StoreValue);
        MeasureStore_mutex.unlock();
        QThread::sleep(60);
    }
}

QVector<MeasurementStruc> DataStore::getDataFromMeasureStore()
{
    QVector<MeasurementStruc> value;
    int counter=0;

    MeasureStore_mutex.lock();
    QVector<MeasurementStruc>::iterator it= MeasureStore.end();
    if(it!=MeasureStore.begin() || counter>=10){
        it--;
        counter++;
        value.append((*it));
    }
    MeasureStore_mutex.unlock();
    return value;
}

