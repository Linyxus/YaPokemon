import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.15

ListView {
    id: root

    anchors.fill: parent
    spacing: 5
    model: client_model.pokemonMoves

    delegate: Rectangle {
        width: parent.width * 0.8
        height: 80
        border.width: 2
        radius: height / 2
        anchors.horizontalCenter: parent.horizontalCenter
        property string moveName: modelData.name
        property string moveCat: modelData.cat
        property string moveDesc: modelData.desc

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

        Rectangle {
            id: innerRoot
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.margins: 15
            color: parent.color

            Rectangle {
                id: nameRect
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.top: parent.top
                height: parent.height
                width: parent.width / 4

                Text {
                    text: parent.parent.parent.moveName
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }

            Rectangle {
                id: catRect
                anchors.left: nameRect.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width / 6

                Text {
                    text: parent.parent.parent.moveCat + "类招式"
                    anchors.centerIn: parent
                }
            }

            Rectangle {
                id: descRect
                anchors.left: catRect.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: parent.right

                Text {
                    text: parent.parent.parent.moveDesc
                    anchors.centerIn: parent
                    width: parent.width
                    wrapMode: Text.Wrap
                }
            }
        }
    }
}
