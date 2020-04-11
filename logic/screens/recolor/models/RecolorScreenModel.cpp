#include "RecolorScreenModel.h"
#include "stores/Stores.h"

#include <QDebug>

RecolorScreenModel::RecolorScreenModel() {
    mEmptyImagePath = "";

    auto stores = Stores::getInstance();

    auto recolorStore = std::dynamic_pointer_cast<RecolorStore>(
                stores->getStore(Stores::Recolor));
    if (recolorStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->RECOLOR_STORE_IS_NULL";
        return;
    }

    mRecolorState = std::dynamic_pointer_cast<RecolorState>(recolorStore->getState());
    if (mRecolorState == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->RECOLOR_STATE_IS_NULL";
        return;
    }

    mRecolorState->select([this] () {
        setImagePath(mRecolorState->imagePath);        
        setTargetColor(mRecolorState->targetColor);
        setNewColor(mRecolorState->newColor);
        setBusy(mRecolorState->recoloring);
        // ===
//        setTestColor(mRecolorState->testColor);
        // ===
    });
}

QString RecolorScreenModel::getImagePath() const {
    return mImagePath;
}

QString RecolorScreenModel::getEmptyImagePath() const {
    return mEmptyImagePath;
}

bool RecolorScreenModel::getSelectPixelColorMode() const {
    return mSelectPixelColorMode;
}

QColor RecolorScreenModel::getTargetColor() const {
    if (mTargetColor.isValid()) {
        return mTargetColor;
    } else {
        return QColor("white");
    }
}

QString RecolorScreenModel::getTargetColorHex() const {
    if (mTargetColor.isValid()) {
        return mTargetColor.name();
    } else {
        return "Цвет не выбран";
    }
}

QColor RecolorScreenModel::getNewColor() const {
    if (mNewColor.isValid()) {
        return mNewColor;
    } else {
        return QColor("white");
    }
}

QString RecolorScreenModel::getNewColorHex() const {
    if (mNewColor.isValid()) {
        return mNewColor.name();
    } else {
        return "Цвет не задан";
    }
}

bool RecolorScreenModel::getBusy() const {
    return mBusy;
}
// ===
//QColor RecolorScreenModel::getTestColor() const {
//    if (mTestColor.isValid()) {
//        return mTestColor;
//    } else {
//        return QColor("purple");
//    }
//}
// ===

void RecolorScreenModel::setImagePath(const QString value) {
    mImagePath = value;
    emit imagePathChanged(getImagePath());
}

void RecolorScreenModel::setSelectPixelColorMode(bool value) {
    mSelectPixelColorMode = value;
    emit selectPixelColorModeChanged(getSelectPixelColorMode());
}

void RecolorScreenModel::setTargetColor(const QColor value) {
    mTargetColor = value;

    emit targetColorChanged(getTargetColor());
    emit targetColorHexChanged(getTargetColorHex());
}

void RecolorScreenModel::setNewColor(const QColor value) {
    mNewColor = value;

    emit newColorChanged(getNewColor());
    emit newColorHexChanged(getNewColorHex());
}

void RecolorScreenModel::setBusy(const bool value) {
    mBusy = value;

    emit busyChanged(getBusy());
}
// ===
//void RecolorScreenModel::setTestColor(const QColor value) {
//    mTestColor = value;

//    emit testColorChanged(getTestColor());
//}
// ===
