#include "RecolorPipeline.h"

#include <QDebug>
#include <QThread>

RecolorPipeline::RecolorPipeline()
    : mQmlFilePrefix("file:///") {

}

void RecolorPipeline::startPipeline(const QString& imagePath,
                                    const QColor& targetColor,
                                    const QPoint& targetPoint,
                                    const QColor& newColor) {
//    qDebug() << __PRETTY_FUNCTION__ << targetColor.red() << targetColor.green() << targetColor.blue();

    QString targetImagePath(imagePath);
    if (targetImagePath.contains(mQmlFilePrefix)) {
        targetImagePath.remove(0, mQmlFilePrefix.length());
    }

    bool badData = isInputDataValid(targetImagePath, targetColor, newColor);

    if (badData) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_INPUT_DATA";
        emit pipelineFinished(QImage());
        return;
    }

    QImage image(targetImagePath);
    if (image.isNull()) {
        qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_IS_NULL";
        emit pipelineFinished(QImage());
        return;
    }

    QString imageFormat = imagePath.mid(imagePath.lastIndexOf("."));

    const QList<QPoint>& points = getPointsToRecolor(image, targetColor, targetPoint);
    qDebug() << __PRETTY_FUNCTION__ << "->POINTS_SIZE: " << points.length();

    emit pipelineFinished(QImage());
}

//void RecolorPipeline::startPipeline(const QString& imagePath,
//                                    const QColor& targetColor,
//                                    const QPoint& targetPoint,
//                                    const QColor& newColor) {
////    qDebug() << __PRETTY_FUNCTION__ << targetColor.red() << targetColor.green() << targetColor.blue();

//    QString targetImagePath(imagePath);
//    if (targetImagePath.contains(mQmlFilePrefix)) {
//        targetImagePath.remove(0, mQmlFilePrefix.length());
//    }

//    bool badData = isInputDataValid(targetImagePath, targetColor, newColor);

//    if (badData) {
//        qDebug() << __PRETTY_FUNCTION__ << "->BAD_INPUT_DATA";
//        emit pipelineFinished(QImage());
//        return;
//    }

//    QImage image(targetImagePath);
//    if (image.isNull()) {
//        qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_IS_NULL";
//        emit pipelineFinished(QImage());
//        return;
//    }

//    QString imageFormat = imagePath.mid(imagePath.lastIndexOf("."));

//    // ===
//    ColorTools colorTools;
//    // ===

//    image = image.convertToFormat(QImage::Format_ARGB32);

//    QColor color(targetColor);
//    qDebug() << __PRETTY_FUNCTION__ << color.red() << color.green() << color.blue();
//    QList<float> targetLAB = colorTools.RGBtoLAB(color.red(),
//                                                 color.green(),
//                                                 color.blue(),
//                                                 colorTools.CIE2_F7);

//    qDebug() << __PRETTY_FUNCTION__ << targetLAB;



////    for (int x = 0; x < image.width(); ++x) {
////        for (int y = 0; y < image.height(); ++y) {
////            QPoint p(x, y);

////            // ===
////            QColor color = image.pixelColor(p);
////            colorTools.RGBtoLAB(color.red(),
////                                color.green(),
////                                color.blue(),
////                                colorTools.CIE2_A);
////            // ===

//////            if (image.pixelColor(p) == targetColor) {
//////                image.setPixelColor(x, y, newColor);
//////            }
////        }
////    }

//    emit pipelineFinished(QImage());
//}

//void RecolorPipeline::startPipeline(const QString& imagePath,
//                                    const QColor& targetColor,
//                                    const QColor& newColor) {
//    qDebug() << __PRETTY_FUNCTION__;

//    QString targetImagePath(imagePath);
//    if (targetImagePath.contains(mQmlFilePrefix)) {
//        targetImagePath.remove(0, mQmlFilePrefix.length());
//    }

//    bool badData = isInputDataValid(targetImagePath, targetColor, newColor);

//    if (badData) {
//        emit pipelineFinished(QImage());
//        return;
//    }

//    QImage image(targetImagePath);
//    if (image.isNull()) {
//        qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_IS_NULL";
//        emit pipelineFinished(QImage());
//        return;
//    }

//    QString imageFormat = imagePath.mid(imagePath.lastIndexOf("."));

//    image = image.convertToFormat(QImage::Format_ARGB32);
//    for (int x = 0; x < image.width(); ++x) {
//        for (int y = 0; y < image.height(); ++y) {
//            QPoint p(x, y);
//            if (image.pixelColor(p) == targetColor) {
//                image.setPixelColor(x, y, newColor);
//            }
//        }
//    }

//    QString convertedImagePath = targetImagePath;
//    convertedImagePath = convertedImagePath.insert(convertedImagePath.lastIndexOf(imageFormat), "converted");

//    image.save(convertedImagePath);

//    emit pipelineFinished(image);
//}

