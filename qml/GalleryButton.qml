import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    width: parent.width
    height: parent.height / 2

    property alias imgSrc: image.source
    property alias text: label.text
    property alias mouseArea: mouseArea

    Image {
        id: image
        source: "../static/pokemon.jpg"
        fillMode: Image.PreserveAspectCrop
        anchors.fill: parent
    }

    Rectangle {
        id: text
        anchors.fill: parent

        color: "black"
        opacity: 0.7

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                parent.opacity = 0.3
//                label.color = "black"
                label.scale = 1.2
            }
            onExited: {
                parent.opacity = 0.7
                label.color = "#F3F3F3"
                label.scale = 1.0
            }
        }

        Behavior on opacity {
            NumberAnimation {
                duration: 200
            }
        }
    }

    Text {
        id: label
        text: "用户大厅"
        color: "#F3F3F3"

        anchors.centerIn: parent

        font.pointSize: 40

        Behavior on scale {
            NumberAnimation {
                duration: 200
            }
        }
    }
}
