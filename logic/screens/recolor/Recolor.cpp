#include "Recolor.h"
#include "logic/screens/recolor/models/RecolorScreenModel.h"
#include "logic/screens/recolor/controllers/RecolorScreenController.h"

Recolor::Recolor() {

}

void Recolor::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("RecolorScreenController", new RecolorScreenController());
    ctxt->setContextProperty("RecolorScreenModel", new RecolorScreenModel());
}
