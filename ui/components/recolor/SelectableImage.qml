import QtQuick 2.12
import QtQuick.Window 2.12

//Rectangle {
//    color: 'transparent'

//    border.width: 1
//    border.color: "grey"

//    Image {
//        anchors.fill: parent

//        source: RecolorScreenModel.imagePath
//    }
//}

//Rectangle {
//    color: 'transparent'

//    border.width: 1
//    border.color: "grey"

//    Flickable {
//        anchors.fill: parent

//        contentWidth: canvas.width // no need for future assignment
//        contentHeight: canvas.height

//        Canvas {
//            id: canvas

//            anchors.fill: parent

//            visible: true

//            property string imagePathProp: RecolorScreenModel.imagePath
//            property bool emptyImagePathProp: RecolorScreenModel.emptyImagePath

//            onImagePathPropChanged: {
//                if (imagePathProp !== emptyImagePathProp) {
//                    canvas.loadImage(imagePathProp)
//                }
//            }

//            MouseArea {
//                anchors.fill: parent

//                onClicked: {
//    //                var r = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[0]
//    //                var g = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[1]
//    //                var b = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[2]
//    //                var a = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[3]

//                    var imageData = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1);

//                    var r = imageData.data[0]
//                    var g = imageData.data[1]
//                    var b = imageData.data[2]
//                    var a = imageData.data[3]

//                    var h = imageData.height
//                    var w = imageData.width

//                    console.log(mouseX + ' - ' + mouseY)

//    //                RecolorScreenController.setTargetColor(r, g, b, a)
//                }

//    //            onClicked: {
//    //                var r = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[0]
//    //                var g = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[1]
//    //                var b = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[2]
//    //                var a = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[3]

//    //                RecolorScreenController.setTargetColor(r, g, b, a)
//    //            }
//            }

//            onCanvasSizeChanged: {
//                canvas.requestPaint()
//            }

//            onImageLoaded: {
//                var ctx = canvas.getContext("2d");
//                ctx.drawImage(imagePathProp,canvas.x,canvas.y,canvas.width,canvas.height);
////                ctx.drawImage(imagePathProp,canvas.x,canvas.y);
//                canvas.requestPaint();
//            }
//        }
//    }
//}

Rectangle {
    color: 'transparent'

    border.width: 1
    border.color: "grey"

    Image {
        id: image

        anchors.fill: parent

        source: RecolorScreenModel.imagePath
    }

    Canvas {
        id: canvas

        anchors.fill: parent

        visible: true

        property string imagePathProp: RecolorScreenModel.imagePath
        property bool emptyImagePathProp: RecolorScreenModel.emptyImagePath

        onImagePathPropChanged: {
            if (imagePathProp !== emptyImagePathProp) {
                canvas.loadImage(imagePathProp)
            }
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                var imageData = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1);

                var r = imageData.data[0]
                var g = imageData.data[1]
                var b = imageData.data[2]
                var a = imageData.data[3]

                var heightScale = image.sourceSize.height / canvas.height
                var widthScale = image.sourceSize.width / canvas.width

                var imageXPos = mouseX * widthScale
                var imageYPos = mouseY * heightScale

                RecolorScreenController.setTargetColorPoint(r, g, b, a, imageXPos, imageYPos)
            }
        }

        onCanvasSizeChanged: {
            canvas.requestPaint();
        }

        onImageLoaded: {
            var ctx = canvas.getContext("2d");
            ctx.drawImage(imagePathProp,canvas.x,canvas.y,canvas.width,canvas.height);
            canvas.requestPaint();
        }
    }
}
