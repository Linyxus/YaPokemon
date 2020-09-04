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
//        initialItem: profileView
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

    Connections {
        target: client_model

        function onPagePushed(page) {
            stackView.push(page)

        }

        function onPagePoped() {
            stackView.pop()
        }
    }

    WelcomeView {
        id: welcomeView
        visible: false
    }
}
