import QtQuick 2.0
import "../../components/java-server"

Item {
    Rectangle {
        id: mainFieldWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: rightPannelWrapper.left
    }

    Item {
        id: rightPannelWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        width: 200

        RightPanel {
            anchors.fill: parent
        }
    }
}
