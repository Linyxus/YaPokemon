//
// Created by Yichen Xu on 2020/9/1.
//

#include <pokemon/PokemonInstance.h>
#include <pokemon/pokemons/type_map.h>

template<typename T>
shared_ptr<PokemonInstanceOf<T>> get_instance_of(shared_ptr<PokemonOf<T>> pokemon) {
    auto ret = make_shared<PokemonInstanceOf<T>>(*pokemon);
    return ret;
}

shared_ptr<PokemonInstance> instance_of(const shared_ptr<Pokemon>& pokemon) {
    PokemonId pid = pokemon->temp()->id();
    // TODO pid-based if-statements
    if (pid == PokemonEevee) {
        auto p = static_pointer_cast<PokemonOf<pokemon_of<PokemonEevee>::type>>(pokemon);
        auto ret = get_instance_of(p);
        return ret;
    }
    if (pid == PokemonPikachu) {
        auto p = static_pointer_cast<PokemonOf<pokemon_of<PokemonPikachu>::type>>(pokemon);
        auto ret = get_instance_of(p);
        return ret;
    }
    if (pid == PokemonZacian) {
        auto p = static_pointer_cast<PokemonOf<pokemon_of<PokemonZacian>::type>>(pokemon);
        auto ret = get_instance_of(p);
        return ret;
    }
    if (pid == PokemonDragapult) {
        auto p = static_pointer_cast<PokemonOf<pokemon_of<PokemonDragapult>::type>>(pokemon);
        auto ret = get_instance_of(p);
        return ret;
    }
    if (pid == PokemonZamazenta) {
        auto p = static_pointer_cast<PokemonOf<pokemon_of<PokemonZamazenta>::type>>(pokemon);
        auto ret = get_instance_of(p);
        return ret;
    }
    return nullptr;
}
