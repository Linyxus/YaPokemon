//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef POKEMON_CORE_POKEMON_TOOLS_H
#define POKEMON_CORE_POKEMON_TOOLS_H

#include <iostream>
using namespace std;
#include <pokemon/Pokemon.h>
#include <pokemon/PokemonInstance.h>

ostream &operator<<(ostream &os, const shared_ptr<Pokemon>& pokemon);

ostream &operator<<(ostream &os, const shared_ptr<PokemonInstance>& instance);

#endif //POKEMON_CORE_TOOLS_H
