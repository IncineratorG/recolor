import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3

Rectangle {
    color: '#00796B'

    Rectangle {
        id: colorsWrapper

        anchors.top: parent.top
        anchors.bottom: busyIndicatorWrapper.top
        anchors.left: parent.left
        anchors.right: parent.right

        color: 'transparent'

        Item {
            id: targetColorWidgetWrapper

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: targetColorWidget.height

            TargetColorWidget {
                id: targetColorWidget

                anchors.fill: parent
            }
        }

        Item {
            id: newColorWidgetWrapper

            anchors.top: targetColorWidgetWrapper.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: newColorWidget.height

            NewColorWidget {
                id: newColorWidget

                anchors.fill: parent
            }
        }
    }

    Rectangle {
        id: busyIndicatorWrapper

        anchors.bottom: buttonsWrapper.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        height: 25

        color: RecolorScreenModel.busy ? 'yellow' : 'transparent'
    }

    Rectangle {
        id: buttonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 62

        color: 'transparent'

        Button {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: 'Выбрать изображение'

            onClicked: {
                fileDialog.open()
            }
        }

        Button {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: 25

            text: 'Начать'

            onClicked: {
                RecolorScreenController.startRecolor()
            }
        }
    }

    FileDialog {
        id: fileDialog

        visible: false

        selectFolder: false

        title: "Выберите изображение"

        onAccepted: {
            RecolorScreenController.setImagePath(fileDialog.fileUrl)
        }
    }
}
