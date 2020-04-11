#include "Test.h"
#include "models/TestScreenModel.h"
#include "controllers/TestScreenController.h"

Test::Test() {

}

void Test::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("TestScreenController", new TestScreenController());
    ctxt->setContextProperty("TestScreenModel", new TestScreenModel());
}
