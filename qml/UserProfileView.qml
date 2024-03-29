import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent
    property alias backBtnMouseArea: backBtn.mouseArea

    Rectangle {
        id: usernameRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 100

        Text {
            id: usernameLabel
            anchors.centerIn: parent

            text: client_model.users[client_model.viewUser].username
            font.pointSize: 50
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

    function level2desc(l) {
        if (l === 0) {
            return "无"
        }
        if (l === 1) {
            return "青铜色"
        }
        if (l === 2) {
            return "银色"
        }
        if (l === 3) {
            return "金色"
        }
    }

    Rectangle {
        id: numBadgeRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: usernameRect.bottom
        height: 60

        Text {
            anchors.centerIn: parent
            text: level2desc(client_model.userNumBadge) + "宠物个数勋章   "
                + level2desc(client_model.userHLBadge) + "高级宠物勋章 "

            font.pointSize: 20
        }
    }

    Rectangle {
        id: pokemonListRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: numBadgeRect.bottom
        anchors.bottom: parent.bottom
        clip: true

        PokemonList {
            id: pokemonList
            anchors.fill: parent
        }
    }

    Component.onCompleted: {
        client_model.updateUsers()
        console.log(client_model.userNumBadge)
        console.log(client_model.userHLBadge)
    }
}
