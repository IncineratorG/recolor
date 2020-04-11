#ifndef RECOLORSERVICE_H
#define RECOLORSERVICE_H

#include "common/libs/service/Service.h"
#include "pipeline/RecolorPipeline.h"

#include <QObject>
#include <QString>
#include <QColor>
#include <QImage>
#include <QThread>
#include <QList>

#include <functional>

class RecolorService : public QObject, public Service
{
    Q_OBJECT

public:
    RecolorService();

    void recolor(const QString imagePath,
                 const QColor targetColor,
                 const QPoint targetPoint,
                 const QColor newColor,
                 std::function<void(const QImage& finalImage)> callback);

signals:
    void startPipeline(const QString& imagePath,
                       const QColor& targetColor,
                       const QPoint& targetPoint,
                       const QColor& newColor);

private slots:
    void onPipelineFinished(const QImage& finalImage);

private:
    QThread mThread;
    QList<std::function<void(const QImage& finalImage)>> mCallbacks;
    RecolorPipeline mPipeline;
};

#endif // RECOLORSERVICE_H
