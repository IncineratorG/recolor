import QtQuick 2.0
import "../../components/recolor"

Item {
    Item {
        id: imageWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: leftPanelWrapper.right
        anchors.right: parent.right

        anchors.margins: 4

        SelectableImage {
            anchors.fill: parent
        }
    }

    Item {
        id: leftPanelWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        width: 200

        LeftActionsPanel {
            anchors.fill: parent
        }
    }
}
