#include "ServerActions.h"

#include <QString>

ServerActions::ServerActions() {
//    QString actionString("{\"a\":11,\"s\":\"string\",\"list\":[\"A\",\"B\",\"C\"]}\r\n");
}

QByteArray ServerActions::getDataAction() {
    QString actionString("{\"type\":\"GET_DATA\"}\r\n");
    return actionString.toUtf8();
}

QByteArray ServerActions::getOffAction() {
    QString actionString("{\"type\":\"STOP_SERVER\"}\r\n");
    return actionString.toUtf8();
}

QByteArray ServerActions::runLongRunningTaskAction() {
    QString actionString("{\"type\":\"RUN_LONG_RUNNING_TASK\"}\r\n");
    return actionString.toUtf8();
}
