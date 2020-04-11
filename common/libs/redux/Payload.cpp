#include "Payload.h"

Payload::Payload() {

}

Payload::Payload(const QString& key, std::any value) {
    mObjects.insert(key, value);
}

void Payload::set(const QString& key, std::any value) {
    mObjects.insert(key, value);
}

std::any Payload::get(const QString& key) const {
    std::any value;

    if (mObjects.contains(key)) {
        value = mObjects.value(key);
    }

    return value;
}
