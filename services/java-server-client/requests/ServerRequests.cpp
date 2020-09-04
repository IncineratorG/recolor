#include "ServerRequests.h"

#include <QMap>

ServerRequests::ServerRequests() {

}

Request ServerRequests::runLongRunningTaskRequest(int a, int b, const QList<QString> list) {
    QMap<QString, std::any> values;
    values.insert("a", 1);
    values.insert("b", 2);

    const QString doubleQuotes = "\"";
    const QString comma = ",";
    const QString listField = doubleQuotes + "list" + doubleQuotes + ":";

    QString aSerialized = "\"a\":\"" + QString::number(std::any_cast<int>(values.value("a"))) + "\",";
    QString bSerizlized = "\"b\":\"" + QString::number(std::any_cast<int>(values.value("a"))) + "\",";

    QString listSerialized;
    for (int i = 0; i < list.length(); ++i) {
        QString itemSerialized = doubleQuotes + list.at(i) + doubleQuotes;
        listSerialized = listSerialized + itemSerialized;
        if (i < list.length() - 1) {
            listSerialized = listSerialized + comma;
        }
    }
    listSerialized = listField + "[" + listSerialized + "]";

    QString serilizedPayload =
            aSerialized +
            bSerizlized +
            listSerialized;

    RequestPayload payload(values, serilizedPayload);

    Request request("RUN_LONG_RUNNING_TASK", payload);

    return request;
}
