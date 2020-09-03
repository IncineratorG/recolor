#ifndef REQUEST_H
#define REQUEST_H

#include "RequestPayload.h"

#include <QString>
#include <QByteArray>
#include <QUuid>

#include <functional>

class Request
{
public:
    Request(const QString& type);
    Request(const QString& type, const RequestPayload& payload);

    QString getType() const;
    QUuid getUuid() const;
    QByteArray toByteArray() const;

private:
    QString mType;
    QUuid mUuid;
    RequestPayload mPayload;
};

#endif // REQUEST_H
