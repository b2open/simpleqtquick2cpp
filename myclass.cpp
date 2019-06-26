#include "myclass.h"
#include <QDateTime>
#include <QDebug>
#include <QTimer>

MyClass::MyClass(QObject *parent) :    
    QObject(parent),
    m_timer(new QTimer)
{
    QObject::connect(m_timer, &QTimer::timeout, [&](){
        this->setClock(QDateTime::currentDateTime().toString("HH:MM:ss"));
        qInfo().noquote().nospace() << "Tick: " << QDateTime::currentDateTime().toString("HH:MM:ss");
    });

}

MyClass::~MyClass()
{
    if (m_timer) {
        delete m_timer;
        m_timer = nullptr;
    }
}

QString MyClass::clock() const
{
    return m_clock;
}

void MyClass::newValuePot(int value)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
    qInfo().noquote().nospace() << "New Value[" << qrand()%value <<"]";
    Q_EMIT newData(qrand()%value);
}

void MyClass::startTimer()
{
    m_timer->start(1000);
}

void MyClass::stopTimer()
{
    m_timer->stop();
}

void MyClass::setClock(QString time)
{
    if (m_clock == time)
        return;

    m_clock = time;
    Q_EMIT changedClock(m_clock);

}
