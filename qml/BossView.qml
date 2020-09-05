import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent

    Rectangle {
        id: headerRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 100

        GameButton {
            id: backBtn
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 80
            width: 100
            text: "< 返回"

            mouseArea.onClicked: {
                client_model.popPage()
            }
        }

        Text {
            anchors.centerIn: parent
            text: "挑战"
            font.pointSize: 50
        }
    }

    Rectangle {
        id: listRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: headerRect.bottom
        anchors.bottom: parent.bottom

        BossList {
            anchors.fill: parent
        }
    }
}
