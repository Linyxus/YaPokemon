import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    width: parent.width * 0.8
    height: 70
    anchors.horizontalCenter: parent.horizontalCenter
    border.width: 2
    border.color: "black"
    radius: height / 2
    property string username: "linyxus"
    property int count: 4

    property alias mouseArea: mouseArea

    Text {
        id: nameLabel
        text: parent.username

        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 30
    }

    Text {
        id: countLabel
        text: "拥有 " + parent.count + " 只精灵"

        anchors.right: parent.right
        anchors.rightMargin: 18
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 15
        color: "black"
    }

    Behavior on scale {
        NumberAnimation { duration: 100; easing.type: Easing.InOutQuad }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.scale = 1.02
        }
        onExited: {
            parent.scale = 1
        }
    }
}
