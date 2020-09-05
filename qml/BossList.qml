import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: root

    anchors.fill: parent
    spacing: 5
    model: ListModel {
        ListElement {}
        ListElement {}
        ListElement {}
    }

    delegate: Rectangle {
        width: parent.width * 0.8
        height: 80
        border.width: 2
        radius: height / 2
        anchors.horizontalCenter: parent.horizontalCenter
        property string bossName: "皮卡丘"

        Menu {
            id: pokemonSelect
            width: parent.width - 20
            y: parent.height
            x: 10
            MenuItem {
                text: "皮卡丘 10级"
                onClicked: {
                    client_model.pushPage("BattleView.qml")
                }
            }
            MenuItem {
                text: "伊布 12级"
            }
        }

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

            PokemonImage {
                id: avatar
                anchors.left: parent.left
                anchors.top: parent.top
                height: parent.height
                width: parent.height

                name: pokemonName
            }

            Rectangle {
                id: nameRect
                anchors.left: avatar.right
                anchors.leftMargin: 30
                anchors.top: parent.top
                height: parent.height
                width: parent.width / 4

                Rectangle {
                    id: pokemonNameLabel
                    height: parent.height
                    width: parent.width
                    anchors.left: parent.left
                    anchors.top: parent.top

                    Text {
                        text: bossName
                        anchors.centerIn: parent
                        font.pointSize: 20
                    }
                }
            }

            Button {
                id: realBtn
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: "挑战"
                font.pointSize: 18
                flat: true

                onClicked: {
                    pokemonSelect.open()
                }
            }

            Button {
                id: exeBtn
                anchors.right: realBtn.left
                anchors.verticalCenter: parent.verticalCenter
                text: "练习"
                font.pointSize: 18
                flat: true

                onClicked: {
                    pokemonSelect.open()
                }
            }
        }
    }
}
