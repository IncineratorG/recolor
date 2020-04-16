#ifndef RECOLORPIPELINE_H
#define RECOLORPIPELINE_H

#include "../helpers/ColorTools.h"

#include <QObject>
#include <QString>
#include <QColor>
#include <QImage>
#include <QList>
#include <QPair>
#include <QSet>

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
                                           const QPoint& initialPoint,
                                           const QSet<QPoint>& visitedPoints,
                                           QSet<QPoint>& borderPoints,
                                           const QList<float>& targetPointLAB,
                                           const double maxDeltaE,
                                           const ColorTools& colorTools) const;
};

inline uint qHash (const QPoint & key) {
    return qHash (QPair<int,int>(key.x(), key.y()) );
}


#endif // RECOLORPIPELINE_H
