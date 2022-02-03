#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = nullptr);

signals:

};

#endif // DATASTORE_H
