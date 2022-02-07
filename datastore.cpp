#include "datastore.h"

DataStore::DataStore(QObject *parent) : QObject(parent)
{

}

void DataStore::ReciveRequest(RequestStruc &request)
{
    mutex_request.lock();
    RequestPool.append(request);
    mutex_request.unlock();
}

bool DataStore::GetRequest(RequestStruc &req)
{

    mutex_answer.lock();

    if(!AnswerPool.isEmpty())
    {
        mutex_request.lock();
        req = RequestPool.first();
        RequestPool.removeFirst();
        mutex_request.unlock();
        return true;
    }else
        return false;
}

void DataStore::SetAnswer(AnswerStruc &answ)
{
    mutex_answer.lock();
    AnswerPool.append(answ);
    mutex_answer.unlock();
}
