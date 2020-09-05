import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    anchors.fill: parent
    property alias usersBtnMouseArea: usersBtn.mouseArea
    property alias battleBtnMouseArea: battleBtn.mouseArea

    GalleryButton {
        id: usersBtn

        anchors.top: parent.top
        anchors.left: parent.left

        mouseArea.onClicked: {
            client_model.pushPage("UsersView.qml")
        }
    }

    GalleryButton {
        id: battleBtn

        anchors.top: usersBtn.bottom
        anchors.left: parent.left

        text: "挑战"
        imgSrc: "../static/pokemon_2.jpg"

        mouseArea.onClicked: client_model.pushPage("BossView.qml")
    }
}
