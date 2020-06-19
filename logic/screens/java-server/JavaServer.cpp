#include "JavaServer.h"
#include "models/JavaServerScreenModel.h"
#include "controllers/JavaServerScreenController.h"

JavaServer::JavaServer() {

}

void JavaServer::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("JavaServerScreenController", new JavaServerScreenController());
    ctxt->setContextProperty("JavaServerScreenModel", new JavaServerScreenModel());
}
