import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent
    color: "white"
    required property StackView stack

    property alias startBtnMouseArea: startBtn.mouseArea

    Image {
        id: testImage
        source: "../static/pokemon_3.jpg"
        fillMode: Image.PreserveAspectCrop
        anchors.fill: parent
    }

    GameButton {
        id: startBtn
        stack: parent.stack
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 30
    }
}
