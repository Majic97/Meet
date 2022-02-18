#include "handler.h"

Handler::Handler(QObject *parent) : QObject(parent)
{

}

bool Handler::SwitchOnSensor()
{
    return dataBase.SwitchOnSensor();
}

QVector<MeasurementStruc> Handler::getLastTenValues()
{
    return dataBase.getLastTenValues();
}
