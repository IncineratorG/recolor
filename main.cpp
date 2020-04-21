#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "logic/screens/test/Test.h"
#include "logic/screens/recolor/Recolor.h"
#include "logic/screens/matrix/Matrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Test* testScreen = new Test();
    testScreen->registerScreen(engine.rootContext());

    Recolor* recolorScreen = new Recolor();
    recolorScreen->registerScreen(engine.rootContext());

    Matrix* matrixScreen = new Matrix();
    matrixScreen->registerScreen(engine.rootContext());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
