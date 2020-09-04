import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: root

    anchors.fill: parent
    spacing: 5
    model: client_model.userPokemons
    delegate: PokemonItem {
        pokemonName: modelData.name
        level: modelData.level
        hp: modelData.hp
        attack: modelData.attack
        spAttack: modelData.spAttack
        defense: modelData.defense
        spDefense: modelData.spDefense
        speed: modelData.speed

        mouseArea.onClicked: {
            console.log(modelData.name)
        }
    }
}
