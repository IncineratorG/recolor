import QtQuick 2.12

Rectangle {
    height: 50

    color: 'lightgrey'

    border.width: 1
    border.color: 'lightgrey'

    Item {
        id: newColorLabelWrapper

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 25

        Text {
            id: newColorLabel

            anchors.left: parent.left

            width: parent.width
            height: parent.height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: "Новый цвет"
            clip: true
            elide: Text.ElideRight
        }
    }

    Rectangle {
        id: newColorWrapper

        anchors.top: newColorLabelWrapper.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.bottomMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

        height: 21

        color: RecolorScreenModel.newColor

        TextEdit {
            id: newColorHex

            anchors.left: parent.left

            width: parent.width
            height: parent.height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: RecolorScreenModel.newColorHex
            clip: true
            readOnly: false
            selectByMouse: true
            wrapMode: Text.WordWrap
            cursorVisible: true

            Keys.onReturnPressed: {
                RecolorScreenController.setNewColor(newColorHex.text)
            }
        }
    }
}
