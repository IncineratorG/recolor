#ifndef RECOLORPIPELINE_H
#define RECOLORPIPELINE_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QImage>
#include <QList>
#include <QPair>

class RecolorPipeline : public QObject
{
    Q_OBJECT

public:
    RecolorPipeline();

public slots:
    void startPipeline(const QString& imagePath,
                       const QColor& targetColor,
                       const QPoint& targetPoint,
                       const QColor& newColor);

signals:
    void pipelineFinished(const QImage& finalImage);

private:
    const QString mQmlFilePrefix;

    bool isInputDataValid(const QString& imagePath,
                          const QColor& targetColor,
                          const QColor& newColor);

    const QList<QPoint> getPointsToRecolor(const QImage& image,
                                           const QColor& targetColor,
                                           const QPoint& targetPoint);
    const QPair<bool, QPoint> getNextPoint(const QImage& image,
                                           const QPoint& currentPoint,
                                           const QList<float>& targetPointLAB,
                                           const double maxDeltaE) const;
};

#endif // RECOLORPIPELINE_H
