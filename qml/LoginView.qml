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

        property string value: ""
        onTextChanged: value = text
    }

    TextField {
        id: passwordInput
        placeholderText: "密码"

        echoMode: TextInput.Password

        anchors.top: userNameInput.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: banner.horizontalCenter

        width: 300

        property string value: ""
        onTextChanged: value = text
    }

    GameButton {
        id: submitBtn

        anchors.top: passwordInput.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: banner.horizontalCenter

        text: banner.isLogin ? "登录" : "注册"

        mouseArea.onClicked: {
            if (banner.isLogin) {
                const msg = client_model.auth(userNameInput.value, passwordInput.value)
                if (msg) {
                    submitBtn.text = "密码错误"
                } else {
                    client_model.pushPage("MainView.qml")
                }
            } else {
                const msg = client_model.signup(userNameInput.value, passwordInput.value)
                if (msg) {
                    submitBtn.text = msg
                } else {
                    submitBtn.text = "注册成功"
                    banner.isLogin = true
                }
            }
        }
    }
}
