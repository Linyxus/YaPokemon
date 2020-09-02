import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    anchors.fill: parent

    GalleryButton {
        id: usersBtn

        anchors.top: parent.top
        anchors.left: parent.left
    }

    GalleryButton {
        id: battleBtn

        anchors.top: usersBtn.bottom
        anchors.left: parent.left

        text: "挑战"
        imgSrc: "../static/pokemon_2.jpg"
    }
}
