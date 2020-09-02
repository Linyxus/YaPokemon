import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    anchors.fill: parent

    required property StackView stack

    property alias backBtnMouseArea: backBtn.mouseArea

    GameButton {
        id: backBtn
        anchors.centerIn: parent
        text: "返回"

        stack: root.stack
    }
}
