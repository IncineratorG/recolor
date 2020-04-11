#ifndef RECOLORSCREENMODEL_H
#define RECOLORSCREENMODEL_H

#include "stores/recolor/RecolorState.h"

#include <QObject>
#include <QString>
#include <QColor>

#include <memory>

class RecolorScreenModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath          READ getImagePath                                          NOTIFY imagePathChanged)
    Q_PROPERTY(QString emptyImagePath     READ getEmptyImagePath                                     NOTIFY emptyImagePathChanged)
    Q_PROPERTY(bool selectPixelColorMode  READ getSelectPixelColorMode WRITE setSelectPixelColorMode NOTIFY selectPixelColorModeChanged)
    Q_PROPERTY(QColor targetColor         READ getTargetColor                                        NOTIFY targetColorChanged)
    Q_PROPERTY(QString targetColorHex     READ getTargetColorHex                                     NOTIFY targetColorHexChanged)
    Q_PROPERTY(QColor newColor            READ getNewColor                                           NOTIFY newColorChanged)
    Q_PROPERTY(QString newColorHex        READ getNewColorHex                                        NOTIFY newColorHexChanged)
    Q_PROPERTY(bool busy                  READ getBusy                                               NOTIFY busyChanged)
    // ===
//    Q_PROPERTY(QColor testColor           READ getTestColor                                          NOTIFY testColorChanged)
    // ===

public:
    RecolorScreenModel();

    QString getImagePath() const;
    QString getEmptyImagePath() const;
    bool getSelectPixelColorMode() const;
    QColor getTargetColor() const;
    QString getTargetColorHex() const;
    QColor getNewColor() const;
    QString getNewColorHex() const;
    bool getBusy() const;
    // ===
//    QColor getTestColor() const;
    // ===

    void setSelectPixelColorMode(bool value);

signals:
    void imagePathChanged(QString value);
    void emptyImagePathChanged(QString value);
    void selectPixelColorModeChanged(bool value);
    void targetColorChanged(QColor value);
    void targetColorHexChanged(QString value);
    void newColorChanged(QColor value);
    void newColorHexChanged(QString value);
    void busyChanged(bool value);
    // ===
//    void testColorChanged(QColor value);
    // ===

private:
    std::shared_ptr<RecolorState> mRecolorState;

    QString mImagePath;
    QString mEmptyImagePath;
    bool mSelectPixelColorMode;
    QColor mTargetColor;
    QColor mNewColor;
    bool mBusy;
    // ===
//    QColor mTestColor;
    // ===

    void setImagePath(const QString value);
    void setTargetColor(const QColor value);
    void setNewColor(const QColor value);
    void setBusy(const bool value);
    // ===
//    void setTestColor(const QColor value);
    // ===
};

#endif // RECOLORSCREENMODEL_H
