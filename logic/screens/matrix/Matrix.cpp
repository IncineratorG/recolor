#include "Matrix.h"
#include "models/MatrixScreenModel.h"
#include "controllers/MatrixScreenController.h"

Matrix::Matrix() {

}

void Matrix::registerScreen(QQmlContext* ctxt) {
    ctxt->setContextProperty("MatrixScreenController", new MatrixScreenController());
    ctxt->setContextProperty("MatrixScreenModel", new MatrixScreenModel());
}

