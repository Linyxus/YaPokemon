import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            console.log("tick!")
            leftIndicator.nowHp += 5
            rightIndicator.nowHp -= 5
            leftAttackAnimation.start()
            rightAttackAnimation.start()
        }
    }

    Rectangle {
        id: headerRect
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: root.top
        height: 100

        Text {
            id: roundLabel
            text: "第 1 回合"
            anchors.centerIn: parent

            font.pointSize: 30
        }

        PokemonIndicator {
            id: leftIndicator

            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width / 3
            nowHp: 0
        }

        PokemonIndicator {
            id: rightIndicator

            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width / 3
            nowHp: 30
        }
    }

    Rectangle {
        id: pokemonRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: headerRect.bottom
        anchors.bottom: textRect.top

        PokemonImage {
            id: leftPokemon
            name: "伊布"
            x: parent.width / 6
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height * 0.6
            width: height
            transform: Rotation {
                origin.x: leftPokemon.width / 2
                origin.y: 0
                axis { x: 0; y: 1; z: 0 }
                angle: 180
            }
        }

        SequentialAnimation {
            id: leftAttackAnimation
            NumberAnimation {
                target: leftPokemon
                property: "x"
                duration: 200
                easing.type: Easing.InOutQuad
                from: parent.width / 6
                to: parent.width / 6 + 50
            }
            NumberAnimation {
                target: leftPokemon
                property: "x"
                duration: 200
                easing.type: Easing.InOutQuad
                from: parent.width / 6 + 50
                to: parent.width / 6
            }
            running: false
        }

        PokemonImage {
            id: rightPokemon
            name: "皮卡丘"
            x: parent.width - rightPokemon.width - parent.width / 6
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height * 0.6
            width: height
            transform: Rotation {
                origin.x: rightPokemon.width / 2
                origin.y: 0
                axis { x: 0; y: 1; z: 0 }
                angle: 0
            }
        }

        SequentialAnimation {
            id: rightAttackAnimation
            NumberAnimation {
                target: rightPokemon
                property: "x"
                duration: 200
                easing.type: Easing.InOutQuad
                from: parent.width - rightPokemon.width - parent.width / 6
                to: parent.width - rightPokemon.width - parent.width / 6 - 50
            }
            NumberAnimation {
                target: rightPokemon
                property: "x"
                duration: 200
                easing.type: Easing.InOutQuad
                from: parent.width - rightPokemon.width - parent.width / 6 - 50
                to: parent.width - rightPokemon.width - parent.width / 6
            }
            running: false
        }
    }

    Rectangle {
        id: textRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 250

        Text {
            anchors.centerIn: parent
            text: "皮卡丘使出了 打雷"
            font.pointSize: 30
        }
    }
}
