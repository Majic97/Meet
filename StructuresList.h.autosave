#ifndef STRUCTURESLIST_H
#define STRUCTURESLIST_H
#include <QDate>
#include <QTime>

struct MeasurementStruc{
    unsigned short int MeetID;
    char Temp;
    char Hum;
    QDate Date;
    QTime Time;
};

struct MeetData{
    unsigned short int MeetID;
    QDate dataBegin;
    QTime timeBegin;
    QDate dateEnd;
    QTime timeEnd;
};

struct RequestStruc{
    unsigned char Source;
    unsigned char TypeOfRequest;
    unsigned short int MeetID;
    unsigned short int SensorID;
};

struct AnswerStruc{
    unsigned char Source;
    unsigned char TypeOfRequest;
    unsigned short int MeetID;
    unsigned short int SensorID;
    QVector<MeasurementStruc> Data;
    QVector<MeetData> MeetDataList;
    QString Message;
};



#endif // STRUCTURESLIST_H
