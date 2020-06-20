#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QTcpSocket>

#include <functional>

class Bridge : public QObject
{
    Q_OBJECT

public:
    explicit Bridge();
//    ~Bridge();

public slots:
    void on();
    void off();

    void send(const QString& data);

private slots:
    void onTimeout();

    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

signals:
    void received(const QString& data);

private:
    QTcpSocket* mSocket;
    QTimer* mTimer;
    int counter;
};

#endif // BRIDGE_H
