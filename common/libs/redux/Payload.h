#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <QMap>

#include <memory>
#include <any>

class Payload
{
public:
    Payload();
    Payload(const QString& key, std::any value);

    void set(const QString& key, std::any value);
    std::any get(const QString& key) const;

private:
    QMap<QString, std::any> mObjects;
};


#endif // PAYLOAD_H
