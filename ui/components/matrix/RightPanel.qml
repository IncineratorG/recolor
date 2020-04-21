import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle {
    color: '#00796B'

    Item {
        id: buttonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 200

        Button {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: "Button One"

            onClicked: {
                MatrixScreenController.test()
            }
        }
    }
}
