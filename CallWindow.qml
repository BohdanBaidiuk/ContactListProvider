import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import CLP 1.0

Window{
    id:callWidow
    signal signalExit
    width: 400
    height: 200

    color:"#008080"
    Button {
        text: qsTr("Главное окно")
        width: 20
        height: 20
        x:10
        y:10
        onClicked: {
            dialogeWidow.signalExit()
        }
    }
    Image {
        id:img
        width: 100
        height: 100
        x:10
        anchors.verticalCenter: parent.verticalCenter
        source: model.image
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
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
        font.pixelSize: 30
    }
    Text {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 30
        text:"Phone "+ model.phoneNumber
    }

}
