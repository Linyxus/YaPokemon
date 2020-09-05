import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent

    Text {
        id: resultLabel
        anchors.centerIn: parent

        text: client_model.resultText
        font.pointSize: 30
        horizontalAlignment: Text.AlignHCenter
    }

    GameButton {
        id: backBtn
        anchors.top: resultLabel.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        text: "返回大厅"
        mouseArea.onClicked: {
            client_model.updateUsers()
            client_model.popPage()
            client_model.popPage()
        }
    }
}
