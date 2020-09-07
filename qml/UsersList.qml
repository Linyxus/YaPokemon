import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: root

    anchors.fill: parent
    model: client_model.users
    spacing: 5
    delegate: UserItem {
        username: modelData.username
        count: modelData.pokemonCount
        online: modelData.online
        winCount: modelData.winCount
        loseCount: modelData.loseCount

        mouseArea.onClicked: {
            client_model.setViewUser(index)
            console.log(modelData)
            client_model.pushPage("UserProfileView.qml")
        }
    }
}
