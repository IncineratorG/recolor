#include "RecolorScreenController.h"
#include "stores/Stores.h"
#include "services/recolor/helpers/ColorTools.h"

#include <QDebug>
#include <QImage>
#include <QString>

RecolorScreenController::RecolorScreenController() {
    auto stores = Stores::getInstance();

    mRecolorStore = std::dynamic_pointer_cast<RecolorStore>(
                stores->getStore(Stores::Recolor));
    if (mRecolorStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->MAKE_COLOR_TRANSPARENT_STORE_IS_NULL";
        return;
    }

    auto mRecolorState = std::dynamic_pointer_cast<RecolorState>(mRecolorStore->getState());
    if (mRecolorState == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->RECOLOR_STATE_IS_NULL";
        return;
    }
    auto unsubscribe = mRecolorState->select([this, mRecolorState] () mutable {
       mImagePath = mRecolorState->imagePath;
    });
}

void RecolorScreenController::setImagePath(const QString imagePath) {
    auto payload = std::make_shared<Payload>("imagePath", imagePath);

    auto setImagePathAction = mRecolorStore->
            getActionsFactory()->
            getAction(RecolorActions::SetImagePath);
    setImagePathAction->setPayload(payload);

    mRecolorStore->dispatch(setImagePathAction);
}

void RecolorScreenController::setTargetColor(const int r, const int g, const int b, const int a) {
    QColor color(r, g, b, a);

    auto payload = std::make_shared<Payload>("targetColor", color);

    auto setTargetColorAction = mRecolorStore->
            getActionsFactory()->
            getAction(RecolorActions::SetTargetColor);
    setTargetColorAction->setPayload(payload);

    mRecolorStore->dispatch(setTargetColorAction);
}

void RecolorScreenController::setTargetColorPoint(const int r, const int g, const int b, const int a,
                                                  const int imageXPos, const int imageYPos) {
    QColor targetColor(r, g, b, a);
    QPoint targetPoint(imageXPos, imageYPos);

    auto payload = std::make_shared<Payload>("targetColor", targetColor);
    payload->set("targetPoint", targetPoint);

    auto setTargetColorPointAction = mRecolorStore->
            getActionsFactory()->
            getAction(RecolorActions::SetTargetColorPoint);
    setTargetColorPointAction->setPayload(payload);

    mRecolorStore->dispatch(setTargetColorPointAction);
}

void RecolorScreenController::setNewColor(const QString newColorString) {
    QColor newColor(newColorString);

    if (!newColor.isValid()) {
        if (newColorString.toLower() == "transparent") {
            newColor = QColor(newColorString);
        } else if (newColorString.startsWith("#")) {
            newColor = QColor(newColorString);
        } else {
            newColor = QColor("#" + newColorString);
        }
    }

    auto payload = std::make_shared<Payload>("newColor", newColor);

    auto setNewColorAction = mRecolorStore->
            getActionsFactory()->
            getAction(RecolorActions::SetNewColor);
    setNewColorAction->setPayload(payload);

    mRecolorStore->dispatch(setNewColorAction);
}

void RecolorScreenController::startRecolor() {
    auto startRecolorAction = mRecolorStore->
            getActionsFactory()->
            getAction(RecolorActions::StartRecolor);

    mRecolorStore->dispatch(startRecolorAction);
}

//void RecolorScreenController::test(const int r, const int g, const int b, const int a,
//                                   const int imageXPos, const int imageYPos) {
//    qDebug() << __PRETTY_FUNCTION__;

//    auto recolorState = std::dynamic_pointer_cast<RecolorState>(mRecolorStore->getState());
//    if (recolorState == nullptr) {
//        qDebug() << __PRETTY_FUNCTION__ << "->RECOLOR_STATE_IS_NULL";
//        return;
//    }

//    QColor prevColor = recolorState->targetColor;
//    if (prevColor.isValid()) {
//        qDebug() << "PREV_COLOR: " << prevColor.red() << prevColor.green() << prevColor.blue();

//        QColor currentColor(r, g, b, a);
//        qDebug() << "CURRENT_COLOR: " << currentColor.red() << currentColor.green() << currentColor.blue();

//        ColorTools colorTools;

//        QList<float> prevLAB = colorTools.RGBtoLAB(prevColor.red(),
//                                                   prevColor.green(),
//                                                   prevColor.blue(),
//                                                   colorTools.CIE2_F7);
//        QList<float> currentLAB = colorTools.RGBtoLAB(currentColor.red(),
//                                                      currentColor.green(),
//                                                      currentColor.blue(),
//                                                      colorTools.CIE2_F7);

//        double deltaE = colorTools.deltaE(prevLAB.at(0), prevLAB.at(1), prevLAB.at(2),
//                                            currentLAB.at(0), currentLAB.at(1), currentLAB.at(2));

//        qDebug() << "DELTA_E: " << deltaE;

//        qDebug() << "";
//    }




//    QColor targetColor(r, g, b, a);
//    QPoint targetPoint(imageXPos, imageYPos);

//    auto payload = std::make_shared<Payload>("targetColor", targetColor);
//    payload->set("targetPoint", targetPoint);

//    auto setTargetColorPointAction = mRecolorStore->
//            getActionsFactory()->
//            getAction(RecolorActions::SetTargetColorPoint);
//    setTargetColorPointAction->setPayload(payload);

//    mRecolorStore->dispatch(setTargetColorPointAction);
//}

//void RecolorScreenController::test(const int canvasHeight,
//                                   const int canvasWidth,
//                                   const int mouseXPos,
//                                   const int mouseYPos) {
//    QString qmlFilePrefix = "file:///";

//    QString imagePath(mImagePath);
//    if (imagePath.contains(qmlFilePrefix)) {
//        imagePath.remove(0, qmlFilePrefix.length());
//    }

//    QImage image(imagePath);


//    // ===
//    float heightScale = (float) image.height() / canvasHeight;
//    float widthScale = (float) image.width() / canvasWidth;
//    // ===


//    float imageXPos = mouseXPos * widthScale;
//    float imageYPos = mouseYPos * heightScale;

//    qDebug() << imageXPos << " - " << imageYPos;

//    QPoint p(imageXPos, imageYPos);

//    QColor pColor = image.pixelColor(p);

//    auto mRecolorState = std::dynamic_pointer_cast<RecolorState>(mRecolorStore->getState());
//    if (mRecolorState == nullptr) {
//        qDebug() << __PRETTY_FUNCTION__ << "->RECOLOR_STATE_IS_NULL";
//        return;
//    }
//    mRecolorState->update([mRecolorState, pColor] () {
//       mRecolorState->testColor = pColor;
//    });
//}
