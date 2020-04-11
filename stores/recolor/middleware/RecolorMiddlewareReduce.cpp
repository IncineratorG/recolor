#include "RecolorMiddlewareReduce.h"

#include <QDebug>

RecolorMiddlewareReduce::RecolorMiddlewareReduce() {

}

void RecolorMiddlewareReduce::setImagePath(std::shared_ptr<RecolorState> state,
                                           std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto imagePath = std::any_cast<QString>(payload->get("imagePath"));

        state->update([state, imagePath] () {
           state->imagePath = imagePath;
           state->targetColor = QColor();
        });
    } catch (const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void RecolorMiddlewareReduce::setTargetColor(std::shared_ptr<RecolorState> state,
                                             std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto targetColor = std::any_cast<QColor>(payload->get("targetColor"));

        state->update([state, targetColor] () {
           state->targetColor = targetColor;
        });
    } catch (const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void RecolorMiddlewareReduce::setTargetColorPoint(std::shared_ptr<RecolorState> state,
                                                  std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto targetColor = std::any_cast<QColor>(payload->get("targetColor"));
        auto targetPoint = std::any_cast<QPoint>(payload->get("targetPoint"));

        state->update([state, targetColor, targetPoint] () {
           state->targetColor = targetColor;
           state->targetPoint = targetPoint;
        });
    } catch (const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void RecolorMiddlewareReduce::setNewColor(std::shared_ptr<RecolorState> state,
                                          std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto newColor = std::any_cast<QColor>(payload->get("newColor"));

        state->update([state, newColor] () {
           state->newColor = newColor;
        });
    } catch (const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

//void RecolorMiddlewareReduce::startRecolor(std::shared_ptr<RecolorState> state,
//                                           std::shared_ptr<Action> action) {
//    qDebug() << __PRETTY_FUNCTION__;
//}
