import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import CLP 1.0


Rectangle{
height: 60
anchors.left: parent.left
anchors.right: parent.right
color: "#008080"
radius:10
border.color: "white"

    Image {
        id:img
        width: 59
        height: 59
        x:10
        anchors.verticalCenter: parent.verticalCenter
        source: model.image
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                dialogeWindow.show()
                firstWidow.hide()
            }
        }
    }
    Rectangle {
        id: mask
        width: 50
        height: 50
        x:10
        anchors.verticalCenter: parent.verticalCenter
        radius: 250
        visible: false

    }

    Text{

        anchors.centerIn: parent
        text:model.description
        font.pixelSize: 24
    }
    CheckBox {
        id:controlBoxList
        checked: model.done
        anchors.right:parent.right
        anchors.verticalCenter: parent.verticalCenter
        indicator: Rectangle {
            implicitWidth: 26
            implicitHeight: 26
            x: controlBoxList.leftPadding
            y: parent1.height / 2 - height / 2
            color: "transparent"
            Image{
                id:imageStar
                width: 26
                height: 26
                anchors.centerIn: parent
                source: controlBoxList.checked ?  "Image/GoldStar.png" : "Image/BlackStar.png"
            }
        }
        onClicked: clpList.clickedListWiewCheckBox(controlBoxList.checked,index)
    }

    DialogeWindow{

            id: dialogeWindow
            title: qsTr("Contact info")
            onSignalExit: {
                dialogeWindow.close()
                firstWidow.show()
            }
    }

}

