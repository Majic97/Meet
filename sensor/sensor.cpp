#include "sensor/sensor.h"


QPair<double, double> Sensor::getDataFromSensor()
{
    QPair<double,double> value;

    if(!isAlreadySwitchOn)
        if(!StartListening()){
            value.first=NULL;
            value.second = NULL;
            return value;
        }

    value.first = GetTemperature(gfd);
    value.second = GetTemperature(gfd);
    return value;
}

double Sensor::GetTemperature(int fd)
{
    unsigned char buf [4];
    wiringPiI2CWrite(fd, HTU21D_TEMP);
    delay(100);
    read(fd, buf, 3);
    unsigned int temp = (buf [0] << 8 | buf [1]) & 0xFFFC;
    // Convert sensor reading into temperature.
    // See page 14 of the datasheet
    double tSensorTemp = temp / 65536.0;
    return -46.85 + (175.72 * tSensorTemp);
}

double Sensor::GetHumidity(int fd)
{
    unsigned char buf [4];
        wiringPiI2CWrite(fd, HTU21D_HUMID);
        delay(100);
        read(fd, buf, 3);
        unsigned int humid = (buf [0] << 8 | buf [1]) & 0xFFFC;
        // Convert sensor reading into humidity.
        // See page 15 of the datasheet
        double tSensorHumid = humid / 65536.0;
        return -6.0 + (125.0 * tSensorHumid);
}

bool Sensor::StartListening()
{
    wiringPiSetup();
    int fd = wiringPiI2CSetup(HTU21D_I2C_ADDR);
    if ( 0 > fd )
        return false;

    isAlreadySwitchOn=true;
    gfd = fd;
    return true;
}
