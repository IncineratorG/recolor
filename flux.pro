QT += quick
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    logic/screens/test/controllers/TestScreenController.cpp \
    logic/screens/test/Test.cpp \
    logic/screens/test/models/TestScreenModel.cpp \
    common/libs/redux/Payload.cpp \
    common/libs/redux/Action.cpp \
    common/libs/redux/ActionsFactory.cpp \
    common/libs/redux/State.cpp \
    common/libs/redux/Store.cpp \
    common/libs/service/Service.cpp \
    common/libs/reactive/Executable.cpp \
    common/libs/reactive/Subscription.cpp \
    common/libs/reactive/Observable.cpp \
    common/libs/reactive/ObservableLike.cpp \
    common/libs/reactive/Subscriber.cpp \
    common/libs/reactive/Subscribers.cpp \
    common/libs/reactive/ObservableProperty.cpp \
    stores/test/TestStore.cpp \
    stores/Stores.cpp \
    stores/test/TestActions.cpp \
    stores/test/TestState.cpp \
    logic/screens/recolor/Recolor.cpp \
    logic/screens/recolor/controllers/RecolorScreenController.cpp \
    logic/screens/recolor/models/RecolorScreenModel.cpp \
    common/libs/native-screen/NativeScreen.cpp \
    stores/recolor/RecolorStore.cpp \
    stores/recolor/RecolorActions.cpp \
    stores/recolor/RecolorState.cpp \
    stores/recolor/actions/SetImagePathAction.cpp \
    stores/recolor/actions/SetTargetColorAction.cpp \
    stores/recolor/actions/SetNewColorAction.cpp \
    stores/recolor/middleware/RecolorMiddlewareReduce.cpp \
    stores/recolor/actions/StartRecolorAction.cpp \
    stores/recolor/middleware/RecolorMiddlewareEffect.cpp \
    services/recolor/RecolorService.cpp \
    services/recolor/pipeline/RecolorPipeline.cpp \
    services/recolor/helpers/ColorTools.cpp \
    stores/recolor/actions/SetTargetColorPointAction.cpp \
    logic/screens/matrix/Matrix.cpp \
    logic/screens/matrix/controllers/MatrixScreenController.cpp \
    logic/screens/matrix/models/MatrixScreenModel.cpp \
    common/data/simple-matrix/SimpleMatrix.cpp \
    common/data/neural-network/NN_1.cpp \
    common/data/neural-network/activation-functions/sigmoid/Sigmoid.cpp \
    common/data/neural-network/activation-functions/abstract/ActivationFunction.cpp \
    logic/screens/java-server/JavaServer.cpp \
    logic/screens/java-server/models/JavaServerScreenModel.cpp \
    logic/screens/java-server/controllers/JavaServerScreenController.cpp \
    services/java-server-client/JavaServerClientService.cpp \
    stores/java-server-client/JSCStore.cpp \
    stores/java-server-client/JSCState.cpp \
    stores/java-server-client/JSCActions.cpp \
    stores/test/actions/TestAction.cpp \
    stores/java-server-client/actions/JSCTestAction.cpp \
    stores/java-server-client/actions/StartJavaServerClientAction.cpp \
    stores/java-server-client/actions/StopJavaServerClientAction.cpp \
    stores/java-server-client/middleware/JSCMiddlewareReduce.cpp \
    stores/java-server-client/middleware/JSCMiddlewareEffect.cpp \
    stores/java-server-client/actions/SendDataAction.cpp \
    services/java-server-client/bridge/Bridge.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    logic/screens/test/controllers/TestScreenController.h \
    logic/screens/test/Test.h \
    logic/screens/test/models/TestScreenModel.h \
    common/libs/redux/Payload.h \
    common/libs/redux/Action.h \
    common/libs/redux/ActionsFactory.h \
    common/libs/redux/State.h \
    common/libs/redux/Store.h \
    common/libs/service/Service.h \
    common/libs/reactive/Executable.h \
    common/libs/reactive/Subscription.h \
    common/libs/reactive/Observable.h \
    common/libs/reactive/ObservableLike.h \
    common/libs/reactive/Subscriber.h \
    common/libs/reactive/Subscribers.h \
    common/libs/reactive/ObservableProperty.h \
    stores/test/TestStore.h \
    stores/Stores.h \
    stores/test/TestActions.h \
    stores/test/TestState.h \
    logic/screens/recolor/Recolor.h \
    logic/screens/recolor/controllers/RecolorScreenController.h \
    logic/screens/recolor/models/RecolorScreenModel.h \
    common/libs/native-screen/NativeScreen.h \
    stores/recolor/RecolorStore.h \
    stores/recolor/RecolorActions.h \
    stores/recolor/RecolorState.h \
    stores/recolor/actions/SetImagePathAction.h \
    stores/recolor/actions/SetTargetColorAction.h \
    stores/recolor/actions/SetNewColorAction.h \
    stores/recolor/middleware/RecolorMiddlewareReduce.h \
    stores/recolor/actions/StartRecolorAction.h \
    stores/recolor/middleware/RecolorMiddlewareEffect.h \
    services/recolor/RecolorService.h \
    services/recolor/pipeline/RecolorPipeline.h \
    services/recolor/helpers/ColorTools.h \
    stores/recolor/actions/SetTargetColorPointAction.h \
    logic/screens/matrix/Matrix.h \
    logic/screens/matrix/controllers/MatrixScreenController.h \
    logic/screens/matrix/models/MatrixScreenModel.h \
    common/data/simple-matrix/SimpleMatrix.h \
    common/data/neural-network/NN_1.h \
    common/data/neural-network/activation-functions/sigmoid/Sigmoid.h \
    common/data/neural-network/activation-functions/abstract/ActivationFunction.h \
    logic/screens/java-server/JavaServer.h \
    logic/screens/java-server/models/JavaServerScreenModel.h \
    logic/screens/java-server/controllers/JavaServerScreenController.h \
    services/java-server-client/JavaServerClientService.h \
    stores/java-server-client/JSCStore.h \
    stores/java-server-client/JSCState.h \
    stores/java-server-client/JSCActions.h \
    stores/test/actions/TestAction.h \
    stores/java-server-client/actions/JSCTestAction.h \
    stores/java-server-client/actions/StartJavaServerClientAction.h \
    stores/java-server-client/actions/StopJavaServerClientAction.h \
    stores/java-server-client/middleware/JSCMiddlewareReduce.h \
    stores/java-server-client/middleware/JSCMiddlewareEffect.h \
    stores/java-server-client/actions/SendDataAction.h \
    services/java-server-client/bridge/Bridge.h
