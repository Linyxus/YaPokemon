import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    width: 200
    height: 40

    property bool isLogin: true

    Rectangle {
        id: loginLabel
        width: parent.width / 2
        height: parent.height - 10

        anchors.left: parent.left
        anchors.top: parent.top

        Text {
            text: "登录"
            anchors.centerIn: parent
            font.pointSize: 15

            color: isLogin ? "#507DBC" : "black"

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }
        }
    }

    Rectangle {
        id: registerLabel
        width: parent.width / 2
        height: parent.height - 10

        anchors.left: loginLabel.right
        anchors.top: parent.top

        Text {
            text: "注册"
            anchors.centerIn: parent
            font.pointSize: 15

            color: !isLogin ? "#507DBC" : "black"

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }
        }
    }

    Rectangle {
        width: 5
        height: width
        radius: width / 2
        color: "#507DBC"

        anchors.top: loginLabel.bottom
        x: (parent.isLogin
            ? parent.width / 4
            : parent.width / 4 * 3) - radius

        Behavior on x {
            NumberAnimation {
                duration: 100
                easing.type: Easing.InOutQuad
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.isLogin = !parent.isLogin
        }
    }
}
