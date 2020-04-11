import QtQuick 2.0

Rectangle {
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        height: 30

        color: 'red'

        MouseArea {
            anchors.fill: parent

            onClicked: {
                TestScreenController.test()
            }
        }
    }
}
