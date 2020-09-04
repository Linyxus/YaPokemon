import QtQuick 2.12
import QtQuick.Controls 2.12


Rectangle {
    id: root
    border.color: "black"
    border.width: 2
    width: 180
    height: 50
    radius: this.height / 2

    property alias text: buttonText.text
    property alias mouseArea: mouseArea

    Text {
        id: buttonText
        text: "开始游戏"
        font.pointSize: 20

        anchors.centerIn: parent
    }

    Behavior on scale {
        NumberAnimation { duration: 100; easing.type: Easing.InOutQuad }
    }

    Behavior on color {
        ColorAnimation {
            duration: 280
        }
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
        onPressed: {
            parent.color = "royalblue"

        }
        onReleased: {
            parent.color = "white"
        }
    }
}

