#ifndef SENSOR_H
#define SENSOR_H

#define   HTU21D_I2C_ADDR 0x40

#define   HTU21D_TEMP     0xF3
#define   HTU21D_HUMID    0xF5

static bool isAlreadySwitchOn = false;
static int fd;

#include <QObject>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "sensor/wiringPi.h"
#include "sensor/wiringPiI2C.h"
#include <unistd.h>
#include <QPair>

class Sensor
{
//    explicit Sensor();
public:
    static QPair<double,double> getDataFromSensor();

private:
    static double GetTemperature(int fd);
    static double GetHumidity(int fd);
    static bool StartListening();




signals:

};

#endif // SENSOR_H
