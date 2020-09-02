import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: window
    visible: true
    width: 1080
    height: 680
    title: "Pokemon"

    StackView {
        id: stackView
        initialItem: welcomeView
        anchors.fill: parent

        pushEnter: Transition {
            ParallelAnimation {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }

                PropertyAnimation {
                    property: "scale"
                    from: 1.1
                    to: 1
                    duration: 200
                }
            }
        }

        pushExit: Transition {
            ParallelAnimation {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to:0
                    duration: 200
                }

                PropertyAnimation {
                    property: "scale"
                    from: 1
                    to: 1.1
                    duration: 200
                }
            }
        }

        popEnter: Transition {
            ParallelAnimation {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }

                PropertyAnimation {
                    property: "scale"
                    from: 1.1
                    to: 1
                    duration: 200
                }
            }
        }

        popExit: Transition {
            ParallelAnimation {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to:0
                    duration: 200
                }

                PropertyAnimation {
                    property: "scale"
                    from: 1
                    to: 1.1
                    duration: 200
                }
            }
        }
    }

    WelcomeView {
        id: welcomeView
        stack: stackView
        visible: false

        startBtnMouseArea.onClicked: {
            stackView.push(loginView)
        }
    }

    GameView {
        id: gameView
        stack: stackView
        visible: false

        backBtnMouseArea.onClicked: {
            stackView.pop()
        }
    }

    LoginView {
        id: loginView
        visible: false

        submitBtnMouseArea.onClicked: {
            stackView.push(mainView)
        }
    }

    MainView {
        id: mainView
        visible: false
    }
}
