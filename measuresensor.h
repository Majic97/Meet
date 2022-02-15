#ifndef MEASURESENSOR_H
#define MEASURESENSOR_H

#include <QObject>

class MeasureSensor : public QObject
{
    Q_OBJECT
public:
    explicit MeasureSensor(QObject *parent = nullptr);

signals:

};

#endif // MEASURESENSOR_H
