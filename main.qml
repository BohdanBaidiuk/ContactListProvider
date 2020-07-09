import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Window {
    id:firstWidow
    visible: true
    width: 640
    height: 480
    title: qsTr(" ContactListProvider")

    PageList{
        anchors.fill: parent
    }


}
