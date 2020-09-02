import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    anchors.fill: parent

    property alias submitBtnMouseArea: submitBtn.mouseArea

    LoginBanner {
        id: banner

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 150
    }

    TextField {
        id: userNameInput
        placeholderText: "账号"

        anchors.top: banner.bottom
        anchors.topMargin: 60
        anchors.horizontalCenter: banner.horizontalCenter

        width: 300
    }

    TextField {
        id: passwordInput
        placeholderText: "密码"

        echoMode: TextInput.Password

        anchors.top: userNameInput.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: banner.horizontalCenter

        width: 300
    }

    GameButton {
        id: submitBtn

        anchors.top: passwordInput.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: banner.horizontalCenter

        text: banner.isLogin ? "登录" : "注册"
    }
}
