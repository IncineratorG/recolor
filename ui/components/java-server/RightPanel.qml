import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle {
    color: '#00796B'

    Item {
        id: buttonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 250

        Button {
            id: startButton

            anchors.bottom: stopButton.top
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: "Start"

            onClicked: {
                JavaServerScreenController.startService()
            }
        }

        Button {
            id: stopButton

            anchors.bottom: sendButton.top
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: "Stop"

            onClicked: {
                JavaServerScreenController.stopService()
            }
        }

        Button {
            id: sendButton

            anchors.bottom: longRunnigTaskButton.top
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: "Send"

            onClicked: {
                JavaServerScreenController.sendData()
            }
        }

        Button {
            id: longRunnigTaskButton

            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: "Run Long Task"

            onClicked: {
                JavaServerScreenController.runLongRunningServerTask()
            }
        }
    }
}
