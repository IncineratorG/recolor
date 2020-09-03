#include "RequestPayload.h"

#include <QDebug>

RequestPayload::RequestPayload() {

}

RequestPayload::RequestPayload(const QMap<QString, std::any> values,
                               const QString& serializedValues)
    : mValues(values),
      mSerializedValues(serializedValues) {

}

RequestPayload::RequestPayload(const RequestPayload& other)
    : mValues(other.mValues),
      mSerializedValues(other.mSerializedValues) {

}

std::any RequestPayload::getValue(const QString& key) const {
    if (mValues.contains(key)) {
        return mValues.value(key);
    }

    return nullptr;
}

QByteArray RequestPayload::toByteArrayNoCRLF() const {
    QString serializedPayload = "\"payload\":" + mSerializedValues;
    return serializedPayload.toUtf8();
}
