#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class QTimer;

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString clock READ clock WRITE setClock NOTIFY changedClock)

public:
    explicit MyClass(QObject *parent = nullptr);
    ~MyClass();

    QString clock() const;

    Q_INVOKABLE void newValuePot(int value);
    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();


private:
    QString m_clock{"00:00:00"};
    QTimer* m_timer;

signals:
    void newData(int value);
    void changedClock(QString);

public slots:
    void setClock(QString);

};

#endif // MYCLASS_H
