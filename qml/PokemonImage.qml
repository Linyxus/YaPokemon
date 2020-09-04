import QtQuick 2.12

Item {
    id: root
    property string name: "伊布"

    Image {
        id: image
        source: "../static/" + name + ".png"
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
    }
}
