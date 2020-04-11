import QtQuick 2.0

Rectangle {
    height: 50

    color: 'lightgrey'

    border.width: 1
    border.color: 'lightgrey'

    Item {
        id: targetColorLabelWrapper

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 25

        Text {
            id: targetColorLabel

            anchors.left: parent.left

            width: parent.width
            height: parent.height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: "Выбранный цвет"
            clip: true
            elide: Text.ElideRight
        }
    }

    Rectangle {
        id: targetColorWrapper

        anchors.top: targetColorLabelWrapper.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.bottomMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

        height: 21

        color: RecolorScreenModel.targetColor

        TextEdit {
            id: targetColorHex

            anchors.left: parent.left

            width: parent.width
            height: parent.height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: RecolorScreenModel.targetColorHex
            clip: true
            readOnly: true
            selectByMouse: true
            wrapMode: Text.WordWrap
//            elide: Text.ElideRight
        }
    }
}
