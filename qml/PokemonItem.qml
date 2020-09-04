import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    width: parent.width * 0.8
    height: 80
    border.width: 2
    radius: height / 2
    anchors.horizontalCenter: parent.horizontalCenter
    property string pokemonName: "皮卡丘"
    property int level: 12
    property int hp: 30
    property int attack: 10
    property int spAttack: 12
    property int defense: 20
    property int spDefense: 30
    property int speed: 20

    property alias mouseArea: mouseArea

    Behavior on scale {
        NumberAnimation { duration: 100; easing.type: Easing.InOutQuad }
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
            width: parent.width / 3

            Rectangle {
                id: pokemonNameLabel
                height: parent.height / 2
                width: parent.width
                anchors.left: parent.left
                anchors.top: parent.top

                Text {
                    text: pokemonName
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }

            Rectangle {
                height: parent.height / 2
                anchors.left: parent.left
                anchors.top: pokemonNameLabel.bottom
                width: parent.width

                Text {
                    text: level + " 级"
                    anchors.centerIn: parent
                }
            }
        }

        Rectangle {
            id: hexRect
            anchors.left: nameRect.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            Grid {
                anchors.fill: parent
                columns: 3
                rows: 2
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "体力 " + hp
                    }
                }
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "攻击 " + attack
                    }
                }
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "特攻 " + spAttack
                    }
                }
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "速度 " + speed
                    }
                }
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "防御 " + defense
                    }
                }
                Rectangle {
                    width: parent.width / 3
                    height: parent.height / 2
                    Text {
                        anchors.centerIn: parent
                        text: "特防 " + spDefense
                    }
                }
            }
        }
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
}
