import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import CLP 1.0


Page{
    background: Rectangle{
        color: "white"
    }
    header: Rectangle{
        height:40
        anchors.left: parent.left
        anchors.right: parent.right
        color: "#004040"
        radius:10
        border.color: "black"
        CheckBox{
            id: control
            text: qsTr(control.checked?"Show all contacts":"Show only Favorites")
            x:15
                checked: false
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: control.leftPadding
                    y: parent.height / 2 - height / 2
                    radius: 5
                    Image{
                        id:imageStar
                        width: 26
                        height: 26
                        anchors.centerIn: parent
                        source: control.checked ?  "Image/GoldStar.png" : "Image/BlackStar.png"

                    }
                }

                contentItem: Text {
                    text: control.text
                    font: control.font
                    opacity: enabled ? 1.0 : 0.3
                    color: control.down ? "gold" : "white"
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: control.indicator.width + control.spacing
                }
                onClicked: clpList.clickedCheckBox(control.checked )

            }
        Text{
            anchors.centerIn: parent
            text: "Local filter:"
            color:"white"
        }
        TextField{
            anchors.right: parent.right
            onTextChanged: clpList.contactFiltr(text)
        }
    }

    ListView{
        id:listView
        anchors.fill: parent
        clip: true

        ScrollBar.vertical: ScrollBar{}
        model:CLPModel{
            list:clpList
        }

        delegate:DelegateList{}
    }

}
