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

    Rectangle {
        id: pokemonListRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: usernameRect.bottom
        anchors.bottom: parent.bottom
        clip: true

        PokemonList {
            id: pokemonList
            anchors.fill: parent
        }
    }

    Component.onCompleted: {
        client_model.updateUsers()
    }
}
