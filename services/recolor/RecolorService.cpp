#include "RecolorService.h"

#include <QDebug>

RecolorService::RecolorService() {
    connect(this,
            SIGNAL(startPipeline(const QString&, const QColor&, const QPoint&, const QColor&)),
            &mPipeline,
            SLOT(startPipeline(const QString&, const QColor&, const QPoint&, const QColor&)));
    connect(&mPipeline,
            SIGNAL(pipelineFinished(const QImage&)),
            this,
            SLOT(onPipelineFinished(const QImage&)));

    mPipeline.moveToThread(&mThread);
    mThread.start();
}

void RecolorService::recolor(const QString imagePath,
                             const QColor targetColor,
                             const QPoint targetPoint,
                             const QColor newColor,
                             std::function<void (const QImage &)> callback) {

    qDebug() << __PRETTY_FUNCTION__;

    mCallbacks.append(callback);

    emit startPipeline(imagePath, targetColor, targetPoint, newColor);
}

void RecolorService::onPipelineFinished(const QImage& finalImage) {
    for (int i = 0; i < mCallbacks.size(); ++i) {
        mCallbacks.at(i)(finalImage);
    }

    mCallbacks.clear();
}
