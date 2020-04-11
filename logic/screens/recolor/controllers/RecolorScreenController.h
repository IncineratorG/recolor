#ifndef RECOLORSCREENCONTROLLER_H
#define RECOLORSCREENCONTROLLER_H

#include "stores/recolor/RecolorStore.h"

#include <QObject>

class RecolorScreenController : public QObject
{
    Q_OBJECT

public:
    RecolorScreenController();

    Q_INVOKABLE void setImagePath(const QString imagePath);
    Q_INVOKABLE void setTargetColor(const int r, const int g, const int b, const int a);
    Q_INVOKABLE void setTargetColorPoint(const int r, const int g, const int b, const int a,
                                         const int imageXPos, const int imageYPos);
    Q_INVOKABLE void setNewColor(const QString newColorString);
    Q_INVOKABLE void startRecolor();

//    Q_INVOKABLE void test(const int r, const int g, const int b, const int a,
//                          const int imageXPos, const int imageYPos);

//    Q_INVOKABLE void test(const int canvasHeight,
//                          const int canvasWidth,
//                          const int mouseXPos,
//                          const int mouseYPos);

private:
    std::shared_ptr<RecolorStore> mRecolorStore;

    QString mImagePath;
};

#endif // RECOLORSCREENCONTROLLER_H
