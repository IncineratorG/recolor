#ifndef REQUESTPAYLOAD_H
#define REQUESTPAYLOAD_H

#include <QMap>
#include <QByteArray>
#include <QString>

#include <memory>
#include <any>
#include <functional>

class RequestPayload
{
public:
    RequestPayload();
    RequestPayload(const QMap<QString, std::any> values,
                   const QString& serializedValues);
    RequestPayload(const RequestPayload& other);

    std::any getValue(const QString& key) const;

    QByteArray toByteArrayNoCRLF() const;

private:
    QMap<QString, std::any> mValues;
    QString mSerializedValues;
};

#endif // REQUESTPAYLOAD_H