bool RecolorPipeline::isInputDataValid(const QString& imagePath,
                                       const QColor& targetColor,
                                       const QColor& newColor) {
    bool badData = false;
    if (imagePath.isEmpty()) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_IMAGE_PATH: " << imagePath;
        badData = true;
    } else if (!targetColor.isValid()) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_TARGET_COLOR: " << targetColor;
        badData = true;
    } else if (!newColor.isValid()) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_NEW_COLOR: " << newColor;
        badData = true;
    }

    return badData;
}

const QList<QPoint> RecolorPipeline::getPointsToRecolor(const QImage& image,
                                                        const QColor& targetColor,
                                                        const QPoint& targetPoint) {
    const double maximumDeltaE = 5.0;

    ColorTools colorTools;

    QList<QPoint> points;

    const QList<float>& targetLAB = colorTools.RGBtoLAB(targetColor.red(),
                                                        targetColor.green(),
                                                        targetColor.blue(),
                                                        colorTools.CIE2_F7);

    QPoint initialPoint(targetPoint);
    QPoint currentPoint(targetPoint);

    QSet<QPoint> visitedPoints;
    QSet<QPoint> borderPoints;

    while (true) {
        const QPair<bool, QPoint>& nextPointData = getNextPoint(image,
                                                                currentPoint,
                                                                initialPoint,
                                                                visitedPoints,
                                                                borderPoints,
                                                                targetLAB,
                                                                maximumDeltaE,
                                                                colorTools);

        if (!nextPointData.first) {
            break;
        }



//        const QColor& currentColor = image.pixelColor(currentPoint);

//        const QList<float> currentLAB = colorTools.RGBtoLAB(currentColor.red(),
//                                                            currentColor.green(),
//                                                            currentColor.blue(),
//                                                            colorTools.CIE2_F7);

//        const double deltaE = colorTools.deltaE(targetLAB.at(0), targetLAB.at(1), targetLAB.at(2),
//                                                currentLAB.at(0), currentLAB.at(1), currentLAB.at(2));

//        if (deltaE < maximumDeltaE) {
//            points.append(currentPoint);
//        }

//        break;
    }

    return points;
}

const QPair<bool, QPoint> RecolorPipeline::getNextPoint(const QImage& image,
                                                        const QPoint& currentPoint,
                                                        const QPoint& initialPoint,
                                                        const QSet<QPoint>& visitedPoints,
                                                        QSet<QPoint>& borderPoints,
                                                        const QList<float>& targetPointLAB,
                                                        const double maxDeltaE,
                                                        const ColorTools& colorTools) const {
    const int currentPointX = currentPoint.x();
    const int currentPointY = currentPoint.y();

    QPoint nextPoint(currentPointX + 1, currentPointY);

    const QColor& nextPointColor = image.pixelColor(nextPoint);
    if (nextPointColor.isValid() &&
        !visitedPoints.contains(nextPoint) &&
        !borderPoints.contains(nextPoint)) {
        const QList<float>& nextPointLAB = colorTools.RGBtoLAB(nextPointColor.red(),
                                                               nextPointColor.green(),
                                                               nextPointColor.blue(),
                                                               colorTools.CIE2_F7);
        const double deltaE = colorTools.deltaE(targetPointLAB.at(0), targetPointLAB.at(1), targetPointLAB.at(2),
                                                nextPointLAB.at(0), nextPointLAB.at(1), nextPointLAB.at(2));
        if (deltaE < maxDeltaE) {
            return qMakePair(true, nextPoint);
        }
    }

    return qMakePair(false, QPoint());
}
//const QPair<bool, QPoint> RecolorPipeline::getNextPoint(const QImage& image,
//                                                        const QPoint& currentPoint,
//                                                        const QPoint& initialPoint,
//                                                        const QSet<QPoint>& visitedPoints,
//                                                        QSet<QPoint>& borderPoints,
//                                                        const QList<float>& targetPointLAB,
//                                                        const double maxDeltaE,
//                                                        const ColorTools& colorTools) const {
//    const int currentPointX = currentPoint.x();
//    const int currentPointY = currentPoint.y();

//    QPoint nextPoint(currentPointX + 1, currentPointY);

//    const QColor& nextPointColor = image.pixelColor(nextPoint);
//    if (nextPointColor.isValid() &&
//        !visitedPoints.contains(nextPoint) &&
//        !borderPoints.contains(nextPoint)) {
//        const QList<float>& nextPointLAB = colorTools.RGBtoLAB(nextPointColor.red(),
//                                                               nextPointColor.green(),
//                                                               nextPointColor.blue(),
//                                                               colorTools.CIE2_F7);
//        const double deltaE = colorTools.deltaE(targetPointLAB.at(0), targetPointLAB.at(1), targetPointLAB.at(2),
//                                                nextPointLAB.at(0), nextPointLAB.at(1), nextPointLAB.at(2));
//        if (deltaE < maxDeltaE) {
//            return qMakePair(true, nextPoint);
//        }
//    }

//    return qMakePair(false, QPoint());
//}
