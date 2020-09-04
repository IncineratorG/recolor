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

bool RequestPayload::isEmpty() const {
    return mSerializedValues.isEmpty();
}

std::any RequestPayload::getValue(const QString& key) const {
    if (mValues.contains(key)) {
        return mValues.value(key);
    }

    return nullptr;
}

QByteArray RequestPayload::toByteArrayNoCRLF() const {
    QString payloadField = "\"payload\":";

    QString openBrackets = "{";
    QString closeBrackets = "}";
    QString comma = ",";
    QString doubleQuotes = "\"";

    QString serializedPayload =
            payloadField +
            openBrackets +
            mSerializedValues +
            closeBrackets;

    return serializedPayload.toUtf8();
}
