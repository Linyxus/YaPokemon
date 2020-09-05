import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    property int maxHp: 30
    property int nowHp: 20
    property bool isLeft: true

    Behavior on nowHp {
        NumberAnimation {
            duration: 200
        }
    }

    Rectangle {
        id: infoRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height / 3 * 2

        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 10

            text: "皮卡丘"
            font.pointSize: 24
        }

        Text {
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.bottom: parent.bottom

            text: "12 级"
            font.pointSize: 15
        }

        Text {
            id: maxHpLabel
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10

            text: "/ " + root.maxHp
            font.pointSize: 16
        }

        Text {
            anchors.right: maxHpLabel.left
            anchors.bottom: parent.bottom
            anchors.rightMargin: 5

            text: '' + root.nowHp
            font.pointSize: 25
        }
    }

    Rectangle {
        id: hpRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: infoRect.bottom
        anchors.bottom: parent.bottom

        ProgressBar {
            id: hpBar
            anchors.centerIn: parent
            width: parent.width - 10
            value: root.nowHp * 1.0 / root.maxHp

            Behavior on value {
                NumberAnimation {
                    duration: 200
                }
            }
        }
    }
}
