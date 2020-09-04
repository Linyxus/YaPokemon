import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent

    Rectangle {
        id: controlRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 100

        GameButton {
            id: myProfile
            text: "我的信息"
            anchors.centerIn: parent

            mouseArea.onClicked: {
                var i = client_model.getAuthedUser()
                client_model.setViewUser(i)
                client_model.pushPage("UserProfileView.qml")
            }
        }

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
    }

    Rectangle {
        id: usersListRect
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: controlRect.bottom
        anchors.bottom: parent.bottom
        clip: true

        UsersList {
            id: usersList
            anchors.fill: parent
            width: parent.width
        }
    }
}
