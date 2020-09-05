import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent
    property int currentStep: 0
    property int leftMaxHp: client_model.battleResult.initialLeft.hp
    property int leftNowHp: client_model.battleResult.initialLeft.hp
    property string leftName: client_model.battleResult.initialLeft.name
    property int leftLevel: client_model.battleResult.initialLeft.level
    property int rightMaxHp: client_model.battleResult.initialRight.hp
    property int rightNowHp: client_model.battleResult.initialRight.hp
    property string rightName: client_model.battleResult.initialRight.name
    property int rightLevel:client_model.battleResult.initialRight.level
    property string bannerText: "战斗开始"

    Timer {
        id: timer
        interval: 1500
        running: true
        repeat: true
        onTriggered: {
            var result = client_model.battleResult
            if (currentStep === result.steps.length) {
                root.bannerText = "战斗结束"
                client_model.pushPage("ResultView.qml")
                timer.stop()
            } else {
                var step = result.steps[currentStep]
                var str = ''
                if (step.turn === 'left') {
                    str += '左边的' + step.currentLeft.name
                } else {
                    str += '右边的' + step.currentRight.name
                }
                if (step.miss) {
                    str += '使出的招式被躲避了'
                } else {
                    str += '使出了' + step.move

                    if (step.turn === 'left') {
                        leftAttackAnimation.start()
                    } else {
                        rightAttackAnimation.start()
                    }
                }
                bannerText = str
            }

            leftNowHp = step.currentLeft.hp
            rightNowHp = step.currentRight.hp
            currentStep = currentStep + 1
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
            text: root.currentStep == 0 ? '' : "第 " + root.currentStep + " 回合"
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

            name: root.leftName
            level: root.leftLevel
            nowHp: root.leftNowHp
            maxHp: root.leftMaxHp
        }

        PokemonIndicator {
            id: rightIndicator

            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width / 3

            name: root.rightName
            level: root.rightLevel
            nowHp: root.rightNowHp
            maxHp: root.rightMaxHp
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
            name: root.leftName
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
            name: root.rightName
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
        anchors.margins: 30
        border.width: 2
        radius: 20
        height: 250

        Text {
            anchors.centerIn: parent
            text: root.bannerText
            font.pointSize: 30
        }
    }
}
