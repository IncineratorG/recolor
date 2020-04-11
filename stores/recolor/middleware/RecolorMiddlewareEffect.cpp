#include "RecolorMiddlewareEffect.h"

#include <QDebug>

RecolorMiddlewareEffect::RecolorMiddlewareEffect() {

}

void RecolorMiddlewareEffect::startRecolor(std::shared_ptr<RecolorState> state,
                                           std::shared_ptr<Action> action,
                                           std::shared_ptr<RecolorService> service) {
    const QString& imagePath = state->imagePath;
    const QColor& targetColor = state->targetColor;
    const QPoint& targetPoint = state->targetPoint;
    const QColor& newColor = state->newColor;

    if (imagePath.isEmpty()) {
        qDebug() << __PRETTY_FUNCTION__ << "->EMPTY_IMAGE_PATH";
        return;
    } else if (!targetColor.isValid()) {
        qDebug() << __PRETTY_FUNCTION__ << "->INVALID_TARGET_COLOR";
        return;
    } else if (!newColor.isValid()) {
        qDebug() << __PRETTY_FUNCTION__ << "->INVALID_NEW_COLOR";
        return;
    }


    state->update([state] () {
       state->recoloring = true;
    });

    service->recolor(imagePath, targetColor, targetPoint, newColor, [state] (const QImage& finalImage) {
        qDebug() << __PRETTY_FUNCTION__ << "->SERVICE_FINISHED";

        state->update([state] () {
           state->recoloring = false;
        });
    });
}
