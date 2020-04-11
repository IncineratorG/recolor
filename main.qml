import QtQuick 2.9
import QtQuick.Controls 2.2
import "ui/components/main-coordinator"

ApplicationWindow {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Flux")

    MainCoordinator {
        anchors.fill: parent
    }
}
